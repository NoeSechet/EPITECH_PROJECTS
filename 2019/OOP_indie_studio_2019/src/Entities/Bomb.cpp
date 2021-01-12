/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "../../include/Entities/Bomb.hpp"
#include "../../include/Sound.hpp"

Bomb::Bomb(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
    irr::scene::IMetaTriangleSelector* listTriSelectors, unsigned int firePower)
    : _listTriSelectors(listTriSelectors), _firePower(firePower)
{
    if (!smgr || !driver)
        throw std::logic_error("Bomb constructor error: invalid scene/driver/collision list");
    _bombMesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/tilted_bomb_9.obj"), 0);
    _bombMesh->setID(ID_rayPickable::IsNotPickable);
    _bombMesh->setMaterialTexture(0, driver->getTexture("../asset/bomb.jpg"));

    _bombMesh->setTriangleSelector(smgr->createTriangleSelector(_bombMesh->getMesh(), _bombMesh));

    _timer.start();
}

bool Bomb::update(float elapsedTime)
{
    if (_bombMesh == nullptr || _ownerMesh == nullptr)
        return false;
    double sec = _timer.getElapsedSeconds();

    if (sec > 3) {
        _exploded = true;
    }
    if (_ownerMesh != nullptr) {
        irr::core::vector3df pos = _ownerMesh->getPosition();
        if (pos.getDistanceFrom(getPosition()) > 20.0 && isInsideOwner == true) {
            _listTriSelectors->addTriangleSelector(_bombMesh->getTriangleSelector());
            isInsideOwner = false;
            _ownerMesh = nullptr;
        }
    }
    return true;
}

irr::core::vector3df Bomb::getPosition() const
{
    if (_bombMesh)
        return _bombMesh->getPosition();
    else
        return irr::core::vector3df();
}

void Bomb::setPosition(irr::core::vector3df pos)
{
    if (_bombMesh)
        _bombMesh->setPosition(pos);
}
