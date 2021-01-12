/*
** EPITECH PROJECT, 2020
** EVENT_RECEIVER_CPP
** File description:
** EVENT_RECEIVER_CPP
*/

#include <iostream>

#include "../include/Menus/MainMenu/StartMenu.hpp"
#include "../include/Menus/ControlsScreen.hpp"
#include "../include/EventReceiver.hpp"
#include "../include/UI/UIEnumeration.hpp"
#include "../include/Game.hpp"
#include "../include/UI/UIPauseMenu.hpp"

#include "../include/Sound.hpp"

EventReceiver::EventReceiver(irr::gui::IGUIEnvironment *env, Game *game)
: _env(env), _game(game)
{
    std::cout << "EventReceiver created" << std::endl;
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

EventReceiver::~EventReceiver()
{}

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
    switch (event.EventType)
    {
        case irr::EET_GUI_EVENT: GUIEvent(event); break;
        case irr::EET_MOUSE_INPUT_EVENT: break;
        case irr::EET_KEY_INPUT_EVENT: KeyInputEvent(event); break;
        // and others ...
        default: break;
    }
    return false;
}

bool EventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}

void EventReceiver::GUIEvent(const irr::SEvent &event)
{
    if (event.GUIEvent.EventType != irr::gui::EGET_BUTTON_CLICKED) return;

    // Sound* gameSound = new Sound();
    // gameSound->loadClickSound();
    // gameSound->buttonClick.play();

    _game->gameSound->buttonClick.play();

    std::vector<IUI *> interfaces = _game->getUIManager()->getInterfaces();

    for (auto *i : interfaces)
    {
        if (i == nullptr) continue;
        for (auto *j : i->getVectorButton())
        {
            if (j == nullptr) continue;
            if (!j->getButton()) continue;
            if (j->getButton()->getID() == event.GUIEvent.Caller->getID())
            {
                j->callback(_game);
                return;
            }
        }
    }
    // gameSound->buttonClick.stop();
    // delete gameSound;
}

void EventReceiver::KeyInputEvent(const irr::SEvent &event)
{
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    if (event.KeyInput.Key == irr::KEY_RETURN && _game->getStatus() == Game::State::Title || _game->getStatus() == Game::State::Credits) {
        std::cout << "Enter Main Menu" << std::endl;
        _game->setStatus(Game::State::MainMenu);
        _game->getUIManager()->clear();
        _game->getUIManager()->add(new StartMenu(_game->getEnvironment(), _game->getDriver()));
    }
    if (_game->getStatus() == Game::State::Controls) {
    	ControlsScreen *interface = static_cast <ControlsScreen *> (_game->getUIManager()->getInterface(GUI_ID_CONTROLS_INTERFACE));
        if (!interface)
            return;
        interface->startGame(_game);
    }
    if (event.KeyInput.Key == irr::KEY_ESCAPE && _game->getStatus() == Game::State::Playing)
    {
        _game->getUIManager()->add(new UIPauseMenu(_env, _game->getDriver()));
        _game->setStatus(Game::State::Pause);
    }
}