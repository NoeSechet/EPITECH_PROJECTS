/*
** EPITECH PROJECT, 2020
** EVENT_RECEIVER_HPP
** File description:
** EVENT_RECEIVER_HPP
*/

#ifndef EVENT_RECEIVER_HPP
#define EVENT_RECEIVER_HPP

#include <irrlicht.h>

class EventReceiver : public irr::IEventReceiver {
    private:
        irr::gui::IGUIEnvironment *_env;
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
        class Game *_game;
    public:
        EventReceiver(irr::gui::IGUIEnvironment *env, class Game *game);
        ~EventReceiver();

        bool OnEvent(const irr::SEvent &event);
        void GUIEvent(const irr::SEvent &event);

        bool IsKeyDown(irr::EKEY_CODE keyCode) const;
        void KeyInputEvent(const irr::SEvent &event);
};

#endif /* !EVENT_RECEIVER_HPP */
