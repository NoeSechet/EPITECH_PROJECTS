/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreMenu
*/

#include "CoreMenu.hpp"

namespace games {

    CoreMenu::CoreMenu(const std::string &defaultLibPath, LibraryManagor &libManager)
        : m_defaultLibPath(defaultLibPath), m_libManager(libManager)
    {
        start();
    }

    CoreMenu::~CoreMenu() {}

    void CoreMenu::LoadButtonFromInfoFile()
    {
        uint x_coordGraphElem = 1920 / 3 * 1;
        uint y_coordGraphElem = 400;
        uint x_coordGameElem = 1920 / 3 * 2;
        uint y_coordGameElem = 400;
        menu::MenuElem *elemHolder = nullptr;

        m_objects.push_back(new menu::MenuElem({1920 / 2, 200}, "arcade"));

        for (auto &ite : m_libManager.GetGraphicalLibraryInformation())
        {
            elemHolder = new menu::MenuElem({x_coordGraphElem, y_coordGraphElem}, ite.m_name, "", ite.m_path);
            m_graphButtonList.push_back(elemHolder);
            m_objects.push_back(elemHolder);
            y_coordGraphElem += 200;
        }
        for (auto &ite : m_libManager.GetGameLibraryInformation())
        {
            elemHolder = new menu::MenuElem({x_coordGameElem, y_coordGameElem}, ite.m_name, "", ite.m_path);
            m_gameButtonList.push_back(elemHolder);
            m_objects.push_back(elemHolder);
            y_coordGameElem += 200;
        }
    }

    bool CoreMenu::start()
    {
        LoadButtonFromInfoFile();

        SetButtonSelection(m_graphButtonList, m_graphButtonIte);
        SetButtonSelection(m_gameButtonList, m_gameButtonIte);


        m_objects.push_back(new menu::Text(std::make_pair(1 * 32, 1 * 32), "text_graph", "Press E or Q to change graphical library."));
        m_objects.push_back(new menu::Text(std::make_pair(1 * 32, 2 * 32), "text_game", "Press (A or D)/(Key arrows) to change game library."));
        m_objects.push_back(new menu::Text(std::make_pair(1 * 32, 3 * 32), "text_action", "Space bar is the action button."));
        return true;
    }

    bool CoreMenu::end()
    {
        return true;
    }

    std::vector<IObjectToDraw *> CoreMenu::getAssets() const
    {
        std::vector <IObjectToDraw *> assets;
        std::pair <long int, long int> d_coord = {0,0};

        assets.push_back(new menu::MenuElem(d_coord, "arcade", "./core/coremenu/assets/arcadebutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "solarfox", "./core/coremenu/assets/solarfoxbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "centiped", "./core/coremenu/assets/centipedbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "qix", "./core/coremenu/assets/qixbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "pacman", "./core/coremenu/assets/pacmanbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "nibbler", "./core/coremenu/assets/nibblerbutton/"));

        assets.push_back(new menu::MenuElem(d_coord, "ncurses", "./core/coremenu/assets/ncursesbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "sfml", "./core/coremenu/assets/sfmlbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "sdl", "./core/coremenu/assets/sdlbutton/"));
        assets.push_back(new menu::MenuElem(d_coord, "border", "./games/solar_fox/assets/border/"));

        assets.push_back(new menu::Text(d_coord, "text_graph"));
        assets.push_back(new menu::Text(d_coord, "text_game"));
        assets.push_back(new menu::Text(d_coord, "text_action"));

        return assets;
    }

    COMMAND CoreMenu::applyInput(COMMAND userInput)
    {
        (void)userInput;

        switch (userInput) {
            case DOWN: MoveSelection(m_gameButtonList, m_gameButtonIte, 1); break;
            case RIGHT: MoveSelection(m_gameButtonList, m_gameButtonIte, 1); break;
            case UP: MoveSelection(m_gameButtonList, m_gameButtonIte, -1); break;
            case LEFT: MoveSelection(m_gameButtonList, m_gameButtonIte, -1); break;
            case PREV_GRAPH: MoveSelection(m_graphButtonList, m_graphButtonIte, -1); break;
            case NEXT_GRAPH: MoveSelection(m_graphButtonList, m_graphButtonIte, 1); break;
            case ACTION: return GAME; break;
            default: break;
        }

        return userInput;
    }

    void CoreMenu::MoveSelection(std::vector<menu::MenuElem *> &chosenList, int &chosenIte, int selDir)
    {
        if ((size_t)chosenIte > chosenList.size()) {
            std::cerr << "list iterator out of range! MoveSelection() function" << std::endl;
            return;
        }

        menu::MenuElem *button = chosenList[chosenIte];

        if (button == nullptr)
            throw std::exception();

        if (button->isSelected() == false)
            return;

        if (!(chosenIte + selDir < 0) && !(chosenIte + selDir > (int)chosenList.size() - 1))
            chosenIte += selDir;

        button->SetSelected(false);
        button->setColor(std::make_tuple<uint,uint,uint,uint>(255, 255, 255, 255));
        button = chosenList[chosenIte];
        button->SetSelected(true);
        button->setColor(std::make_tuple<uint,uint,uint,uint>(255, 150, 150, 150));
    }

    void CoreMenu::SetButtonSelection(std::vector<menu::MenuElem *> &chosenList, int &chosenIte)
    {
        if (chosenList.size() <= 0) {
            std::cerr << "Invalid list size! SetButtonSelection() function" << std::endl;
            return;
        }
        for (auto &ite : chosenList)
        {
            if (ite->getLibPath().compare(m_defaultLibPath) == 0)
            {
                ite->SetSelected(true);
                ite->setColor(std::make_tuple<uint,uint,uint,uint>(255, 150, 150, 150));
                return;
            }
            chosenIte += 1;
        }
        menu::MenuElem &obj = *chosenList[0];
        obj.SetSelected(true);
        obj.setColor(std::make_tuple<uint,uint,uint,uint>(255, 150, 150, 150));
        chosenIte = 0;
        return;
    }

    std::vector<IObjectToDraw *> CoreMenu::compute()
    {
        return m_objects;
    }

}