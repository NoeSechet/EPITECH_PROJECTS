/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sfml
*/

#include "Graphic_sfml.hpp"

namespace graphical {

    Graphic_sfml::Graphic_sfml()
        : m_name("sfml"), m_winSize(std::make_pair<uint, uint>(0, 0))
    {
        init();
    }

    Graphic_sfml::~Graphic_sfml()
    {
        std::cout << "Terminated sfml lib" << std::endl;
    }

    bool Graphic_sfml::init()
    {
        std::cout << "Initialized sfml lib" << std::endl;

        return true;
    }

    bool Graphic_sfml::InitWindow(uint width, uint height)
    {
        m_window.create(sf::VideoMode(width, height), "sfml window");
        m_window.setFramerateLimit(30);
        m_window.setKeyRepeatEnabled(false);

        return true;
    }

    // Si le type de l'asset == text, il faut créer un text, avec la value de l'asset.
    bool Graphic_sfml::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset))
                continue;
            if (asset->getType() == IObjectToDraw::text) {
                m_assetList.push_back(new AssetSFML(asset->getId(),asset->getType(),asset->getPath(),asset->getSpritePos()));
            }
            if (CheckAssetPath(asset->getPath()) == true) {
                m_assetList.push_back(new AssetSFML(asset->getId(),asset->getType(),asset->getPath(),asset->getSpritePos()));
            }
        }
        InitWindow();
        return true;
    }

    bool Graphic_sfml::destroyAssets()
    {
        return true;
    }

    bool Graphic_sfml::destroy()
    {
        return true;
    }

    COMMAND Graphic_sfml::getInput()
    {
        while (m_window.pollEvent(m_event)) {
            if (m_event.type == sf::Event::Closed)
               return EXIT;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) return UP;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) return DOWN;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) return LEFT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) return RIGHT;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) return ACTION;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) return RESTART;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) return PREV_GRAPH;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) return NEXT_GRAPH;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) return PREV_GAME;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) return NEXT_GAME;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace)) return EXIT;
        return NO_INPUT;
    }

    // Si l'objet est un text, il faut update le text de la value, et le draw à la bonne position.
    bool Graphic_sfml::draw(std::vector<IObjectToDraw *> objectList)
    {
        m_window.clear();
        AssetSFML *assetPtr = nullptr;
        std::shared_ptr<sf::Sprite> spritePtr = nullptr;
        std::pair<uint, uint> objCoord = {0,0};

        for (auto &obj : objectList)
        {
            // std::cout << "coord: " << obj->getCoords().first << " " << obj->getCoords().second << std::endl;
            if ((assetPtr = getObjectContent(obj)) == nullptr) {
                // std::cout << "Asset not found:" << obj->getId() << std::endl;
                continue;
            }
            if (assetPtr->getType() == IObjectToDraw::text) {
                assetPtr->getText()->setPosition(obj->getCoords().first, obj->getCoords().second);
                assetPtr->getText()->setString(obj->getValue());
                m_window.draw(*assetPtr->getText());
                continue;
            }
            if ((spritePtr = assetPtr->getSprite()) == nullptr) {
                // std::cout << "Sprite not found:" << obj->getId() << std::endl;
                continue;
            }

            std::tuple<uint,uint,uint,uint> color = obj->getColor();

            spritePtr->setColor(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color), std::get<3>(color)));

            objCoord = obj->getCoords();
            spritePtr->setPosition(
                objCoord.first - std::get<2>(assetPtr->getSpritePos()) / 2,
                objCoord.second - std::get<3>(assetPtr->getSpritePos()) / 2
            );
            m_window.draw(*spritePtr);
        }
        m_window.display();
        return true;
    }

    bool Graphic_sfml::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &asset : m_assetList) {
            if (object->getId().compare(asset->getId()) == 0) {
                return true;
            }
        }
        return false;
    }

    AssetSFML *Graphic_sfml::getObjectContent(IObjectToDraw *object) const
    {
        // std::cout << object->getId() << std::endl;
        for (auto asset : m_assetList) {
            if (object->getId().compare(asset->getId()) == 0) {
                return asset;
            }
        }
        return nullptr;
    }

    bool Graphic_sfml::CheckAssetPath(std::string path)
    {
        struct stat buffer;

        if (path[path.size() - 1] != '/')
            path.append("/");

        if (stat (path.append("texture.png").c_str(), &buffer) == 0) {
            return true;
        }
        return false;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_sfml();
        }
    }

}
