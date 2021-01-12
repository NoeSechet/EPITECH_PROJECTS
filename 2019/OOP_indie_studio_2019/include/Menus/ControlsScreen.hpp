/*
** EPITECH PROJECT, 2020
** ControlScreen_HPP
** File description:
** ControlScreen_HPP
*/

#ifndef CONTROLSCREEN_HPP
#define CONTROLSCREEN_HPP

#include "../UI/IUI.hpp"
#include "../Game.hpp"

class ControlsScreen : public IUI {
  private:
	irr::gui::IGUIEnvironment* _env;
	std::vector<IButton *> _buttons;
    irr::gui::IGUIImage *_background;
    std::vector<irr::gui::IGUIImage *> _controls;
    int _playersNum;
    int _aiNum;
  public:
    ControlsScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver, int players, int AI);
    ~ControlsScreen();
    std::vector<IButton *> getVectorButton() override;
    irr::s32 getID() override;
    void clearInterface() override;
    void startGame(Game *game);
};

#endif // CONTROLSCREEN_HPP