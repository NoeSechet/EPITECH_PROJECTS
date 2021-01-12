/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <unistd.h>

#include "../include/DLLoader.hpp"
#include "../../lib/IGraphicalInterface.hpp"
#include "../../games/IGameInterface.hpp"

#include "../coremenu/CoreMenu.hpp"

class Core {
        LibraryManagor *m_libManager = nullptr;
        std::string m_userName = "";

        void *m_graphLibHand = nullptr;
        void *m_gameLibHand = nullptr;

        std::vector<games::IGameInterface *> m_listLoadedGame;

        graphical::IGraphicalInterface *m_graphLib = nullptr;
        games::IGameInterface *m_gameLib = nullptr;

        COMMAND m_input = NO_INPUT;
        COMMAND m_step = NO_INPUT;

        games::CoreMenu *m_coreMenu = nullptr;

    public:
        Core(const std::string &defaultLib, std::string userName);
        ~Core();

        int loop();

    private:
        int CheckLibName(const std::string &libName);

        int ChangeGraphLib(std::string libPath);
        int ChangeGameLib(std::string libPath);
        bool LoadGameLib(const std::string libPath);
        bool LoadGraphLib(const std::string libPath);
        bool UnloadGameLib();
        bool UnloadGraphLib();
};

#endif /* !CORE_HPP_ */
