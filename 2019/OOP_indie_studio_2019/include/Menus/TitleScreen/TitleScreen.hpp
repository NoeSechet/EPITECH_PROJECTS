/*
** EPITECH PROJECT, 2020
** TitleScreen_HPP
** File description:
** TitleScreen_HPP
*/

#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include "../../UI/IUI.hpp"

class TitleScreen : public IUI {
  private:
	irr::gui::IGUIEnvironment* _env;
	std::vector<IButton *> _buttons;
  irr::gui::IGUIImage *_titleScreen;
  public:
    TitleScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
    ~TitleScreen();
    std::vector<IButton *> getVectorButton() override;
    irr::s32 getID() override;
    void clearInterface() override;
};

#endif // TITLESCREEN_HPP