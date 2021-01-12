/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include <memory>

#include "IEntity.hpp"
#include "Bomb.hpp"

class Player : public IEntity {
    private:
        irr::scene::ISceneManager* _smgr = nullptr;
        irr::video::IVideoDriver* _driver = nullptr;
        irr::scene::IMetaTriangleSelector* _listTriSelectors = nullptr;
        irr::scene::IMeshSceneNode* _playerMesh = nullptr;
        class EventReceiver* _eventReceiver = nullptr;
        std::vector<irr::EKEY_CODE> _keyMap;
        float _speed = 100.0f;
        int _playerNb = 0;
        int _score = 0;
        int* _scorePtr = nullptr;
        bool _isBombing = false;
        bool _isDead = false;
        unsigned int _firePower = 1;
        Timer _reloadTimer;
        Timer _rateOfFire;
        unsigned int _nbLoadedBombs = 1;
        unsigned int _magSize = 1;
    public:
        Player(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, EventReceiver* eventReceiver, irr::scene::IMetaTriangleSelector* listTriSelectors);
        ~Player() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _playerMesh; }
        irr::core::vector3df getPosition() const override;
        void setPosition(irr::core::vector3df pos) override;
        bool update(float elapsedTime) override;
        EntityType getType() const override { return EntityType::PLAYER; }

        unsigned int getFirePower() const { return _firePower; }
        void setFirePower(unsigned int firePower) { _firePower = firePower; }
        float getSpeed() const { return _speed; }
        void setSpeed(float speed) { if (speed <= 300.0f) _speed = speed; }
        unsigned int getMagSize() const { return _magSize; }
        void setMagSize(unsigned int magSize) { _magSize = magSize; }

        void bindKeyMovements(const std::vector<irr::EKEY_CODE> keyMap);
        void setPlayerNb(int playerNb) { _playerNb = playerNb; }
        int getPlayerNb() { return _playerNb;}
        bool isBombing() const { return _isBombing; }
        void setBombing(bool val) { _isBombing = val; }
        bool isDead() const { return _isDead; }
        void setDeadStatus(bool isDead) { _isDead = isDead; }
        void setScorePtr(int *scorePtr) { _scorePtr = scorePtr; }

        void putBomb(std::vector<std::shared_ptr<IEntity>> &listEntities);

    protected:
};

#endif /* !PLAYER_HPP_ */
