/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BlastCube
*/

#include "../../include/Entities/BlastCube.hpp"

Blast::Blast(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, irr::core::vector3df pos)
{
    if (!smgr || !driver)
        throw std::logic_error("Blast constructor error: invalid scene/driver/collision list");
    _mesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/power_intensity.obj"), 0);
    _mesh->setID(ID_rayPickable::IsNotPickable);
    _mesh->setMaterialTexture(0, driver->getTexture("../asset/explosion2.jpg"));

    setPosition(pos);

    _timer.start();
}

bool Blast::update(float elapsedTime)
{
    return true;
}

irr::core::vector3df Blast::getPosition() const
{
    if (_mesh)
        return _mesh->getPosition();
    else
        return irr::core::vector3df();
}

void Blast::setPosition(irr::core::vector3df pos)
{
    if (_mesh)
        _mesh->setPosition(pos);
}
