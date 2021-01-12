/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiPlayer
*/

#ifndef CENTIPLAYER_HPP_
#define CENTIPLAYER_HPP_

#include "CentiElem.hpp"

namespace games {

    class CentiPlayer : public CentiElem {
        private:
            Timer m_shotTimer;
            uint m_TopLimit = 0;
            uint m_BotLimit = 0;
            uint m_RightLimit = 0;
            uint m_LeftLimit = 0;

        public:
            CentiPlayer(
                std::pair<uint,uint> coord,
                std::string id = "player", std::string path = "",
                std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32});
            ~CentiPlayer();

            void MoveUp();
            void MoveDown();
            void MoveLeft();
            void MoveRight();
            void Shot(std::vector <IObjectToDraw *> &bobject);
            
            void setTopLimit(uint limit) { m_TopLimit = limit; }
            void setBotLimit(uint limit) { m_BotLimit = limit; }
            void setRightLimit(uint limit) { m_RightLimit = limit; }
            void setLeftLimit(uint limit) { m_LeftLimit = limit; }


        private:

        protected:
    };

}

#endif /* !CENTIPLAYER_HPP_ */
