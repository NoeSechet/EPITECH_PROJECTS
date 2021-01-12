/*
** EPITECH PROJECT, 2020
** MONSTER
** File description:
** MONSTER
*/

#ifndef MONSTER
#define MONSTER

#include <random>

#include "CentiElem.hpp"
#include "CentiPlayer.hpp"

namespace games {

    class Monster : public CentiElem
    {
    private:
        Timer m_moveTimer;
        u_int32_t randValue = 0;
        std::mt19937 m_RNGGenerator;

    public:
        Monster(std::pair<uint,uint> coord, std::string id = "monster",
            std::string path = "./games/centiped/assets/monster/", std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32});
        ~Monster()
        {}

        void move(std::vector <IObjectToDraw *> &object);
        void collision(std::vector <IObjectToDraw *> &object);
    };
}

#endif /* !MONSTER */
