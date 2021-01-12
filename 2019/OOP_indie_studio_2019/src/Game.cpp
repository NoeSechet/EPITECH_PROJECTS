/*
** EPITECH PROJECT, 2020
** GAME_CPP
** File description:
** GAME_CPP
*/

#include "../include/EventReceiver.hpp"
#include "../include/UI/UIManager.hpp"
#include "../include/Game.hpp"
#include "../include/UI/UIEnd.hpp"
#include "../include/Menus/PlayerSelection/UIPlayerSelection.hpp"

#include "../include/Sound.hpp"

#include "../include/Entities/Powers/Intensity.hpp"

#include <iostream>
#include <string>
#include <codecvt>
#include <locale>

Game::Game()
{
    _device = irr::createDevice(irr::video::E_DRIVER_TYPE::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 16);
	_driver = _device->getVideoDriver();
	_env = _device->getGUIEnvironment();
    _skin = _env->getSkin();

    _device->getCursorControl()->setVisible(true);
	_device->setResizable(true);

    _uiManager = new UIManager();
    _eventReceiver = new EventReceiver(_env, this);
	_device->setEventReceiver(_eventReceiver);
    _smgr = this->getDevice()->getSceneManager();

    gameSound = new Sound();
    gameSound->loadClickSound();
    gameSound->loadExplosionSound();
    gameSound->loadGameTheme();
}

Game::~Game()
{
    delete gameSound;
}

bool Game::initLevel(unsigned int nbPlayers, unsigned int nbAI)
{
    (void)nbAI;
    irr::video::IVideoDriver* bomb_driver = this->getDriver();
    irr::IrrlichtDevice* bomb_device = this->getDevice();
    irr::scene::ICameraSceneNode* camera = _smgr->addCameraSceneNode(0,
        irr::core::vector3df(100.0f, 300.0f, 0.0f),
        irr::core::vector3df(0.0f, 0.0f, 0.0f)
    );

    if (initMap() == false || initPlayerList(nbPlayers, _map->getTriSelector()) == false)
        throw std::logic_error("Error: map/player initialization failed!");

    std::vector<irr::core::vector3df> listPositions = {
        { 13.0f * 20.0f - 150.0f + 9.0f , 40.0f, 13.0f * 20.0f - 150.0f + 9.0f },
        { 1.0f * 20.0f - 150.0f + 9.0f , 40.0f, 13.0f * 20.0f - 150.0f + 9.0f },
        { 13.0f * 20.0f - 150.0f + 9.0f , 40.0f, 1.0f * 20.0f - 150.0f + 9.0f },
        { 1.0f * 20.0f - 150.0f + 9.0f , 40.0f, 1.0f * 20.0f - 150.0f + 9.0f },
    };
    for (size_t i = 0; i < nbAI; ++i) {
        auto newAI = std::make_shared<AI>(_smgr, _driver, _map->getTriSelector());
        newAI->setPosition(listPositions[i]);
        _listAI.push_back(newAI);
        _listEntities.push_back(newAI);
    }
    _smgr->addSkyBoxSceneNode(
        bomb_driver->getTexture("../asset/land_up.jpg"),
        bomb_driver->getTexture("../asset/land_down.jpg"),
        bomb_driver->getTexture("../asset/land_left.jpg"),
        bomb_driver->getTexture("../asset/land_right.jpg"),
        bomb_driver->getTexture("../asset/land_front.jpg"),
        bomb_driver->getTexture("../asset/land_back.jpg")
    );
    irr::scene::ILightSceneNode* light = _smgr->addLightSceneNode(0, irr::core::vector3df(0, 100, 0),
        irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 6000.0f);

    return true;
}

bool Game::initPlayerList(unsigned int nbPlayers, irr::scene::IMetaTriangleSelector* listTriSelectors)
{
    if (listTriSelectors == nullptr) {
        throw std::logic_error("Error: listTriSelector uninitialized inside initPlayerList()");
    }
    std::vector<std::vector<irr::EKEY_CODE>> listKeyMap = {
        { irr::KEY_KEY_W, irr::KEY_KEY_S, irr::KEY_KEY_A, irr::KEY_KEY_D, irr::KEY_KEY_Q },
        { irr::KEY_UP,    irr::KEY_DOWN,  irr::KEY_LEFT,  irr::KEY_RIGHT, irr::KEY_KEY_M },
        { irr::KEY_KEY_I, irr::KEY_KEY_K, irr::KEY_KEY_J, irr::KEY_KEY_L, irr::KEY_KEY_U },
        { irr::KEY_KEY_T, irr::KEY_KEY_G, irr::KEY_KEY_F, irr::KEY_KEY_H, irr::KEY_KEY_R }
    };
    std::vector<irr::core::vector3df> listPositions = {
        { 1.0f * 20.0f - 150.0f + 9.0f , 20.0f, 1.0f * 20.0f - 150.0f + 9.0f },
        { 13.0f * 20.0f - 150.0f + 9.0f , 20.0f, 1.0f * 20.0f - 150.0f + 9.0f },
        { 0.0f * 20.0f - 150.0f + 9.0f , 20.0f, 13.0f * 20.0f - 150.0f + 9.0f },
        { 13.0f * 20.0f - 150.0f + 9.0f , 20.0f, 13.0f * 20.0f - 150.0f + 9.0f },
    };

    for (size_t i = 0; i < nbPlayers; ++i) {
        auto newPlayer = std::make_shared<Player>(_smgr, _driver, _eventReceiver, listTriSelectors);
        newPlayer->setPosition(listPositions[i]);
        newPlayer->bindKeyMovements(listKeyMap[i]);
        newPlayer->setPlayerNb(PLAYER_1 + i);
        _listPlayer.push_back(newPlayer);
        _listEntities.push_back(newPlayer);
    }
    return true;
}

bool Game::initMap()
{
    _map = std::make_shared<Map>(_smgr, _driver);

    if (!_map)
        return false;
    else
        return true;
}

void Game::displayFPS(int lastFPS)
{
    int fps = this->getDriver()->getFPS();
    if (lastFPS != fps)
    {
        irr::core::stringw str = L"Bomberman game - Irrlicht Engine [";
        str += this->getDriver()->getName();
        str += "] FPS:";
        str += fps;
        this->getDevice()->setWindowCaption(str.c_str());
        lastFPS = fps;
    }
}

void Game::selection()
{
    UIPlayerSelection *selection = static_cast<UIPlayerSelection *>(_uiManager->getInterface(GUI_ID_PLAYERSELECTION_INTERFACE));

    if (!selection)
        return;
    selection->update();
}

bool Game::update(float elapsedTime)
{
    // Should loop on the vector of [Entity* ] and call the function update().
    for (auto entity : _listEntities) {
        if (entity) {
            if (entity->getType() == IA) {
                std::shared_ptr<AI> ai = std::static_pointer_cast<AI>(entity);
                ai->calculateNextMove(_listEntities);
            }
            entity->update(elapsedTime);
        }
    }
    for (auto player : _listPlayer) {
        player->putBomb(_listEntities);
        checkPowerCollision(player);
    }
    for (auto ai : _listAI) {
        ai->putBomb(_listEntities);
        checkPowerCollision(ai);
    }
    for (auto blast : _listBlast) {
        if (blast)
            blast->update(elapsedTime);
    }
    removeDestroyedEntities();
    endGame();
    return true;
}

void Game::checkPowerCollision(std::shared_ptr<IEntity> player_AI)
{
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<AI> artificialInt = nullptr;
    size_t i = 0;

    for (auto power : _listPower) {
        if (player_AI && power && power->getMesh()) {
            if (power->isPicked() == false && player_AI->getPosition().getDistanceFrom(power->getPosition()) <= 20.0) {
                EntityType ent_type =  player_AI->getType();
                if (ent_type == EntityType::PLAYER) {
                    player = std::static_pointer_cast<Player>(player_AI);
                    switch (power->getPowerType()) {
                        case POWER_TYPE::INTENSITY: player->setFirePower(player->getFirePower() + 1); break;
                        case POWER_TYPE::SPEED: player->setSpeed(player->getSpeed() + 25); break;
                        case POWER_TYPE::MAG_SIZE: player->setMagSize(player->getMagSize() + 1); break;
                        default: break;
                    }
                } else if (ent_type == EntityType::IA) {
                    artificialInt = std::static_pointer_cast<AI>(player_AI);
                    switch (power->getPowerType()) {
                        case POWER_TYPE::INTENSITY: artificialInt->setFirePower(artificialInt->getFirePower() + 1); break;
                        case POWER_TYPE::SPEED: artificialInt->setSpeed(artificialInt->getSpeed() + 25); break;
                        case POWER_TYPE::MAG_SIZE: artificialInt->setMagSize(artificialInt->getMagSize() + 1); break;
                        default: break;
                    }
                }
                power->setPicked(true);
                _listPower.erase(_listPower.begin() + i);
            }
        }
        i += 1;
    }
}

void Game::detonateBomb(std::shared_ptr<Bomb> bomb)
{
    irr::scene::IMetaTriangleSelector* listTriSelectors = nullptr;
    irr::scene::ISceneCollisionManager* collMan = _smgr->getSceneCollisionManager();
    irr::scene::ISceneNode* selectedSceneNode = nullptr;
    std::vector<irr::core::line3d<float>> listRay;

    listRay.resize(4);
    if (!_map || (listTriSelectors = _map->getTriSelector()) == nullptr)
        throw std::logic_error("Error: listTriSelector uninitialized inside detonateRemoveBomb()");

    listRay[0].start = bomb->getPosition() + irr::core::vector3df(10.0f, 0.0f, 0.0f);
    listRay[1].start = bomb->getPosition() + irr::core::vector3df(-10.0f, 0.0f, 0.0f);
    listRay[2].start = bomb->getPosition() + irr::core::vector3df(0.0f, 0.0f, 10.0f);
    listRay[3].start = bomb->getPosition() + irr::core::vector3df(0.0f, 0.0f, -10.0f);

    listRay[0].end = listRay[0].start + irr::core::vector3df(18.0f, 0.0f, 0.0f) * bomb->getFirePower();
    listRay[1].end = listRay[1].start + irr::core::vector3df(-18.0f, 0.0f, 0.0f) * bomb->getFirePower();
    listRay[2].end = listRay[2].start + irr::core::vector3df(0.0f, 0.0f, 18.0f) * bomb->getFirePower();
    listRay[3].end = listRay[3].start + irr::core::vector3df(0.0f, 0.0f, -18.0f) * bomb->getFirePower();

    irr::core::vector3df intersection;
    irr::core::triangle3df triangle;

    for (auto ray : listRay)
    {
        selectedSceneNode = collMan->getSceneNodeAndCollisionPointFromRay(
            ray, intersection, triangle, ID_rayPickable::IsPickable, 0
        );
        if (selectedSceneNode) {
            displayBlastCubes((selectedSceneNode->getPosition() - bomb->getPosition()).normalize(), bomb->getPosition(), bomb->getFirePower());
            if (checkDeadPlayers(selectedSceneNode) == true) {
                bomb->incrementScore(5);
                listTriSelectors->removeTriangleSelector(selectedSceneNode->getTriangleSelector());
            }
            if (checkDeadAI(selectedSceneNode) == true) {
                bomb->incrementScore(5);
                listTriSelectors->removeTriangleSelector(selectedSceneNode->getTriangleSelector());
            }
            if (checkDestroyedCube(selectedSceneNode) == true) {
                bomb->incrementScore(1);
                listTriSelectors->removeTriangleSelector(selectedSceneNode->getTriangleSelector());
            }
        } else {
            displayBlastCubes(ray.getVector().normalize(), bomb->getPosition(), bomb->getFirePower());
        }
    }
}

void Game::displayBlastCubes(irr::core::vector3df vectorBlast, irr::core::vector3df origin, unsigned int firePower)
{
    irr::core::vector3df pos;
    irr::core::vector3df len20 = vectorBlast * 20.0f;

    for (unsigned int i = 0; i < firePower; i += 1)
    {
        pos = origin + len20 * i + len20;
        std::shared_ptr<Blast> blast = std::make_shared<Blast>(_smgr, _driver, pos);
        _listBlast.push_back(blast);
    }
}

void Game::spawnPower(std::shared_ptr<Cube> cube)
{
    std::shared_ptr<Power> power = nullptr;

    if (_map && _map->getTriSelector() && cube)
    {
        switch (cube->getPowerType())
        {
            case POWER_TYPE::INTENSITY: generatePowerEntity<Intensity>(cube); break;
            case POWER_TYPE::SPEED: generatePowerEntity<Speed>(cube); break;
            case POWER_TYPE::MAG_SIZE: generatePowerEntity<MagSize>(cube); break;
            default: break;
        }
    }
}

void Game::removeNodeFromSceneList(std::shared_ptr<IEntity> entity, size_t i)
{
    irr::scene::IMeshSceneNode* node = nullptr;
    irr::scene::IMetaTriangleSelector* listTriSelector = nullptr;

    if ((node = entity->getMesh()) != nullptr && _map && (listTriSelector = _map->getTriSelector())) {
        listTriSelector->removeTriangleSelector(node->getTriangleSelector());
        node->remove();
        node = nullptr;
        _listEntities.erase(_listEntities.begin() + i);
    }
}

void Game::removeDestroyedEntities()
{
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<Cube> cube = nullptr;
    std::shared_ptr<AI> artificialInt = nullptr;
    std::shared_ptr<Bomb> bomb = nullptr;
    std::shared_ptr<Power> power = nullptr;
    irr::scene::IMeshSceneNode* node = nullptr;
    size_t i = 0;

    for (auto entity : _listEntities) {
        if (!entity) continue;
        switch (entity->getType()) {
            case EntityType::PLAYER: player = std::static_pointer_cast<Player>(entity); player->setScorePtr(nullptr);
                if (player->isDead() == true)
                    removeNodeFromSceneList(entity, i);
                break;
            case EntityType::OBSTACLE: cube = std::static_pointer_cast<Cube>(entity);
                if (cube && cube->isDestroyed() == true) {
                    removeNodeFromSceneList(entity, i);
                    spawnPower(cube);
                }
                break;
            case EntityType::IA:
                if (std::static_pointer_cast<AI>(entity)->isDead() == true)
                    removeNodeFromSceneList(entity, i);
                break;
            case EntityType::BOMB: bomb = std::static_pointer_cast<Bomb>(entity);
                if (bomb && bomb->getTimer().getElapsedSeconds() > 3) {
                    gameSound->explosionSound.play();
                    detonateBomb(bomb);
                    removeNodeFromSceneList(entity, i);
                }
                break;
            case EntityType::POWER: power = std::static_pointer_cast<Power>(entity);
                if (power && power->isPicked() == true) {
                    irr::scene::IMeshSceneNode* node = power->getMesh();
                    if (node) {
                        node->remove();
                        node = nullptr;
                    }
                    _listEntities.erase(_listEntities.begin() + i);
                }
                break;
            default: break;
        }
        i += 1;
    }
    int j = 0;
    for (auto blast : _listBlast) {
        if (blast && blast->getTimer().getElapsedSeconds() >= 0.2) {
            node = blast->getMesh();
            if (node) {
                node->remove();
                node = nullptr;
            }
            _listBlast.erase(_listBlast.begin() + j);
        }
        j += 1;
    }
}

bool Game::checkDeadPlayers(irr::scene::ISceneNode* selectedSceneNode)
{
    for (size_t i = 0; i < _listPlayer.size(); i += 1) {
        if (selectedSceneNode == _listPlayer[i]->getMesh()) {
            _listPlayer[i]->setDeadStatus(true);
            _listPlayer.erase(_listPlayer.begin() + i);
            return true;
        }
    }
    return false;
}

bool Game::checkDeadAI(irr::scene::ISceneNode* selectedSceneNode)
{
    for (size_t i = 0; i < _listAI.size(); i += 1) {
        if (selectedSceneNode == _listAI[i]->getMesh()) {
            _listAI[i]->setDeadStatus(true);
            _listAI.erase(_listAI.begin() + i);
            return true;
        }
    }
    return (false);
}

bool Game::checkDestroyedCube(irr::scene::ISceneNode* selectedSceneNode)
{
    std::vector<std::shared_ptr<Cube>> &listCube = _map->getListCube();
    size_t i = 0;

    for (auto cube : listCube)
    {
        if (selectedSceneNode == cube->getMesh() && cube->isDestructible() == true) {
            cube->setDestroyedStatus(true);
            cube->setLastPosition();
            listCube.erase(listCube.begin() + i);
            return true;
        }
        i += 1;
    }

    for (size_t i = 0; i < _map->getListCube().size(); i += 1) {
        
    }
    return false;
}


void Game::clearAllEntities()
{
    if (_map != nullptr && _map->getTriSelector() != nullptr) {
        _map->getTriSelector()->removeAllTriangleSelectors();
    }

    for (auto entity : getListEntities())
	{
        irr::scene::IMeshSceneNode* node = entity->getMesh();
        if (node != nullptr) {
		    node->remove();
            node = nullptr;
        }
	}
	_listEntities.clear();
	_listPlayer.clear();
    _listAI.clear();
    _listBlast.clear();
    _listPower.clear();
	if (_map)
		_map->getListCube().clear();
}

void Game::endGame()
{
    if (_status == Game::State::End) return;
    if (_listPlayer.size() == 1 && _listAI.size() == 0)
    {
        std::cout << "a player won" << std::endl;
        _status = Game::State::End;
        _uiManager->clear();
        _uiManager->add(new UIEnd(_env, _driver, _listPlayer[0]->getPlayerNb()));
    }
    else if (_listPlayer.size() == 0 && _listAI.size() != 0)
    {
        std::cout << "ai won" << std::endl;
        _status = Game::State::End;
        _uiManager->clear();
        _uiManager->add(new UIEnd(_env, _driver, EntityType::IA));
    }
}
