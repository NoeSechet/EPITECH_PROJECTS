/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AssetSFML
*/

#include "AssetSFML.hpp"

AssetSFML::AssetSFML(const std::string &id, Type type, std::string path, std::tuple<uint, uint, uint, uint> sprRec)
    : m_id(id), m_type(type), m_tex(std::make_shared<sf::Texture>()), m_spriPos(sprRec)
{
    if (path[path.size() - 1] != '/')
            path.append("/");
        if (type == text) {
            if (!m_font.loadFromFile(path + "font.ttf"))
                throw std::logic_error("Font not found. Maybe the given path is invalid");
            m_text = new sf::Text();
            m_text->setFont(m_font);
            m_text->setString(getValue());
            m_text->setCharacterSize(24);
            return;
        }
        if (!m_tex->loadFromFile(path + "texture.png"))
            throw std::logic_error("Texture not found. Maybe the given path is invalid");
        m_sprite = std::make_shared<sf::Sprite>(
                    *m_tex,
                    sf::IntRect(std::get<0>(sprRec),
                                std::get<1>(sprRec),
                                std::get<2>(sprRec),
                                std::get<3>(sprRec))
                );
        m_texSize = m_tex->getSize();
}

AssetSFML::~AssetSFML()
{
}
