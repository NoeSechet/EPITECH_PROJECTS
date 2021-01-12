/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MenuElem
*/

#ifndef MENUBUTTON_HPP_
#define MENUBUTTON_HPP_

#include "../../GlobalHeaders.hpp"

namespace menu {

    class MenuElem : public IObjectToDraw
    {
        private:
            std::pair<long int, long int> m_coord = {0,0};
            std::string m_id = "";
            std::string m_assetPath = "";
            std::tuple<uint, uint, uint, uint> m_sprPos = {0,0,200,100};
            bool m_selected = false;
            const std::string m_LibPath = "";
            std::tuple<uint, uint, uint, uint> m_color = {255,255,255,255};

        public:
            MenuElem(std::pair<uint, uint> coord, std::string id, std::string assetPath = "", const std::string LibPath = "")
                : m_coord(coord), m_id(id), m_assetPath(assetPath), m_LibPath(LibPath) {}
            ~MenuElem() {}

            virtual std::string getId() const { return m_id; }
            void setId(std::string id) { m_id = id; };
            std::string getPath() const { return m_assetPath; }
            virtual Type getType() const { return objects; }
            virtual std::string getValue() const { return "val"; }
            std::pair<long int, long int> getCoords() const { return m_coord; }
            std::tuple<uint, uint, uint, uint> getSpritePos() const { return m_sprPos; }
            std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }

            bool isSelected() const { return m_selected; }
            void SetSelected(bool selected) { m_selected = selected; }
            void setColor(std::tuple<uint,uint,uint,uint> color) { m_color = color; }
            const std::string getLibPath() const { return m_LibPath; }

    };


    class Text : public MenuElem {

        private:
        std::string m_value = "debug";
        public:
            Text(std::pair<uint, uint> coord, std::string id,std::string value = "", std::string assetPath = "./games/solar_fox/assets/font/", const std::string LibPath = "")
                : MenuElem(coord, id, assetPath, LibPath) {
                    m_value = value;
                }
            ~Text() {}

            Type getType() const { return text; }
            std::string getValue() const { return m_value; }

    };

}

#endif /* !MENUBUTTON_HPP_ */
