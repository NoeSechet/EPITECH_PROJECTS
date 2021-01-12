/*
** EPITECH PROJECT, 2020
** QUITBUTTON_CPP
** File description:
** QUITBUTTON_CPP
*/

#include "../../../include/Menus/MainMenu/QuitButton.hpp"
#include "../../../include/Game.hpp"

QuitButton::QuitButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(810,720,1110,820), 0, GUI_ID_QUIT_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/QuitButton.png");
	_button->setImage(image);
}

irr::gui::IGUIButton *QuitButton::getButton()
{
	 return _button;
}

void QuitButton::callback(Game *game)
{
	std::cout << "Quit button pressed" << std::endl;

	game->setStatus(Game::State::Exit);
}