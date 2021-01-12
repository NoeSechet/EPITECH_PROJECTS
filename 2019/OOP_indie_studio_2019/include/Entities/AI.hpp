/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <vector>
#include <memory>
#include <algorithm>
#include <random>

#include "IEntity.hpp"
#include "Player.hpp"
#include "../Map.hpp"
#include "Bomb.hpp"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE,
    BELOW,
};

class AI : public IEntity {
    private:
        irr::scene::ISceneManager* _smgr = nullptr;
        irr::video::IVideoDriver* _driver = nullptr;
        irr::scene::IMetaTriangleSelector* _listTriSelectors = nullptr;
        irr::scene::IMeshSceneNode* _mesh = nullptr;
        bool _isDead = false;
        float _speed = 100.0f;
        bool _isBombing = false;
        bool _justBombed = false;
        bool _lastSpaceSave = true;
        Direction _direction = NONE;
        Direction _lastMovement = NONE;
        EntityType _type_map[15][15] = {};
        std::pair<int, int> _map_pos;
        std::pair<float, float> _coordinates;
        int _score = 0;
        Timer _reloadTimer;
        Timer _rateOfFire;
        Timer _incrementSave;
        unsigned int _spaces_since_danger = 4;
        unsigned int _firePower = 1;
        unsigned int _nbLoadedBombs = 1;
        unsigned int _magSize = 1;
        int counter = 0;
        int lastx = 0;
        int lastz = 0;
    public:
        AI(irr::scene::ISceneManager* _smgr, irr::video::IVideoDriver* _driver, irr::scene::IMetaTriangleSelector* listTriSelectors);
        ~AI() = default;

        irr::scene::IMeshSceneNode* getMesh() const override { return _mesh; }
        irr::core::vector3df getPosition() const override { return _mesh->getPosition(); }
        void setPosition(irr::core::vector3df pos) override { _mesh->setPosition(pos); }
        bool calculateNextMove(std::vector<std::shared_ptr<IEntity>> entities);
        std::vector<Direction> scanForDanger(int up_down, int left_right);
        std::vector<Direction> scanForAvailablePath(void);
        std::vector<Direction> scanForObstacles(void);

        bool dodge_danger(std::vector<Direction> dangers, std::vector<Direction> paths);
        bool avoid_closest_danger(std::vector<Direction> dangers, std::vector<Direction> paths);
        int getDangerDistance(Direction direction);
        bool moveAI(Direction direction, float elapsedTime);

        unsigned int getFirePower() const { return _firePower; }
        void setFirePower(unsigned int firePower) { _firePower = firePower; }
        float getSpeed() const { return _speed; }
        void setSpeed(float speed) { if (speed <= 300.0f) _speed = speed; }
        unsigned int getMagSize() const { return _magSize; }
        void setMagSize(unsigned int magSize) { _magSize = magSize; }

        bool update(float elapsedTime) override;
        EntityType getType() const override { return EntityType::IA; }
        bool fillMap(std::vector<std::shared_ptr<IEntity>> entities);

        void putBomb(std::vector<std::shared_ptr<IEntity>> &listEntities);
        bool isBombing() const { return _isBombing; }
        void setBombing(bool val) { _isBombing = val; }
        void setDeadStatus(bool dead) { _isDead = dead; }
        bool isDead(void) { return _isDead; }
    protected:
};

#endif /* !AI_HPP_ */
