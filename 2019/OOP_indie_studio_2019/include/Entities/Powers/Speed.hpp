/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Speed
*/

#ifndef SPEED_HPP_
#define SPEED_HPP_

#include "Power.hpp"
#include "../../Timer.hpp"

class Speed : public Power {
    private:
        
    public:
        Speed(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
            ID_rayPickable idPick, bool destructible);
        ~Speed() = default;

        POWER_TYPE getPowerType() const override { return POWER_TYPE::SPEED; };

    protected:
};

#endif /* !SPEED_HPP_ */
