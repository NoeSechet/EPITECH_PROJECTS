/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AssetSFML
*/

#ifndef ASSETSFML_HPP_
#define ASSETSFML_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "../../../GlobalHeaders.hpp"

class AssetSFML : public IObjectToDraw {
    private:
        std::string m_id;
        Type m_type = objects;
        std::string m_value = "";
        std::shared_ptr<sf::Sprite> m_sprite = nullptr;
        std::shared_ptr<sf::Texture> m_tex = nullptr;
        sf::Vector2u m_texSize = { 0, 0 };
        std::pair<long int, long int> m_coord = { 0,0 };
        std::tuple<uint, uint, uint, uint> m_spriPos = {0,0,32,32};
        std::tuple<uint, uint, uint, uint> m_color = {255,255,255,255};
        // Arnaud for text
        sf::Font m_font;
        sf::Text *m_text = nullptr;

    public:
        AssetSFML(const std::string &id, Type type, std::string path, std::tuple<uint, uint, uint, uint> sprRec);
        ~AssetSFML();

        sf::Text* getText() const { return m_text; }

        // -- Interface Functions
        std::string getId() const { return m_id; };
        std::string getPath() const { return std::string(""); };
        Type getType() const {return m_type; };
        std::string getValue() const { return m_value; };
        std::pair<long int, long int> getCoords() const { return m_coord; };
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return m_spriPos; }
        std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }
        // --

        std::shared_ptr<sf::Sprite> getSprite() { return m_sprite; }

};

#endif /* !ASSETSFML_HPP_ */