/*
** EPITECH PROJECT, 2020
** SFXUPBUTTON_CPP
** File description:
** SFXUPBUTTON_CPP
*/

#include "../../../include/Menus/SettingsMenu/SFXUpButton.hpp"

SFXUpButton::SFXUpButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(1120,675,1170,725), 0, GUI_ID_SFX_UP_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/ArrowRight.png");
	_button->setImage(image);
};

void SFXUpButton::callback(Game *game)
{
	if (game->gameSound->explosionSound.getVolume() < 90.f) {
		game->gameSound->explosionSound.setVolume(game->gameSound->explosionSound.getVolume() + 10.f);
		game->gameSound->buttonClick.setVolume(game->gameSound->buttonClick.getVolume() + 10.f);
	}
};