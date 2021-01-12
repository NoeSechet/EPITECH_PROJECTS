/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#include "../include/Map.hpp"

Map::Map(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver)
    : _smgr(smgr), _driver(driver), _listTriSelectors(smgr->createMetaTriangleSelector())
{
    if (smgr == nullptr || driver == nullptr || _listTriSelectors == nullptr)
        throw std::logic_error("Bomb constructor error: invalid scene/driver/collision list");
    irr::scene::IMeshSceneNode* plane = 0;
    irr::video::SMaterial material = irr::video::SMaterial();

    plane = _smgr->addMeshSceneNode(_smgr->getMesh("../asset/plane_150.obj"), 0, ID_rayPickable::IsPickable);
    plane->setPosition(irr::core::vector3df(0, 0, 0));
    plane->setMaterialTexture(0, _driver->getTexture("../asset/dirt.png"));

    plane->setTriangleSelector(_smgr->createTriangleSelector(plane->getMesh(), plane));
    _listTriSelectors->addTriangleSelector(plane->getTriangleSelector());
}

Map::~Map()
{
}

bool Map::isPlayerZone(unsigned int x, unsigned int y)
{
    return (
        x == 1 && y == 1 ||
        x == 2 && y == 1 ||
        x == 1 && y == 2 ||

        x == 13 && y == 1 ||
        x == 12 && y == 1 ||
        x == 13 && y == 2 ||

        x == 1 && y == 13 ||
        x == 1 && y == 12 ||
        x == 2 && y == 13 ||

        x == 13 && y == 13 ||
        x == 12 && y == 13 ||
        x == 13 && y == 12
    );
}

bool Map::isBorder(unsigned int x, unsigned int y)
{
    return (
        x == 0 || x == 14 || y == 0 || y == 14
    );
}
 
bool Map::proceduralGenCubes(std::vector<std::shared_ptr<IEntity>>& listEntities)
{
    for (unsigned int x = 0; x < 15; x++) {
        for (unsigned int y = 0; y < 15; y++) {
            int val = _rng.getIntRange(0,100);

            if (isBorder(x, y) || (x % 2 == 0 && y % 2 == 0)) {
                std::shared_ptr<Cube> cube = placeCube(x, y, ID_rayPickable::IsNotPickable, false);
                listEntities.push_back(cube);
            } else if (val < 80 && !isPlayerZone(x,y)) {
                RNGenerator rng;
                std::shared_ptr<Cube> cube = placeCube(x, y, ID_rayPickable::IsPickable, true);
                listEntities.push_back(cube);
            }
        }
    }
    return true;
}

std::shared_ptr<Cube> Map::placeCube(unsigned int x, unsigned int y, ID_rayPickable idPick, bool destructible)
{
    irr::core::vector3df pos = { (float)(x * 20), 20.0f, (float)(y * 20) };
    pos.X -= 150.0f;
    pos.Z -= 150.0f;
    pos.X += 9.0f;
    pos.Z += 9.0f;
    std::shared_ptr<Cube> cube = std::make_shared<Cube>(
        _smgr, _driver, _listTriSelectors, pos, idPick, destructible
    );
    _listCubes.push_back(cube);

    return cube;
}

bool Map::addCubeToMap(std::shared_ptr<Cube> newCube)
{
    _listCubes.push_back(newCube);
    return true;
}