/*
** EPITECH PROJECT, 2020
** ENTITY_HPP
** File description:
** ENTITY_HPP
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

#include <irrlicht.h>
#include "EntityEnumeration.hpp"

class IEntity {
    public:
        IEntity() {};

        virtual irr::scene::IMeshSceneNode* getMesh() const = 0;
        virtual irr::core::vector3df getPosition() const = 0;
        virtual void setPosition(irr::core::vector3df pos) = 0;
        virtual bool update(float elapsedTime) = 0;
        virtual EntityType getType() const = 0;
};

#endif /* !ENTITY_HPP */
