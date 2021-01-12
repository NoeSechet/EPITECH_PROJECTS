/*
** EPITECH PROJECT, 2020
** CREDITSBUTTON_CPP
** File description:
** CREDITSBUTTON_CPP
*/

#include "../../../include/Menus/MainMenu/CreditsButton.hpp"
#include "../../../include/Menus/CreditsScreen.hpp"
#include "../../../include/Game.hpp"

CreditsButton::CreditsButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(965,610,1265,710), 0, GUI_ID_CREDITS_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/CreditsButton.png");
	_button->setImage(image);
};

irr::gui::IGUIButton *CreditsButton::getButton()
{
	 return _button;
}
void CreditsButton::callback(Game *game)
{
	std::cout << "Credits button pressed" << std::endl;

	game->getUIManager()->clear();
	game->getUIManager()->add(new CreditsScreen(_env, game->getDriver()));
	game->setStatus(Game::State::Credits);
};