/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiElem
*/

#ifndef CENTIELEM_HPP_
#define CENTIELEM_HPP_

#include "GlobalHeaders.hpp"
#include <vector>
#include "Timer.hpp"

namespace games
{

    class CentiElem : public IObjectToDraw
    {
        private:
        protected:
            bool m_toClear = false;
            std::pair<long int, long int> m_coord;
            std::string m_id = "";
            std::string m_path = "";
            Type m_type = objects;
            std::string m_val = "";
            std::tuple <uint, uint, uint, uint> m_sprPos;
            std::tuple <uint, uint, uint, uint> m_color = {255,255,255,255};

        public:
            CentiElem(std::pair<uint,uint> coord, std::string id, std::string path, std::tuple<uint,uint,uint,uint> sprPos)
                : m_coord(coord), m_id(id), m_path(path), m_sprPos(sprPos)
            {}
            ~CentiElem()
            {}

            std::string getId() const { return m_id; }
            std::string getPath() const { return m_path; }
            Type getType() const { return m_type; }
            std::string getValue() const { return m_val; }
            std::pair<long int, long int> getCoords() const { return m_coord; }
            std::tuple<uint, uint, uint, uint> getSpritePos() const { return m_sprPos; }
            std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }
            bool getToClear() { return m_toClear;}
            void setToClear(bool boolean) { m_toClear = boolean; ;}

            virtual void move(std::vector <IObjectToDraw *> &listObject) { (void)listObject; };
            virtual void collision(std::vector <IObjectToDraw *> &listObject) { (void)listObject; };
    };

    class Mushroom : public CentiElem
    {
    private:

    public:
        Mushroom(std::pair<uint,uint> coord, std::string id = "mushroom", std::string path = "", std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32})
            : CentiElem(coord, id, path, sprPos)
        {}
        ~Mushroom()
        {}
    };

    class Lazer : public CentiElem
    {
    private:
        Timer m_moveTimer;
    public:
        Lazer(std::pair<uint,uint> coord, std::string id = "lazer_white", std::string path = "./games/centiped/assets/lazer/", std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32})
            : CentiElem(coord, id, path, sprPos)
        {
            m_moveTimer.startTimer();
        }
        ~Lazer()
        {}
        void move(std::vector <IObjectToDraw *> &object) {
            (void)object;
            if (m_moveTimer.getElapsedSeconds() < 0.1) return;
            m_moveTimer.restartTimer();
            m_coord.second -= 32;
        };

        void collision(std::vector <IObjectToDraw *> &object)
        {
            for (size_t i = 0; i < object.size(); i++) {
                if (object[i] == this)
                    continue;
                if (static_cast <CentiElem *> (object[i])->getCoords().first == m_coord.first &&
                    static_cast <CentiElem *> (object[i])->getCoords().second == m_coord.second) {
                        m_toClear = true;
                        static_cast <CentiElem *> (object[i])->setToClear(true);
                    }
            }
        };
    };
    
    class Border : public CentiElem
    {
    private:

    public:
        Border(std::pair<uint,uint> coord, std::string id = "border", std::string path = "", std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32})
            : CentiElem(coord, id, path, sprPos)
        {}
        ~Border()
        {}
    };

    class Text : public CentiElem
    {
    public:
        Text(std::pair<uint,uint> coord, std::string id = "text", std::string value = "", std::string path = "./games/centiped/assets/font/", std::tuple<uint,uint,uint,uint> sprPos = {0,0,32,32})
            : CentiElem(coord, id, path, sprPos)
        {
            m_val = value;
            m_type = IObjectToDraw::text;
        }
        ~Text()
        {}

        void setValue(std::string newValue) { m_val = newValue; };
        std::string getValue() { return m_val; };
    };
}

#endif /* !CENTIELEM_HPP_ */