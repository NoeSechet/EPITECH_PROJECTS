/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <stdexcept>

#include "IEntity.hpp"
#include "../Timer.hpp"

class Bomb : public IEntity
{
    private:
        irr::scene::IMeshSceneNode* _bombMesh = nullptr;
        unsigned int _firePower = 1;
        bool _exploded = false;
        bool isInsideOwner = true;
        Timer _timer;

        int* _playerScore = nullptr;

        irr::scene::IMeshSceneNode* _ownerMesh = nullptr;

        irr::scene::IMetaTriangleSelector* _listTriSelectors = nullptr;

    public:
        Bomb(irr::scene::ISceneManager* _smgr, irr::video::IVideoDriver* _driver,
            irr::scene::IMetaTriangleSelector* listTriSelectors, unsigned int firePower);
        ~Bomb() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _bombMesh; }
        irr::core::vector3df getPosition() const override;
        void setPosition(irr::core::vector3df pos) override;
        bool update(float elapsedTime) override;
        EntityType getType() const override { return EntityType::BOMB; }

        irr::scene::ITriangleSelector* getTriSelect() { return _bombMesh->getTriangleSelector(); }
        Timer& getTimer() { return _timer; }
        bool isExploded() const { return _exploded; }
        unsigned int getFirePower() const { return _firePower; }

        void setOwner(irr::scene::IMeshSceneNode* ownerMesh, int* playerScore) { _ownerMesh = ownerMesh; _playerScore = playerScore; }
        void incrementScore(int points) { if (_playerScore) { *_playerScore += points; } }

    protected:
};

#endif