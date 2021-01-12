/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Power
*/

#ifndef POWER_HPP_
#define POWER_HPP_

#include <iostream>
#include <memory>
#include <random>
#include <ctime>

#include "../IEntity.hpp"
#include "../../Timer.hpp"

class Power : public IEntity
{
    protected:
        irr::scene::IMeshSceneNode* _powerMesh = nullptr;
        bool _destructible = false;
        bool _isPicked = false;
        Timer _timer;
        float _rotation = 10.0f;
    public:
        Power(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
            ID_rayPickable idPick, bool destructible);
        ~Power() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _powerMesh; }
        irr::core::vector3df getPosition() const override;
        void setPosition(irr::core::vector3df pos) override;
        bool update(float elapsedTime) override;
        EntityType getType() const override { return EntityType::POWER; }

        virtual POWER_TYPE getPowerType() const = 0;

        bool isPicked() const { return _isPicked; }
        void setPicked(bool picked) { _isPicked = picked; }

};

#endif /* !POWER_HPP_ */
