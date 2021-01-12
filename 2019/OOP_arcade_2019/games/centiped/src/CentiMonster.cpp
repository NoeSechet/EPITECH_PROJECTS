/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiElem
*/

#include "Monster.hpp"

namespace games
{

    Monster::Monster(std::pair<uint,uint> coord, std::string id, std::string path, std::tuple<uint,uint,uint,uint> sprPos)
            : CentiElem(coord, id, path, sprPos)
        {
            m_RNGGenerator.seed(randValue);
            m_moveTimer.startTimer();
        }

    void Monster::move(std::vector <IObjectToDraw *> &listObj)
    {
        if (m_moveTimer.getElapsedSeconds() < 0.4)
            return;
        m_moveTimer.restartTimer();

        std::uniform_int_distribution<uint32_t> rand01(0, 1);
        u_int32_t rn = rand01(m_RNGGenerator);

        for (auto &obj : listObj) {
            if (obj == this)
                continue;
            if (static_cast <CentiElem *> (obj)->getCoords().first == m_coord.first &&
            static_cast <CentiElem *> (obj)->getCoords().second - 32 == m_coord.second &&
            obj->getId().compare("mushroom") == 0) {
                if (rn == 0)
                    m_coord.first += 32;
                else
                    m_coord.first -= 32;

                return;
            }
        }
        m_coord.second += 32;

    };

    void Monster::collision(std::vector <IObjectToDraw *> &listObj)
    {
        for (size_t i = 0; i < listObj.size(); i++) {
            if (listObj[i] == this)
                continue;
            if (static_cast <CentiElem *> (listObj[i])->getCoords().first == m_coord.first &&
            static_cast <CentiElem *> (listObj[i])->getCoords().second == m_coord.second) {
                if (listObj[i]->getId().compare("player") == 0)
                    static_cast <CentiElem *> (listObj[i])->setToClear(true);
            }
        }
    }

}