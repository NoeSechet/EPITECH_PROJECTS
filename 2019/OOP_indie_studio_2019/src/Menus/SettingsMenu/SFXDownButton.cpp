/*
** EPITECH PROJECT, 2020
** SFXDOWNBUTTON_CPP
** File description:
** SFXDOWNBUTTON_CPP
*/

#include "../../../include/Menus/SettingsMenu/SFXDownButton.hpp"

SFXDownButton::SFXDownButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(750,675,800,725), 0, GUI_ID_SFX_DOWN_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/ArrowLeft.png");
	_button->setImage(image);
};

void SFXDownButton::callback(Game *game)
{
	if (game->gameSound->explosionSound.getVolume() > 15.f) {
		game->gameSound->explosionSound.setVolume(game->gameSound->explosionSound.getVolume() - 10.f);
		game->gameSound->buttonClick.setVolume(game->gameSound->buttonClick.getVolume() - 10.f);
	}
};