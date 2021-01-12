/*
** EPITECH PROJECT, 2020
** RESUMEBUTTON_CPP
** File description:
** RESUMEBUTTON_CPP
*/

#include "../../include/UI/ResumeButton.hpp"
#include "../../include/Game.hpp"


ResumeButton::ResumeButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(810,340,1110,440), 0, GUI_ID_RESUME_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/ResumeButton.png");
	_button->setImage(image);
};

irr::gui::IGUIButton *ResumeButton::getButton()
{
	 return _button;
}
void ResumeButton::callback(Game *game)
{
	std::cout << "Resume button pressed" << std::endl;

	game->getUIManager()->clear(GUI_ID_PAUSEMENU_INTERFACE);
	game->setStatus(Game::State::Playing);
};