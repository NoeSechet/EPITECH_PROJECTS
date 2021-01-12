/*
** EPITECH PROJECT, 2020
** SOLAR_FOX
** File description:
** SOLAR_FOX
*/

#include "../include/SolarFox.hpp"
#include <fstream>
#include <iostream>
#include "../include/Entities.hpp"
#include <string>


// Si pas de fichier, il faut en générer 1 avec unknow:0
namespace games {

    SolarFox::SolarFox()
    {}

    SolarFox::~SolarFox()
    {}

    void SolarFox::setUsername(std::string username)
    {
        m_username = username;
    }

    void SolarFox::loadClassFromChar(char c, long int x, long int y)
    {
        std::pair <long int, long int> coord = {x * 32, y * 32};

        switch (c) {
            case '1': m_objectToDraw.push_back(new Monster(coord, std::make_pair(0 * 32, 1 * 32), "monster_right")); static_cast <Monster *> (m_objectToDraw[m_objectToDraw.size()-1])->setDirectionLazer(RIGHT); break;
            case '2': m_objectToDraw.push_back(new Monster(coord, std::make_pair(-1 * 32, 0 * 32), "monster_down")); static_cast <Monster *> (m_objectToDraw[m_objectToDraw.size()-1])->setDirectionLazer(DOWN); break;
            case '3': m_objectToDraw.push_back(new Monster(coord, std::make_pair(0 * 32, -1 * 32), "monster_left")); static_cast <Monster *> (m_objectToDraw[m_objectToDraw.size()-1])->setDirectionLazer(LEFT); break;
            case '4': m_objectToDraw.push_back(new Monster(coord, std::make_pair(1 * 32, 0 * 32), "monster_up")); static_cast <Monster *> (m_objectToDraw[m_objectToDraw.size()-1])->setDirectionLazer(UP); break;
            case '^': m_player = new Player(coord); m_objectToDraw.push_back(m_player);  break;
            case 'S': m_scoreText = new Text(coord, "score_text"); m_scoreText->setValue(m_username + ", your score is : 0"); m_objectToDraw.push_back(m_scoreText);  break;
            case 'B': m_scoreBestText = new Text(coord, "best_score_text"); m_objectToDraw.push_back(m_scoreBestText);  break;
            case 'E': m_endText = new Text(coord, "end_text"); m_objectToDraw.push_back(m_endText);  break;
            case '*': m_objectToDraw.push_back(new Target(coord)); m_totalTarget += 1; break;
            case '#': m_objectToDraw.push_back(new Border(coord)); break;
            default: break;
        }
    }
    void SolarFox::loadLevel()
    {
        size_t x = 0;
        size_t y = 0;
        std::string input = "";
        std::ifstream file("./games/solar_fox/assets/level");

        if (!file)
            throw std::logic_error("Could not open the level file : SolarFox level");
        for (; getline(file, input); y += 1) {
            x = 0;
            for (; x < input.size(); x += 1)
                loadClassFromChar(input[x], x, y);
        }
        file.close();
    }

    void SolarFox::loadScore()
    {
        std::string username = "";
        std::string score = "";
        std::ifstream file("./games/solar_fox/assets/score");

        if (!file) {
            m_scoreBestText->setValue("No best score.");
            return;
        }
        getline(file, username);
        getline(file, score);
        m_scoreBestText->setValue(username + " has the best score, with " + score + " targets destroyed.");
        m_bestScore = std::stoi(score);
    }

    void SolarFox::restart()
    {
        end();
        start();
        m_finished = false;
    }
    void SolarFox::saveScore()
    {
        std::ofstream outfile ("./games/solar_fox/assets/score"); // path pas bon

        outfile << m_username << std::endl << m_destroyedTarget << std::endl;
        outfile.close();
    }

    void SolarFox::gameFinished()
    {
        if ((m_player == nullptr || m_leftTarget == 0) && m_finished == false) {
            m_endText->setValue("Press the Action button to restart.");
            m_finished = true;
            if (m_destroyedTarget > m_bestScore)
                saveScore();
        }
    }

    bool SolarFox::start()
    {
        loadLevel();
        loadScore();
        return true;
    }

    bool SolarFox::end()
    {
        m_objectToDraw.clear();
        m_leftTarget = 0;
        m_bestScore = 0;
        m_totalTarget = 0;
        m_destroyedTarget = 0;
        return true;
    }

    std::vector <IObjectToDraw *> SolarFox::getAssets() const
    {
        std::vector <IObjectToDraw *> assets;
        std::pair <long int, long int> default_coord = {0,0};

        assets.push_back(new Player(default_coord, "player_up", "./games/solar_fox/assets/player_up/"));
        assets.push_back(new Player(default_coord, "player_down", "./games/solar_fox/assets/player_down/"));
        assets.push_back(new Player(default_coord, "player_right", "./games/solar_fox/assets/player_right/"));
        assets.push_back(new Player(default_coord, "player_left", "./games/solar_fox/assets/player_left/"));
        assets.push_back(new Monster(default_coord, default_coord, "monster_up", "./games/solar_fox/assets/monster_up/"));
        assets.push_back(new Monster(default_coord, default_coord, "monster_left", "./games/solar_fox/assets/monster_left/"));
        assets.push_back(new Monster(default_coord, default_coord, "monster_right", "./games/solar_fox/assets/monster_right/"));
        assets.push_back(new Monster(default_coord, default_coord, "monster_down", "./games/solar_fox/assets/monster_down/"));
        assets.push_back(new Target(default_coord, "target", "./games/solar_fox/assets/target/"));
        assets.push_back(new Border(default_coord, "border", "./games/solar_fox/assets/border/"));
        assets.push_back(new Lazer(default_coord, default_coord, Lazer::O_PLAYER, "lazer", "./games/solar_fox/assets/lazer/"));
        assets.push_back(new Text(default_coord, "score_text", "./games/solar_fox/assets/font/"));
        assets.push_back(new Text(default_coord, "best_score_text", "./games/solar_fox/assets/font/"));
        assets.push_back(new Text(default_coord, "end_text", "./games/solar_fox/assets/font/"));
        return assets;
    }

    COMMAND SolarFox::applyInput (COMMAND userInput)
    {
        if (m_player != nullptr)
            m_player->setCommand(userInput);
        switch (userInput) {
            case UP: if (m_player) m_player->setPlayerDirection(); break;
            case DOWN: if (m_player) m_player->setPlayerDirection(); break;
            case LEFT: if (m_player) m_player->setPlayerDirection(); break;
            case RIGHT: if (m_player) m_player->setPlayerDirection(); break;
            case ACTION: if (m_finished) restart(); break;
            case RESTART: restart(); break;
            case EXIT: return MAIN_MENU;
            default: break;
        }
        return userInput;
    }

    std::vector <IObjectToDraw *> SolarFox::compute()
    {        
        m_leftTarget = 0;

        // Move
        for (size_t i = 0; i < m_objectToDraw.size(); i++)
            static_cast <Entity *> (m_objectToDraw[i])->move();
        // Impact
        for (size_t i = 0; i < m_objectToDraw.size(); i++) {
            static_cast <Entity *> (m_objectToDraw[i])->impact(m_objectToDraw);
            increaseTargetleft(static_cast <Entity *> (m_objectToDraw[i]));
        }
        // Action
        for (size_t i = 0; i < m_objectToDraw.size(); i++)
            static_cast <Entity *> (m_objectToDraw[i])->action(m_objectToDraw);
        // Update UI
        updateUI();
        // Game over ?
        gameFinished();
        // Free memory
        clearMemory(m_objectToDraw);
        return m_objectToDraw;
    }

    void SolarFox::updateUI()
    {
        m_scoreText->setValue(std::string(m_username + ", your score is : " + std::to_string(m_destroyedTarget) + "."));
    }


    void SolarFox::clearMemory(std::vector <IObjectToDraw *> &objects)
    {
        for (size_t i = 0; i < objects.size(); i++) {
            if (objects[i] == nullptr) {
                objects.erase(objects.begin() + i);
                return clearMemory(objects);
            }
            if (static_cast <Entity *> (objects[i])->getToClear() == true) {
                if (isPlayer(objects[i]->getId()))
                    m_player = nullptr;
                objects.erase(objects.begin() + i);
                return clearMemory(objects);
            }
        }
    }

    void SolarFox::increaseTargetleft(Entity * object)
    {
        if (object == nullptr)
            return;
        if (object->getId().compare("target") == 0 && object->getToClear() == false) {
            m_leftTarget += 1;
            m_destroyedTarget = m_totalTarget - m_leftTarget;
        }
    }

    bool SolarFox::isPlayer(std::string id) const
    {
        if (id.compare("player_up") == 0)
            return true;
        if (id.compare("player_down") == 0)
            return true;
        if (id.compare("player_right") == 0)
            return true;
        if (id.compare("player_left") == 0)
            return true;
        return false;
    }


    extern "C" {
        IGameInterface *entryPoint()
        {
            return new SolarFox;
        }
    }
}


// faire recursivité, des que tu sup un element, tu return ta fonction