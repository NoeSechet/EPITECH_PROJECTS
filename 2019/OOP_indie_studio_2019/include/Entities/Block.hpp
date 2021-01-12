/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_

#include <iostream>
#include <memory>

#include <irrlicht.h>

#include "IEntity.hpp"
#include "../RNGenerator.hpp"

class Cube : public IEntity
{
    private:

    protected:
        irr::scene::IMeshSceneNode* _cubeMesh = nullptr;
        bool _isDestroyed = false;
        bool _destructible = false;
        irr::core::vector3df _lastPosition = {0.0f,0.0f,0.0f};
        POWER_TYPE _powerType = POWER_TYPE::NO_POWER;

    public:
        Cube(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
            ID_rayPickable idPick, bool destructible);
        ~Cube() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _cubeMesh; }
        irr::core::vector3df getPosition() const override;
        void setPosition(irr::core::vector3df pos) override;
        bool update(float elapsedTime) override { return true; }
        EntityType getType() const override { return EntityType::OBSTACLE; }

        irr::core::vector3df getLastPosition() const { return _lastPosition; }
        void setLastPosition();
        void initPower(unsigned int seedVal);
        POWER_TYPE getPowerType() const { return _powerType; }
        void setPowerType(POWER_TYPE type) { _powerType = type; }
        bool isDestructible() const { return _destructible; }
        void setDestructible(bool destructible) { _destructible = destructible; }
        bool getID() const;
        void setID(int ID);
        bool isDestroyed() const { return _isDestroyed; }
        void setDestroyedStatus(bool isDestroyed) { _isDestroyed = isDestroyed; }
};

#endif /* !BLOCK_HPP_ */
