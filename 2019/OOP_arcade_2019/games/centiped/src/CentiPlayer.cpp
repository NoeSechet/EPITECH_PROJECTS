/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiPlayer
*/

#include <iostream>

#include "CentiPlayer.hpp"

namespace games
{

    CentiPlayer::CentiPlayer(
        std::pair<uint,uint> coord,
        std::string id,
        std::string path,
        std::tuple<uint,uint,uint,uint> sprPos
    )
        : CentiElem(coord, id, path, sprPos)
    {
        m_shotTimer.startTimer();
    }

    CentiPlayer::~CentiPlayer()
    {}

    void CentiPlayer::MoveUp()
    {
        if (m_coord.second - 32 > m_TopLimit)
            m_coord.second -= 32;
    }

    void CentiPlayer::MoveDown()
    {
        if (m_coord.second + 32 < m_BotLimit)
            m_coord.second += 32;
    }

    void CentiPlayer::MoveLeft()
    {
        if (m_coord.first - 32 > m_LeftLimit)
            m_coord.first -= 32;
    }

    void CentiPlayer::MoveRight()
    {
        if (m_coord.first + 32 < m_RightLimit)
            m_coord.first += 32;
    }

    void CentiPlayer::Shot(std::vector <IObjectToDraw *> &object)
    {
        std::pair<long int, long int> newCoord = m_coord;
    
        if (m_shotTimer.getElapsedSeconds() < 1) return;
        m_shotTimer.restartTimer();
        newCoord.second -= 32;
        object.push_back(new Lazer(newCoord));
    }

}