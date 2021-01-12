/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Power
*/

#include "../../../include/Entities/Powers/Power.hpp"

Power::Power(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
    irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
    ID_rayPickable idPick, bool destructible)
    : _destructible(destructible)
{
}

bool Power::update(float elapsedTime)
{
    if (_powerMesh) {
        _powerMesh->setRotation(_powerMesh->getRotation() + _rotation * elapsedTime);
    }

    return true;
}

irr::core::vector3df Power::getPosition() const
{
    if (_powerMesh)
        return _powerMesh->getPosition();
    else
        return irr::core::vector3df();
}

void Power::setPosition(irr::core::vector3df pos)
{
    if (_powerMesh)
        _powerMesh->setPosition(pos);
}
