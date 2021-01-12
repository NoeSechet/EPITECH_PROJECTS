/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graphic_sfml
*/

#ifndef GRAPHIC_SFML_HPP_
#define GRAPHIC_SFML_HPP_

#include <unistd.h>
#include <sys/stat.h>
#include <iostream>

#include "IGraphicalInterface.hpp"
#include "AssetSFML.hpp"

namespace graphical {

    class Graphic_sfml : public IGraphicalInterface {
        private:
            std::string m_name = "";
            std::pair<uint, uint> m_winSize = {1920,1080};
            std::vector<AssetSFML *> m_assetList;

            COMMAND m_command = NO_INPUT;
            sf::RenderWindow m_window;
            sf::Event m_event;

        public:
            Graphic_sfml();
            ~Graphic_sfml();

            bool init();
            bool initAssets(std::vector<IObjectToDraw *> assets);
            bool destroyAssets();
            bool destroy();
            COMMAND getInput();
            bool draw(std::vector<IObjectToDraw *> objects);

            std::string GetName() const { return m_name; }

        private:
            bool InitWindow(uint width = 1920, uint height = 1080);
            AssetSFML *getObjectContent(IObjectToDraw *object) const;
            bool isAlreadyLoaded(IObjectToDraw *object) const;
            bool CheckAssetPath(std::string path);

    };

}

#endif /* !GRAPHIC_SFML_HPP_ */
