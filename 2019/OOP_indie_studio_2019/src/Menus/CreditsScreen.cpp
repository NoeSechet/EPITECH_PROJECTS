/*
** EPITECH PROJECT, 2020
** MAINMENU_HPP
** File description:
** MAINMENU_HPP
*/

#include "../../include/Menus/CreditsScreen.hpp"

CreditsScreen::CreditsScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver) : _env(env)
{
	irr::video::ITexture* image = driver->getTexture("../asset/menus/CreditsScreen.png");
	_background = env->addImage(image, irr::core::position2di(0, 0));
}
		
CreditsScreen::~CreditsScreen()
{
}

std::vector<IButton *> CreditsScreen::getVectorButton()
{
	return _buttons;
}

irr::s32 CreditsScreen::getID()
{
    return GUI_ID_Credits_INTERFACE;
}

void CreditsScreen::clearInterface()
{
	_background->remove();
}