/*
** EPITECH PROJECT, 2020
** ENTITIES
** File description:
** ENTITIES
*/

#ifndef ENTITIES
#define ENTITIES

#include "Entity.hpp"
#include "../Timer.hpp"

class Border : public Entity {
    public:
        Border(std::pair <long int, long int> coord, std::string id = "border", std::string path = "",
            std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32})
            : Entity(coord, id, path, spriPos) {};
        ~Border() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};

class Monster : public Entity {
    private:
        COMMAND m_directionLazer = DOWN;
        Timer m_timerMove;
        Timer m_timerShoot;
        std::pair <long int, long int> m_movementFactor;
    public:
        Monster(std::pair <long int, long int> coord, std::pair <long int, long int> movementFactor = {0, 0}, std::string id = "monster",
            std::string path = "", std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32});
        ~Monster();
        void setDirectionLazer(COMMAND direction);
        std::string getId() const;
        Type getType() const;
        std::string getValue() const;
        void move(void);
        void action(std::vector <IObjectToDraw *> &objects);
        void impact(std::vector <IObjectToDraw *> &objects); 
        private:
            void reverseMovementFactor(void);
};

class Player : public Entity {
    private:
        COMMAND m_command = NO_INPUT;
        COMMAND m_direction = NO_INPUT;
        Timer m_timerMove;
        Timer m_timerShoot;
    public:
        Player(std::pair <long int, long int> coord, std::string id = "player_up",
            std::string path = "", std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32});
        ~Player();
        void setCommand(COMMAND command);
        std::string getId() const; // pas de maj pour les id.
        Type getType() const;
        std::string getValue() const;
        void setPlayerDirection();
        void move(void);
        void action(std::vector <IObjectToDraw *> &objects);
        void impact(std::vector <IObjectToDraw *> &objects);
};

class Target : public Entity {
    public:
        Target(std::pair <long int, long int> coord, std::string id = "target", std::string path = "", std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32})
            : Entity(coord, id, path, spriPos) {};
        ~Target() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return objects; };
        std::string getValue() const { return ""; };
};

class Lazer : public Entity {
    public:
    typedef enum OWNER {
        O_MONSTER,
        O_PLAYER
    } OWNER;
    private:
        std::pair <long int, long int> m_movementFactor;
        OWNER m_owner;
        Timer m_timer;
    public:
        Lazer(std::pair <long int, long int> coord, std::pair <long int, long int> movementFactor = {0, 0}, OWNER owner = O_PLAYER, std::string id = "lazer",
            std::string path = "", std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32});
        ~Lazer();
        std::string getId() const;
        Type getType() const;
        std::string getValue() const;
        void move(void);
        void impact(std::vector <IObjectToDraw *> &objects);
};

class Text : public Entity {
    private:
        std::string m_value = "";
    public:
        Text(std::pair <long int, long int> coord, std::string id = "text", std::string path = "", std::tuple<uint,uint,uint,uint> spriPos = {0,0,32,32})
            : Entity(coord, id, path, spriPos) {};
        ~Text() {};
        std::string getId() const { return m_id; }; // pas de maj pour les id.
        Type getType() const { return text; };
        std::string getValue() const { return m_value; };
        std::string setValue(std::string value) { return m_value = value; };
};

#endif /* !ENTITIES */
