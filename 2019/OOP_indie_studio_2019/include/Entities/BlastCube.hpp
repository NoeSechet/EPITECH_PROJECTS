/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BlastCube
*/

#ifndef BLASTCUBE_HPP_
#define BLASTCUBE_HPP_

#include <stdexcept>

#include "IEntity.hpp"
#include "../Timer.hpp"

class Blast : public IEntity
{
    private:
        irr::scene::IMeshSceneNode* _mesh = nullptr;
        unsigned int _firePower = 1;
        bool _vaporised = false;
        Timer _timer;

    public:
        Blast(irr::scene::ISceneManager* _smgr, irr::video::IVideoDriver* _driver, irr::core::vector3df pos);
        ~Blast() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _mesh; }
        irr::core::vector3df getPosition() const override;
        void setPosition(irr::core::vector3df pos) override;
        bool update(float elapsedTime) override;
        EntityType getType() const override { return EntityType::BLAST; }

        Timer& getTimer() { return _timer; }
        bool isVaporised() const { return _vaporised; }

    protected:
};

#endif /* !BLASTCUBE_HPP_ */
