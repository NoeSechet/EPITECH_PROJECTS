/*
** EPITECH PROJECT, 2020
** SOLAR_FOX
** File description:
** SOLAR_FOX
*/

#ifndef SOLAR_FOX
#define SOLAR_FOX

#include "IGameInterface.hpp"
#include "Entities.hpp"

namespace games {

    class SolarFox : public IGameInterface {
        private:
            std::vector <IObjectToDraw *> m_objectToDraw;
            Player *m_player = nullptr;
            Text *m_scoreText = nullptr;
            Text *m_scoreBestText = nullptr;
            Text *m_endText = nullptr;
            std::string m_username = "";
            int m_bestScore = 0;
            int m_totalTarget = 0;
            int m_leftTarget = 0;
            int m_destroyedTarget = 0;
            bool m_finished = false;
        public:
            SolarFox();
            ~SolarFox();
            void setUsername(std::string username);
            bool start();
            void restart();
            bool end();
            void gameFinished();
            std::vector <IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector <IObjectToDraw *> compute();
            void loadClassFromChar(char c, long int x, long int y);
            void loadLevel();
            void loadScore();
            void saveScore();
            void clearMemory(std::vector <IObjectToDraw *> &objects);
            bool isPlayer(std::string id) const;
            void increaseTargetleft(Entity * object);
            void updateUI();
    };

}

#endif /* !SOLAR_FOX */