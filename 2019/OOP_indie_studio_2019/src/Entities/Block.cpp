/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Block
*/

#include "../../include/Entities/Block.hpp"

Cube::Cube(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
    irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
    ID_rayPickable idPick, bool destructible)
    : _destructible(destructible)
{
    if (smgr == nullptr || driver == nullptr || listTriSelectors == nullptr)
        throw std::logic_error("Cube constructor error: invalid scene/driver/collision list");

    _cubeMesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/cube_9.obj"), 0, ID_rayPickable::IsPickable);
    _cubeMesh->setPosition(pos);
    if (destructible == true) {
        _cubeMesh->setMaterialTexture(0, driver->getTexture("../asset/bricks.png"));
        initPower(std::abs(pos.X * pos.Y * (unsigned)time(0)));
    } else
        _cubeMesh->setMaterialTexture(0, driver->getTexture("../asset/glass.png"));

    _cubeMesh->setTriangleSelector(smgr->createTriangleSelector(_cubeMesh->getMesh(), _cubeMesh));
    listTriSelectors->addTriangleSelector(_cubeMesh->getTriangleSelector());
}

void Cube::initPower(unsigned int seed)
{
    uint32_t _seedValue = seed;
    srand(_seedValue);
    std::mt19937 _RNGen;
    _RNGen.seed(_seedValue);
    std::uniform_int_distribution<uint32_t> rand_range_0_100(0, 100);
    std::uniform_int_distribution<uint32_t> rand_range_0_2(0, 2);

    unsigned int value = rand_range_0_100(_RNGen);
    unsigned int powerType = rand_range_0_2(_RNGen);

    if (value > 60) {
        switch (powerType) {
            case 0: setPowerType(POWER_TYPE::INTENSITY); break;
            case 1: setPowerType(POWER_TYPE::SPEED); break;
            case 2: setPowerType(POWER_TYPE::MAG_SIZE); break;
            default: break;
        }
    }
}

irr::core::vector3df Cube::getPosition() const
{
    if (_cubeMesh)
        return _cubeMesh->getPosition();
    else
        return _lastPosition;
}

void Cube::setPosition(irr::core::vector3df pos)
{
    if (_cubeMesh)
        _cubeMesh->setPosition(pos);
}

void Cube::setLastPosition()
{
    _lastPosition = this->getPosition();
}

bool Cube::getID() const
{
    if (_cubeMesh)
        return _cubeMesh->getID();
    else
        return -1;
}

void Cube::setID(int ID)
{
    if (_cubeMesh)
        _cubeMesh->setID(ID);
}