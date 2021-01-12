/*
** EPITECH PROJECT, 2020
** src
** File description:
** AI
*/

#include "../../include/Entities/AI.hpp"
#include "../../include/EventReceiver.hpp"

AI::AI(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, irr::scene::IMetaTriangleSelector* listTriSelectors)
{
    if (!smgr || !driver || !listTriSelectors)
        throw std::logic_error("Player constructor error: invalid scene/driver/collision list");
    _mesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/chaffee_tank.obj"), 0,  ID_rayPickable::IsPickable);
    _mesh->setPosition(irr::core::vector3df(1 * 20 -150 +9, 300, 1 * 20 -150 +9));
    _smgr = smgr;
    _driver = driver;
    _listTriSelectors = listTriSelectors;

    irr::video::SMaterial material = irr::video::SMaterial();
    _mesh->setMaterialTexture(0, driver->getTexture("../asset/grey.jpg"));
    _mesh->setTriangleSelector(_smgr->createTriangleSelector(_mesh->getMesh(), _mesh));

    if (listTriSelectors)
    {
        irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
            listTriSelectors, _mesh, irr::core::vector3df(10.0f, 10.0f, 10.0f),
            irr::core::vector3df(0, -10, 0)
        );
        _mesh->addAnimator(anim);
        anim->drop();
    }
    for (unsigned int x = 0; x < 15; x++) {
        for (unsigned int y = 0; y < 15; y++) {
            _type_map[x][y] = ENTITY;
        }
    }
    _direction = NONE;
    _rateOfFire.start();
    _incrementSave.start();
    _reloadTimer.start();
    std::srand(std::time(nullptr));
}

bool AI::fillMap(std::vector<std::shared_ptr<IEntity>> entities)
{
    int posX = 0;
    int posZ = 0;
    int x = 0;
    int z = 0;
    for (unsigned int z = 0; z < 15; z++) {
        for (unsigned int x = 0; x < 15; x++) {
            if (_type_map[z][x] != ENTITY)
                _type_map[z][x] = ENTITY;
        }
    }
    for (auto entity : entities) {
        if (entity) {
            posX = entity->getPosition().Z - 9 + 150;
            posZ = entity->getPosition().X - 9 + 150;
            x = posX / 20;
            if (posX % 20 > 10)
                x += 1;
            z = posZ / 20;
            if (posZ % 20 > 10)
                z += 1;
            if (entity->getType() == OBSTACLE)
                _type_map[z][x] = OBSTACLE;
            else if (entity->getType() == BOMB)
                _type_map[z][x] = BOMB;
        }
    }
    if (_justBombed == true) {
        _type_map[_map_pos.first][_map_pos.second] = BOMB;
        _justBombed = false;
    }
    if (_mesh) {
        posX = _mesh->getPosition().Z - 9 + 150;
        posZ = _mesh->getPosition().X - 9 + 150;
    }
    _map_pos.first = posZ / 20;
    if (posZ % 20 > 10)
        _map_pos.first += 1;
    _map_pos.second = posX / 20;
    if (posX % 20 > 10)
        _map_pos.second += 1;
    if (_mesh) {
        _coordinates.first = _mesh->getPosition().X;
        _coordinates.second = _mesh->getPosition().Z;
    }
    return true;
}

std::vector<Direction> AI::scanForDanger(int up_down, int left_right)
{
    std::vector<Direction> dangers;

    for (int z = up_down; z != 0; z--) {
        if (_type_map[z][left_right] == OBSTACLE) {
            break;
        } else if (_type_map[z][left_right] == BOMB) {
            dangers.push_back(UP);
        }
    }
    for (int z = up_down; z != 15; z++) {
        if (_type_map[z][left_right] == OBSTACLE) {
            break;
        } else if (_type_map[z][left_right] == BOMB) {
            dangers.push_back(DOWN);
        }
    }
    for (int x = left_right; x != 0; x--) {
        if (_type_map[up_down][x] == OBSTACLE) {
            break;
        } else if (_type_map[up_down][x] == BOMB) {
            dangers.push_back(LEFT);
        }
    }
    for (int x = left_right; x != 15; x++) {
        if (_type_map[up_down][x] == OBSTACLE) {
            break;
        } else if (_type_map[up_down][x] == BOMB) {
            dangers.push_back(RIGHT);
        }
    }
    if (_type_map[up_down][left_right] == BOMB) {
        dangers.push_back(BELOW);
    }
    if (dangers.size() == 0) {
        dangers.push_back(NONE);
    }
    return dangers;
}

std::vector<Direction> AI::scanForAvailablePath(void)
{
    std::vector<Direction> ways;
    if (_type_map[_map_pos.first+1][_map_pos.second] == ENTITY || _type_map[_map_pos.first+1][_map_pos.second] == PLAYER) {
        ways.push_back(DOWN);
    }
    if (_type_map[_map_pos.first-1][_map_pos.second] == ENTITY || _type_map[_map_pos.first-1][_map_pos.second] == PLAYER) {
        ways.push_back(UP);
    }
    if (_type_map[_map_pos.first][_map_pos.second+1] == ENTITY || _type_map[_map_pos.first][_map_pos.second+1] == PLAYER) {
        ways.push_back(RIGHT);
    }
    if (_type_map[_map_pos.first][_map_pos.second-1] == ENTITY || _type_map[_map_pos.first][_map_pos.second-1] == PLAYER) {
        ways.push_back(LEFT);
    }
    if (ways.size() == 0) {
        ways.push_back(NONE);
    }
    return ways;
}

std::vector<Direction> AI::scanForObstacles(void)
{
    std::vector<Direction> ways;

    if (_map_pos.first + 1 != 14 && ((_map_pos.first + 1) % 2 != 0 || _map_pos.second % 2 != 0) &&
        _type_map[_map_pos.first+1][_map_pos.second] == OBSTACLE) {
        ways.push_back(DOWN);
    }
    if (_map_pos.first - 1 != 0 && ((_map_pos.first - 1) % 2 != 0 || _map_pos.second % 2 != 0) &&
        _type_map[_map_pos.first-1][_map_pos.second] == OBSTACLE) {
        ways.push_back(UP);
    }
    if (_map_pos.second + 1 != 14 && (_map_pos.first % 2 != 0 || (_map_pos.second + 1) % 2 != 0) &&
        _type_map[_map_pos.first][_map_pos.second+1] == OBSTACLE) {
        ways.push_back(RIGHT);
    }
    if (_map_pos.second - 1 != 0 && (_map_pos.first % 2 != 0 || (_map_pos.second - 1) % 2 != 0) &&
        _type_map[_map_pos.first][_map_pos.second-1] == OBSTACLE) {
        ways.push_back(LEFT);
    }
    if (ways.size() == 0) {
        ways.push_back(NONE);
    }
    return ways;
}

bool AI::moveAI(Direction direction, float elapsedTime)
{
    if (direction == UP) {
        _direction = direction;
        _mesh->setRotation(irr::core::vector3df(0.0f, -90.0f, 0.0f));
        return true;
    }
    if (direction == RIGHT) {
        _direction = direction;
        _mesh->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
        return true;
    }
    if (direction == DOWN) {
        _direction = direction;
        _mesh->setRotation(irr::core::vector3df(0.0f, 90.0f, 0.0f));
        return true;
    }
    if (direction == LEFT) {
        _direction = direction;
        _mesh->setRotation(irr::core::vector3df(0.0f, 180.0f, 0.0f));
        return true;
    }
    return (false);
}
bool AI::dodge_danger(std::vector<Direction> dangers, std::vector<Direction> paths)
{
    bool result = false;

    for (auto danger : dangers) {
        for (int x = 0; x != paths.size(); x++) {
            if (paths.at(x) == danger) {
                paths.erase(paths.begin()+x);
                break;
            }
        }
    }
    for (int x = 0; x != paths.size(); x++) {
        if (paths.at(x) == UP) {
            if (scanForDanger(_map_pos.first-1, _map_pos.second).at(0) != NONE) {
                paths.erase(paths.begin()+x);
                x = x -1;
            }
        } else if (paths.at(x) == LEFT) {
            if (scanForDanger(_map_pos.first, _map_pos.second-1).at(0) != NONE) {
                paths.erase(paths.begin()+x);
                x = x -1;
            }
        } else if (paths.at(x) == DOWN) {
            if (scanForDanger(_map_pos.first+1, _map_pos.second).at(0) != NONE) {
                paths.erase(paths.begin()+x);
                x = x -1;
            }
        } else if (paths.at(x) == RIGHT) {
            if (scanForDanger(_map_pos.first, _map_pos.second+1).at(0) != NONE) {
                paths.erase(paths.begin()+x);
                x = x -1;
            }
        }
    }
    if (paths.size() == 0) {
        return (false);
    }
    int random_variable = 0;
    if (paths.size() > 1)
        random_variable = std::rand() % paths.size();
    result = moveAI(paths.at(random_variable), 0);
    return (result);
}

int AI::getDangerDistance(Direction direction)
{
    int distance = 0;

    if (direction == UP) {
        for (distance = 0; _type_map[_map_pos.first - distance][_map_pos.second] != BOMB; distance++);
        return (distance);
    } else if (direction == DOWN) {
        for (distance = 0; _type_map[_map_pos.first + distance][_map_pos.second] != BOMB; distance++);
        return (distance);
    } else if (direction == LEFT) {
        for (distance = 0; _type_map[_map_pos.first][_map_pos.second - distance] != BOMB; distance++);
        return (distance);
    } else if (direction == RIGHT) {
        for (distance = 0; _type_map[_map_pos.first][_map_pos.second + distance] != BOMB; distance++);
        return (distance);
    }
    return distance;
}

bool AI::avoid_closest_danger(std::vector<Direction> dangers, std::vector<Direction> paths)
{
    int distance = -1;
    int tmp = 0;
    std::vector<Direction> shortest;
    Direction res = NONE;
    bool result = false;

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(dangers.begin(), dangers.end(), g);
    for (auto danger : dangers) {
        tmp = getDangerDistance(danger);
        if (tmp < distance || distance == -1) {
            distance = tmp;
            res = danger;
        }
    }
    if (dangers.size() != 5) {
        for (auto danger : dangers) {
            tmp = getDangerDistance(danger);
            if (tmp == distance) {
                shortest.push_back(danger);
            }
        }
        for (auto danger : shortest) {
            for (int x = 0; x != paths.size(); x++) {
                if (paths.at(x) == danger) {
                    paths.erase(paths.begin()+x);
                    break;
                }
            }
        }
        if (paths.size() == 0) {
            _direction = NONE;
            return (true);
        }
    }
    if (res == UP) {
        res = DOWN;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = RIGHT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = LEFT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = UP;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
    } else if (res == DOWN) {
        res = UP;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = RIGHT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = LEFT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (res);
        res = DOWN;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
    } else if (res == LEFT) {
        res = RIGHT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = UP;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = DOWN;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = LEFT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
    } else if (res == RIGHT) {
        res = LEFT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = UP;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = DOWN;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
        res = RIGHT;
        if (std::find(paths.begin(), paths.end(), res) != paths.end())
            return (moveAI(res, 0));
    }
    result = moveAI(res, 0);
    return (result);
}

void correct_error(irr::scene::IMeshSceneNode* mesh, std::pair<float, float> coords)
{
    int x = coords.first - 9.0f + 150.0f;
    int z = coords.second - 9.0f + 150.0f;
    x = x % 20;
    z = z % 20;
    if (x <= 10)
        coords.first -= x;
    if (x > 10)
        coords.first += 20-x;
    if (z <= 10)
        coords.second -= z;
    if (z > 10)
        coords.second += 20-z;
    mesh->setPosition(irr::core::vector3df(coords.first, 0, coords.second));
}

bool AI::calculateNextMove(std::vector<std::shared_ptr<IEntity>> entities)
{
    std::vector<Direction> danger;
    std::vector<Direction> ways;
    std::vector<Direction> obstacles;

    int x = _coordinates.first - 9.0f + 150.0f;
    int z = _coordinates.second - 9.0f + 150.0f;
    x = x % 20;
    z = z % 20;
    fillMap(entities);
    if (x != 0 || z != 0) {
        if ((x == lastx && x != 0) || (z == lastz && z != 0))
            counter++;
        else {
            counter = 0;
            lastx = x;
            lastz = z;
        }
        if (counter == 100) {
            correct_error(_mesh, _coordinates);
            counter = 0;
            _direction = NONE;
        }
        return (false);
    }
    danger = scanForDanger(_map_pos.first, _map_pos.second);
    ways = scanForAvailablePath();

    bool movement_done = false;
    if (danger.size() >= 1 && danger.at(0) != NONE) {
        movement_done = dodge_danger(danger, ways);
        if (movement_done == false) {
            movement_done = avoid_closest_danger(danger, ways);
        }
        if (movement_done == true) {
            _lastSpaceSave = false;
            _spaces_since_danger = 0;
            _incrementSave.restart();
            return (true);
        }
    }
    if (danger.at(0) == NONE && ways.size() <= 4) {
        if (_lastSpaceSave == true) {
            obstacles = scanForObstacles();
            if (_spaces_since_danger >= 4 && obstacles.size() >= 1 && obstacles.at(0) != NONE && _nbLoadedBombs > 0 && _rateOfFire.getElapsedSeconds() > 0.3) {
                _isBombing = true;
                _rateOfFire.restart();
            }
            if (_isBombing == true) {
                _direction = NONE;
                return (true);
            }
            Direction turn_around = NONE;
            if (_lastMovement == UP)
                turn_around = DOWN;
            else if (_lastMovement == DOWN)
                turn_around = UP;
            else if (_lastMovement == LEFT)
                turn_around = RIGHT;
            else if (_lastMovement == RIGHT)
                turn_around = LEFT;
            auto it = std::find(ways.begin(), ways.end(), turn_around);
            if (it != ways.end())
                ways.erase(it);
        }
        movement_done = dodge_danger(danger, ways);
        if (movement_done == true) {
            _lastSpaceSave = true;
            _spaces_since_danger += 1;
            _incrementSave.restart();
            return (true);
        }
    }
    if (_incrementSave.getElapsedSeconds() >= 1) {
        _incrementSave.restart();
        _spaces_since_danger += 1;
    }
    _direction = NONE;
    return true;
}

bool AI::update(float elapsedTime)
{
    if (_direction == UP) {
        _mesh->setPosition(irr::core::vector3df(_coordinates.first - (_speed*elapsedTime) , 0, _coordinates.second));
        _lastMovement = _direction;
        return true;
    }
    if (_direction == RIGHT) {
        _mesh->setPosition(irr::core::vector3df(_coordinates.first, 0, _coordinates.second + (_speed*elapsedTime)));
        _lastMovement = _direction;
        return true;
    }
    if (_direction == DOWN) {
        _mesh->setPosition(irr::core::vector3df(_coordinates.first + (_speed*elapsedTime), 0, _coordinates.second));
        _lastMovement = _direction;
        return true;
    }
    if (_direction == LEFT) {
        _mesh->setPosition(irr::core::vector3df(_coordinates.first, 0, _coordinates.second - (_speed*elapsedTime)));
        _lastMovement = _direction;
        return true;
    }
    if (_reloadTimer.getElapsedSeconds() > 2 && _nbLoadedBombs < _magSize) {
        _nbLoadedBombs += 1;
    }
    return (false);
}

void AI::putBomb(std::vector<std::shared_ptr<IEntity>> &listEntities)
{
    if (_isBombing == true && _nbLoadedBombs > 0) {
        std::shared_ptr<Bomb> bomb = std::make_shared<Bomb>(_smgr, _driver, _listTriSelectors, _firePower);
        bomb->setPosition(this->getPosition());
        bomb->setOwner(nullptr, &_score);
        listEntities.push_back(bomb);
        setBombing(false);
        _justBombed = true;
        _nbLoadedBombs -= 1;
        _reloadTimer.restart();
    }
}