/*
** EPITECH PROJECT, 2020
** GRAPHIC_NCURSES
** File description:
** GRAPHIC_NCURSES
*/

#include "../include/Graphic_ncurses.hpp"

#include <ncurses.h>
#include <iostream>
#include <fstream>

namespace graphical {

    Graphic_ncurses::Graphic_ncurses()
        : m_name("ncurses")
    {
        init();
    }

    Graphic_ncurses::~Graphic_ncurses()
    {}

    bool Graphic_ncurses::init()
    {
        if (initscr() == nullptr) return false;
        curs_set(0);
        noecho();
        nodelay(stdscr, true);
        keypad(stdscr, true);
        if (has_colors())
            start_color();
        return true;
    }

    bool Graphic_ncurses::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        std::tuple<uint,uint,uint,uint> assetSizeDefault = {0,0,0,0};
        std::string value = "";

        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset))
                continue;

            if (asset->getType() == IObjectToDraw::text) {
                m_assetList.push_back(new AssetNcurses(asset->getId(), asset->getType(), asset->getValue(), assetSizeDefault));
            }
            else { 
                if (!asset->getPath().empty()) {
                    std::tuple<uint,uint,uint,uint> assetSize = {0,0,0,0};
                    if (asset->getPath()[asset->getPath().size()-1] == '/') {
                        value = getFileContent(asset->getPath() + "terminal.txt",
                            std::get<2>(assetSize), std::get<3>(assetSize)
                        );
                    } else {
                    value = getFileContent(asset->getPath() + "/terminal.txt",
                            std::get<2>(assetSize), std::get<3>(assetSize)
                        );
                    }
                    m_assetList.push_back(new AssetNcurses(asset->getId(), asset->getType(),
                        value, assetSize));
                    value = "";
                }

            }
        }
        return true;
    }

    bool Graphic_ncurses::destroyAssets()
    {
        m_assetList.clear();
        return true;
    }

    bool Graphic_ncurses::destroy()
    {
        erase();
        endwin();
        return true;
    }

    COMMAND Graphic_ncurses::getInput()
    {
        switch (getch()) {
            case KEY_UP: return UP;
            case KEY_RIGHT: return RIGHT;
            case KEY_DOWN: return DOWN;
            case KEY_LEFT: return LEFT;
            case ' ': return ACTION;
            case 'r': return RESTART;
            case 'q': return PREV_GRAPH;
            case 'e': return NEXT_GRAPH;
            case 'a': return PREV_GAME;
            case 'd': return NEXT_GAME;
            case KEY_BACKSPACE: return EXIT;
            default: return NO_INPUT;
        }
    }

    bool Graphic_ncurses::draw(std::vector<IObjectToDraw *> objects)
    {
        AssetNcurses *assetPtr = nullptr;

        erase();
        for (auto &obj : objects) {
            if (obj->getType() == IObjectToDraw::text) { // Text
                move(obj->getCoords().second / 32, obj->getCoords().first / 32);
                printw("%s", obj->getValue().c_str());
                continue;
            }
            if ((assetPtr = getObjectAsset(obj)) == nullptr)
                throw std::logic_error("could not find corresponding asset");
            PrintAsset(*assetPtr,
                obj->getCoords().first / 32, // Based on sfml
                obj->getCoords().second / 32,
                obj->getColor()
            );
        }
        refresh();

        return true;
    }

    void Graphic_ncurses::PrintAsset(AssetNcurses &asset, uint x_coord, uint y_coord, std::tuple<uint,uint,uint,uint> color)
    {
        std::string val = asset.getValue();
        size_t x_size = std::get<2>(asset.getSpritePos());
        size_t y_size = std::get<3>(asset.getSpritePos());
        size_t i = 0;
        std::vector<std::string> blockList;

        if (std::get<3>(color) != 255)
            TurnOnHighlight();

        for (size_t ite = 0; ite < y_size; ite += 1)
        {
            blockList.push_back(val.substr(0, x_size));
            val = val.substr(x_size, val.size());
        }
        for (size_t k = 0; k < y_size; k += 1)
        {
            mvprintw(y_coord - (y_size/2) + k, x_coord - (x_size/2), blockList[k].c_str());
            i += 1;
        }
        TurnOffHighlight();
    }

    void Graphic_ncurses::TurnOnHighlight()
    {
        if (has_colors()) {
            init_pair(1, COLOR_BLUE, COLOR_WHITE);
            attron(COLOR_PAIR(1));
        } else {
            attron(A_STANDOUT);
        }
    }

    void Graphic_ncurses::TurnOffHighlight()
    {
        if (has_colors()) {
            attroff(COLOR_PAIR(1));
        } else {
            attroff(A_STANDOUT);
        }
    }

    std::string Graphic_ncurses::getFileContent(std::string path, uint &x_size, uint &y_size)
    {
        std::string input = "";
        std::ifstream File(path);
        std::string content = "";

        if (!File)
            throw std::logic_error("NCurses library : Could not get the file content, path: " + path);

        while (getline(File, input)) {
            input.size() > x_size ? x_size = input.size() : 0;
            content.append(input);
            y_size += 1;
        }
        File.close();
        return content;
    }

    bool Graphic_ncurses::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &a : m_assetList) {
            if (object->getId().compare(a->getId()) == 0) {
                return true;
            }
        }
        return false;
    }

    AssetNcurses *Graphic_ncurses::getObjectAsset(IObjectToDraw *obj)
    {
        for (auto &a : m_assetList) {
            if (obj->getId().compare(a->getId()) == 0)
                return a;
        }
        throw std::logic_error(obj->getId());
        return nullptr;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_ncurses;
        }
    }

}