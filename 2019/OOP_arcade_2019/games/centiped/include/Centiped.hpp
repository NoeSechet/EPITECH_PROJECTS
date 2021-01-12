/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centiped
*/

#ifndef CENTIPED_HPP_
#define CENTIPED_HPP_

#include <iostream>
#include <random>

#include "IGameInterface.hpp"

#include "CentiElem.hpp"
#include "CentiPlayer.hpp"

namespace games
{

    class Centiped : public IGameInterface
    {
        private:
            Timer m_spawnMonsterTimer;
            bool m_finished = false;
            Text *m_textScore = nullptr;
            Text *m_textBestScore = nullptr;
            std::vector <IObjectToDraw *> m_objList;
            std::string m_username = "";
            CentiPlayer *m_player = nullptr;
            std::vector<std::vector<char>> m_level;
            int m_totalMushroom = 0;
            int m_leftMushroom = 0;
            int m_destroyedMushroom = 0;
            int m_bestScore = 0;

        public:
            Centiped();
            ~Centiped();

            void setUsername(std::string username) { m_username = username; };
            bool start();
            bool end();
            std::vector <IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector <IObjectToDraw *> compute();
            void clearMemory(std::vector <IObjectToDraw *> &objects);
            void restart();
            void spawnMonster();
            void updateMushroomleft(CentiElem * object);
            void initUI();
            void updateUI();
             void loadScore();
             void gameFinished();
             void saveScore();

        private:
            void LoadLevel();
            void InitPlayerLimits(uint topLimit);

    };

}

#endif /* !CENTIPED_HPP_ */