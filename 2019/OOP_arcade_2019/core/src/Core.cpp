/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"
#include "../../games/IGameInterface.hpp"// tmp

Core::Core(const std::string &defaultLibPath, std::string userName)
    : m_libManager(new LibraryManagor)
{
    m_userName = userName;
    if (!m_libManager || CheckLibName(defaultLibPath) == -1)
        throw std::logic_error("Argument line: invalid library name");
    LoadGraphLib(defaultLibPath);
    m_coreMenu = new games::CoreMenu(defaultLibPath, *m_libManager);
    m_step = MAIN_MENU;
    m_gameLib = m_coreMenu;
    m_graphLib->initAssets((m_gameLib->getAssets()));
}

Core::~Core()
{
    if (m_libManager != nullptr)
        delete m_libManager;
    if (m_coreMenu != nullptr)
        delete m_coreMenu;
    if (m_graphLib != nullptr)
        delete m_graphLib;
    m_graphLib = nullptr;
    // if (m_gameLib != nullptr)
    //     delete m_gameLib;
    // m_gameLib = nullptr;
    if (m_graphLibHand)
        DLLoader<graphical::IGraphicalInterface>::UnloadLib(m_graphLibHand);
    if (m_gameLibHand)
        DLLoader<games::IGameInterface>::UnloadLib(m_gameLibHand);
}

int Core::CheckLibName(const std::string &defaultLibPath)
{
    int i = 0;

    for (auto ite : m_libManager->GetGraphicalLibraryInformation()) {
        if (defaultLibPath.compare(ite.m_path) == 0) {
            m_libManager->SetGraphLibIte(i);
            return 1;
        }
        i += 1;
    }
    return -1;
}

int Core::loop()
{
    COMMAND inputRes = MAIN_MENU;

    while (1)
    {
        m_input = m_graphLib->getInput();
        inputRes = m_gameLib->applyInput(m_input);

        if (inputRes == EXIT && m_gameLib == m_coreMenu)
            return 0;

        switch (m_input) {
            case PREV_GRAPH: ChangeGraphLib(m_libManager->GetPrevGraphLib().m_path); continue;
            case NEXT_GRAPH: ChangeGraphLib(m_libManager->GetNextGraphLib().m_path); continue;
            case PREV_GAME: ChangeGameLib(m_libManager->GetPrevGameLib().m_path); continue;
            case NEXT_GAME: ChangeGameLib(m_libManager->GetNextGameLib().m_path); continue;
            default: break;
        }
        switch (inputRes) {
            case GAME: LoadGameLib(m_coreMenu->GetSelectedGameLib()); m_step = GAME; continue;
            case MAIN_MENU: UnloadGameLib(); m_gameLib = m_coreMenu; continue;
            default: break;
        }
        m_graphLib->draw(
            m_gameLib->compute()
        );
    }
    return 1;
}

int Core::ChangeGraphLib(std::string libPath)
{
    UnloadGraphLib();
    LoadGraphLib(libPath);

    m_graphLib->initAssets((m_gameLib->getAssets()));
    return 1;
}

int Core::ChangeGameLib(std::string libPath)
{
    if (m_gameLib != m_coreMenu) {
        UnloadGameLib();
        LoadGameLib(libPath);
    }
    return 1;
}

bool Core::LoadGameLib(const std::string libPath)
{
    m_gameLibHand = DLLoader<games::IGameInterface>::LoadLib(libPath);
    m_gameLib = DLLoader<games::IGameInterface>::GetInstance(m_gameLibHand);
    if (m_gameLib == nullptr) {
        throw std::logic_error("The game lib couldn't be loaded\nLibpath: " + libPath);
    }
    m_gameLib->setUsername(m_userName);
    m_gameLib->start();
    m_graphLib->initAssets((m_gameLib->getAssets()));

    return true;
}

bool Core::LoadGraphLib(const std::string libPath)
{
    // std::cout << "Loading game... libPath: " << libPath << std::endl;
    m_graphLibHand = DLLoader<graphical::IGraphicalInterface>::LoadLib(libPath);
    m_graphLib = DLLoader<graphical::IGraphicalInterface>::GetInstance(m_graphLibHand);
    if (m_graphLib == nullptr) {
        throw std::logic_error("The graph lib couldn't be loaded\nLibpath: " + libPath);
    }
    return true;
}

bool Core::UnloadGameLib()
{
    m_gameLib = nullptr;
    DLLoader<graphical::IGraphicalInterface>::UnloadLib(m_gameLibHand);
    return true;
}

bool Core::UnloadGraphLib()
{
    if (m_graphLib != nullptr) {
        delete m_graphLib;
        m_graphLib = nullptr;
    }
    DLLoader<graphical::IGraphicalInterface>::UnloadLib(m_graphLibHand);
    return true;
}