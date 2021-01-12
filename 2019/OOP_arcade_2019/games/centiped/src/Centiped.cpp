/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centiped
*/

#include <fstream>

#include "Centiped.hpp"
#include "Monster.hpp"
#include "time.h"

namespace games {

    Centiped::Centiped()
    {}

    Centiped::~Centiped()
    {
        for (auto ite : m_objList) {
            delete ite;
        }
    }

    bool Centiped::start()
    {
        LoadLevel();
        loadScore();
        m_spawnMonsterTimer.startTimer();
        return true;
    }

    void Centiped::restart()
    {
        end();
        m_finished = false;
        m_bestScore = 0;
        m_totalMushroom = 0;
        m_leftMushroom = 0;
        m_destroyedMushroom = 0;
        start();
    }

    bool Centiped::end()
    {
        m_objList.clear();
        return true;
    }

    std::vector <IObjectToDraw *> Centiped::getAssets() const
    {
        std::vector <IObjectToDraw *> assets;
        std::pair <long int, long int> default_coord = {0,0};

        assets.push_back(new Mushroom(default_coord, "mushroom", "./games/centiped/assets/mushroom/"));
        assets.push_back(new Border(default_coord, "border", "./games/centiped/assets/border/"));

        assets.push_back(new CentiPlayer(default_coord, "player", "./games/centiped/assets/player/"));
        assets.push_back(new Lazer(default_coord, "lazer_red", "./games/centiped/assets/redlaser/"));
        assets.push_back(new Lazer(default_coord, "lazer_white", "./games/centiped/assets/whitelaser/"));
        assets.push_back(new Monster(default_coord, "monster", "./games/centiped/assets/monster/"));

        assets.push_back(new Text(default_coord, "text_restart", "./games/centiped/assets/font/"));
        assets.push_back(new Text(default_coord, "text_score", "./games/centiped/assets/font/"));
        assets.push_back(new Text(default_coord, "text_best_score", "./games/centiped/assets/font/"));

        return assets;
    }

    COMMAND Centiped::applyInput (COMMAND userInput)
    {
        switch (userInput) {
            case UP: if (m_player->getToClear() == false) m_player->MoveUp(); break;
            case DOWN: if (m_player->getToClear() == false) m_player->MoveDown(); break;
            case LEFT: if (m_player->getToClear() == false) m_player->MoveLeft(); break;
            case RIGHT: if (m_player->getToClear() == false) m_player->MoveRight(); break;
            case ACTION: if (m_player->getToClear() == false) m_player->Shot(m_objList); break;
            case EXIT: return MAIN_MENU;
            case RESTART: restart(); break;
            default: break;
        }
        return userInput;
    }

    void Centiped::spawnMonster()
    {
        int factor = rand() % 28 + 1;
        if (m_spawnMonsterTimer.getElapsedSeconds() < 1) return;
        m_spawnMonsterTimer.restartTimer();
        m_objList.push_back(new Monster(std::make_pair(32 * factor, 32))); // faire le random ici
    }

    void Centiped::updateMushroomleft(CentiElem * object)
    {
        if (object == nullptr)
            return;
        if (object->getId().compare("mushroom") == 0 && object->getToClear() == false) {
            m_leftMushroom += 1;
            m_destroyedMushroom = m_totalMushroom - m_leftMushroom;
        }
    }

    void Centiped::updateUI()
    {
        m_textScore->setValue(m_username + ", your score is " + std::to_string(m_destroyedMushroom));
    }


    std::vector <IObjectToDraw *> Centiped::compute()
    {
        m_leftMushroom = 0;
    
        spawnMonster();
        for (size_t i = 0; i < m_objList.size(); i++) {
            static_cast <CentiElem *> (m_objList[i])->move(m_objList);
            static_cast <CentiElem *> (m_objList[i])->collision(m_objList);
            updateMushroomleft(static_cast <CentiElem *> (m_objList[i]));
        }
        updateUI();
        gameFinished();
        clearMemory(m_objList);
        return m_objList;
    }

    void Centiped::clearMemory(std::vector <IObjectToDraw *> &objects)
    {
        for (size_t i = 0; i < objects.size(); i++) {
            if (objects[i] == nullptr) {
                objects.erase(objects.begin() + i);
                return clearMemory(objects);
            }
            if (objects[i]->getCoords().second > 800) {
                objects.erase(objects.begin() + i);
                return clearMemory(objects);
            }
            if (static_cast <CentiElem *> (objects[i])->getToClear() == true) {
                objects.erase(objects.begin() + i);
                return clearMemory(objects);
            }
        }
    }

    void Centiped::LoadLevel()
    {
        std::vector<char> levelLine(30, 0);
        std::vector<std::vector<char>> level(25, levelLine);
        m_level = level;

        m_player = new CentiPlayer({(levelLine.size() / 2) * 32, (level.size() / 10 * 8) * 32});

        uint topLimit = m_level.size() / 5 * 3;

        InitPlayerLimits(topLimit);

        // generate random seed and using it to gen a number btw 0 and 10
        u_int32_t randValue = 0;
        std::mt19937 generator;
        generator.seed(randValue);
        std::uniform_int_distribution<uint32_t> rand010(0, 10);

        for (size_t i = 0; i < m_level.size(); i += 1) {
            for (size_t j = 0; j < m_level[i].size(); j += 1) {
                if (j == 0 || j == m_level[i].size() - 1) {
                    m_objList.push_back(new Border({j * 32, i * 32}));
                } else if (i < topLimit && rand010(generator) > 9) {
                    m_objList.push_back(new Mushroom({j * 32, i * 32}));
                    m_totalMushroom += 1;
                }
            }
        }
        m_objList.push_back(m_player);
        initUI();
    }

    void Centiped::initUI()
    {
        m_objList.push_back(new Text(std::make_pair(1000, 100), "text_restart", "Press R to restart the game."));
        m_textScore = new Text(std::make_pair(1000, 200), "text_score", m_username + ", your score is 0.");
        m_objList.push_back(m_textScore);
        m_textBestScore = new Text(std::make_pair(1000, 300), "text_best_score", "No best score saved.");
        m_objList.push_back(m_textBestScore);

    }


    void Centiped::InitPlayerLimits(uint topLimit)
    {
        m_player->setTopLimit(topLimit * 32);
        m_player->setBotLimit(m_level.size() * 32);
        m_player->setRightLimit((m_level[0].size() - 1) * 32);
        m_player->setLeftLimit(0 * 32);
    }




 void Centiped::loadScore()
    {
        std::string username = "";
        std::string score = "";
        std::ifstream file("./games/centiped/assets/score");

        if (!file) {
            m_textBestScore->setValue("No best score saved.");
            return;
        }
        getline(file, username);
        getline(file, score);
        m_textBestScore->setValue(username + " has the best score, with " + score + " targets destroyed.");
        m_bestScore = std::stoi(score);
    }



    void Centiped::saveScore()
    {
        std::ofstream outfile ("./games/centiped/assets/score");

        outfile << m_username << std::endl << m_destroyedMushroom << std::endl;
        outfile.close();
    }

    void Centiped::gameFinished()
    {
        if ((m_player->getToClear() == true || m_leftMushroom == 0) && m_finished == false) {
            m_finished = true;
            if (m_destroyedMushroom > m_bestScore)
                saveScore();
        }
    }



    extern "C" {
        IGameInterface *entryPoint()
        {
            return new Centiped;
        }
    }
}