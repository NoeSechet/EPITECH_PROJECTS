/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreMenu
*/

#ifndef COREMENU_HPP_
#define COREMENU_HPP_

#include <fstream>
#include <iostream>
#include <tuple>
#include <memory>

#include "../../games/IGameInterface.hpp"
#include "../../lib/IGraphicalInterface.hpp"
#include "MenuButton.hpp"

#include "../include/LibraryManagor.hpp"

namespace games {

    class CoreMenu : public games::IGameInterface
    {
        private:
            std::string m_defaultLibPath = "";
            LibraryManagor &m_libManager;
            std::vector<menu::MenuElem *> m_graphButtonList;
            std::vector<menu::MenuElem *> m_gameButtonList;

            std::vector<IObjectToDraw *> m_objects;

            std::pair<uint, uint> m_levelSize = {0,0};
            int m_graphButtonIte = 0;
            int m_gameButtonIte = 0;

        public:
            CoreMenu(const std::string &defaultLibPath, LibraryManagor &libManager);
            ~CoreMenu();

            // -- Interface functions
            void setUsername(std::string username) { (void)username; };
            bool start();
            bool end();
            std::vector<IObjectToDraw *> getAssets() const;
            COMMAND applyInput (COMMAND userInput);
            std::vector<IObjectToDraw *> compute();
            // --

            const std::string GetSelectedGameLib() const {
                return m_gameButtonList[m_gameButtonIte]->getLibPath();
            }

        private:
            void LoadButtonFromInfoFile();
            void LoadClassFromChar(char c, long int x, long int y);
            void SetButtonSelection(std::vector<menu::MenuElem *> &chosenList, int &chosenIte);
            void MoveSelection(std::vector<menu::MenuElem *> &chosenList, int &chosenIte, int selDir);

    };

}
#endif /* !COREMENU_HPP_ */
