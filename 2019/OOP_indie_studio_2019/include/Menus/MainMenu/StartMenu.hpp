/*
** EPITECH PROJECT, 2020
** MAINMENU_HPP
** File description:
** MAINMENU_HPP
*/

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "../../UI/IUI.hpp"

class StartMenu : public IUI {
  private:
	irr::gui::IGUIEnvironment* _env;
	std::vector<IButton *> _buttons;
	irr::gui::IGUIImage *_background;
  public:
	StartMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	~StartMenu();
	std::vector<IButton *> getVectorButton() override;
	irr::s32 getID() override;
	void clearInterface() override;
};
#endif /* !MAINMENU_HPP */
