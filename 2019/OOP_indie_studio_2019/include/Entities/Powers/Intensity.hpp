/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Intensity
*/

#ifndef INTENSITY_HPP_
#define INTENSITY_HPP_

#include "Power.hpp"
#include "../../Timer.hpp"

class Intensity : public Power {
    private:
        
    public:
        Intensity(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
            ID_rayPickable idPick, bool destructible);
        ~Intensity() = default;

        POWER_TYPE getPowerType() const override { return POWER_TYPE::INTENSITY; };

    protected:
};

#endif /* !INTENSITY_HPP_ */
