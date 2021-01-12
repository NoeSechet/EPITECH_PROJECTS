/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MagSize
*/

#ifndef MAGSIZE_HPP_
#define MAGSIZE_HPP_

#include "Power.hpp"
#include "../../Timer.hpp"

class MagSize : public Power {
    private:
        
    public:
        MagSize(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, irr::core::vector3df pos,
            ID_rayPickable idPick, bool destructible);
        ~MagSize() = default;

        POWER_TYPE getPowerType() const override { return POWER_TYPE::MAG_SIZE; };

    protected:
};

#endif /* !MAGSIZE_HPP_ */
