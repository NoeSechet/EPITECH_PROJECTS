/*
** EPITECH PROJECT, 2020
** BACKMENUBUTTON_CPP
** File description:
** BACKMENUBUTTON_CPP
*/

#include "../../include/UI/BackMenuButton.hpp"
#include "../../include/Game.hpp"
#include "../../include/Menus/MainMenu/StartMenu.hpp"

#include <iostream>

BackMenuButton::BackMenuButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(810,640,1110,740), 0, GUI_ID_BACKMENU_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/MenuButton.png");
	_button->setImage(image);
}

irr::gui::IGUIButton *BackMenuButton::getButton()
{
	 return _button;
}

void BackMenuButton::callback(Game *game)
{
	std::cout << "BackMenu button pressed" << std::endl;

	game->getUIManager()->clear();
	game->getUIManager()->add(new StartMenu(_env, game->getDriver()));
	game->setStatus(Game::State::MainMenu);
	game->clearAllEntities();
}