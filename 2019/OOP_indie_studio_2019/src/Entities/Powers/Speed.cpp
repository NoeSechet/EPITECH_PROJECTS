/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Speed
*/

#include "../../../include/Entities/Powers/Speed.hpp"

Speed::Speed(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
    irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
    ID_rayPickable idPick, bool destructible)
    : Power(smgr, driver,listTriSelectors,pos,idPick,destructible)
{
    if (smgr == nullptr || driver == nullptr || listTriSelectors == nullptr)
        throw std::logic_error("Power (Speed) constructor error: invalid scene/driver/collision list");

    _powerMesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/power_speed.obj"), 0, idPick);
    _powerMesh->setPosition(pos);
    _powerMesh->setMaterialTexture(0, driver->getTexture("../asset/bricks.png"));

    _powerMesh->setTriangleSelector(smgr->createTriangleSelector(_powerMesh->getMesh(), _powerMesh));
}