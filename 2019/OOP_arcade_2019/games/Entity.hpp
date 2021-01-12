/*
** EPITECH PROJECT, 2020
** ENTITY
** File description:
** ENTITY
*/

#ifndef ENTITY
#define ENTITY

#include "../GlobalHeaders.hpp"
#include <vector>

class Entity : public IObjectToDraw {
    protected:
        std::pair <long int, long int> m_coord = {0, 0};
        std::string m_id = "";
        std::string m_path = "";
        std::tuple <uint, uint, uint, uint> m_spriPos = {0,0,0,0};
        bool m_toClear = false;
        std::tuple <uint, uint, uint, uint> m_color = {255,255,255,255};
    public:
        Entity(std::pair <long int, long int> coord, std::string id, std::string path, std::tuple<uint,uint,uint,uint> spriPos)
            : m_coord(coord), m_id(id), m_path(path), m_spriPos(spriPos) {}
        virtual ~Entity() = 0;
        virtual std::string getId() const { return "Entity"; };
        bool getToClear(void) const { return m_toClear; };
        void setToClear(bool toClear) { m_toClear = toClear; };
        void setId(std::string id) { m_id = id; };
        std::string getPath() const { return m_path; };
        virtual Type getType() const { return objects; };
        virtual std::string getValue() const { return "";};
        std::pair <long int, long int> getCoords() const { return m_coord; };
        void setCoords(std::pair<long int, long int> coord) { m_coord = coord; };
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return m_spriPos; };
        std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }

        virtual void move(void) {};
        virtual void action(std::vector <IObjectToDraw *> &objects) { (void)objects; };
        virtual void impact(std::vector <IObjectToDraw *> &objects) { (void)objects; };
};

#endif /* !ENTITY */