/*
** EPITECH PROJECT, 2020
** CreditsScreen_HPP
** File description:
** CreditsScreen_HPP
*/

#ifndef CREDITSSCREEN_HPP
#define CREDITSSCREEN_HPP

#include "../UI/IUI.hpp"

class CreditsScreen : public IUI {
  private:
	irr::gui::IGUIEnvironment* _env;
	std::vector<IButton *> _buttons;
  irr::gui::IGUIImage *_background;
  public:
    CreditsScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
    ~CreditsScreen();
    std::vector<IButton *> getVectorButton() override;
    irr::s32 getID() override;
    void clearInterface() override;
};

#endif // CREDITSSCREEN_HPP