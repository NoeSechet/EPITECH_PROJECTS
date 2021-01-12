/*
** EPITECH PROJECT, 2020
** GAME_HPP
** File description:
** GAME_HPP
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <stdexcept>

#include <irrlicht.h>

#include "Entities/AI.hpp"
#include "UI/UIManager.hpp"
#include "Entities/IEntity.hpp"
#include "Entities/Player.hpp"
#include "Entities/BlastCube.hpp"

#include "Entities/Powers/Intensity.hpp"
#include "Entities/Powers/Speed.hpp"
#include "Entities/Powers/MagSize.hpp"
#include "Map.hpp"
#include "Timer.hpp"
#include "Sound.hpp"
#include "EventReceiver.hpp"

class Game {
  public:
    enum State {
        Title,
        MainMenu,
        Settings,
        Credits,
        Selection,
        Controls,
        Playing,
        Pause,
        End,
        Exit
    };
  private:
    // Library must.
    irr::IrrlichtDevice* _device = nullptr;
    irr::video::IVideoDriver* _driver = nullptr;
    irr::gui::IGUIEnvironment* _env = nullptr;
    irr::gui::IGUISkin* _skin = nullptr;
    irr::scene::ISceneManager* _smgr = nullptr;
    
    EventReceiver *_eventReceiver = nullptr;
    UIManager *_uiManager = nullptr;
    State _status = Title;
    float _playerSpeed = 100.0f;

        std::vector<std::shared_ptr<IEntity>> _listEntities;
        std::vector<std::shared_ptr<Player>> _listPlayer;
        std::vector<std::shared_ptr<Power>> _listPower;
        std::vector<std::shared_ptr<AI>> _listAI;
        std::vector<std::shared_ptr<Blast>> _listBlast;

        std::shared_ptr<Map> _map;

    public:
        Game();
        ~Game();

        Sound *gameSound;

        EventReceiver *getEventReceiver() const { return _eventReceiver; }
        UIManager *getUIManager() const { return _uiManager; }
        irr::IrrlichtDevice* getDevice() const { return _device; }
        irr::video::IVideoDriver* getDriver() const { return _driver; }
        irr::gui::IGUIEnvironment* getEnvironment() const { return _env; }
        irr::gui::IGUISkin* getGUISkin() const { return _skin; }
        irr::scene::ISceneManager* getSManager() const { return _smgr; }
        std::vector<std::shared_ptr<IEntity>> getEntities() const { return _listEntities; }
        State getStatus() const { return _status; }
        std::shared_ptr<Map> getMap() const { return _map; };
        std::vector<std::shared_ptr<IEntity>> &getListEntities() { return _listEntities; }
        std::vector<std::shared_ptr<Player>> &getListPLayer() { return _listPlayer; }

        void setStatus(State status) { _status = status; }

        bool initLevel(unsigned int nbPlayers, unsigned int nbAI);
        bool initPlayerList(unsigned int nbPlayers, irr::scene::IMetaTriangleSelector* listTriSelectors);
        bool initMap();
        void displayFPS(int lastFP);

        void selection();
        bool update(float elapsedTime);
        void checkPowerCollision(std::shared_ptr<IEntity> player_AI);
        void removeDestroyedEntities();
        void removeNodeFromSceneList(std::shared_ptr<IEntity> entity, size_t i);
        void spawnPower(std::shared_ptr<Cube> cube);

        void detonateBomb(std::shared_ptr<Bomb> bomb);
        void displayBlastCubes(irr::core::vector3df vectorBlast, irr::core::vector3df origin, unsigned int firePower);
        bool checkDeadPlayers(irr::scene::ISceneNode* selectedSceneNode);
        bool checkDeadAI(irr::scene::ISceneNode* selectedSceneNode);
        bool checkDestroyedCube(irr::scene::ISceneNode* selectedSceneNode);

        void clearAllEntities();
        void endGame();

        template<typename T>
        void generatePowerEntity(std::shared_ptr<Cube> cube)
        {
            std::shared_ptr<Power> power = nullptr;

            power = std::make_shared<T>(
                _smgr, _driver, _map->getTriSelector(), cube->getLastPosition(),
                ID_rayPickable::IsPickable, true
            );
            _listPower.push_back(power);
            _listEntities.push_back(power);
        }

};

#endif /* !GAME_HPP */