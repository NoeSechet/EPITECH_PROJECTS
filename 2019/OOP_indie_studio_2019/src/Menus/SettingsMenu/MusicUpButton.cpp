/*
** EPITECH PROJECT, 2020
** MUSICUPBUTTON_CPP
** File description:
** MUSICUPBUTTON_CPP
*/

#include "../../../include/Menus/SettingsMenu/MusicUpButton.hpp"

MusicUpButton::MusicUpButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(1120,785,1170,835), 0, GUI_ID_MUSIC_UP_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/ArrowRight.png");
	_button->setImage(image);
};

void MusicUpButton::callback(Game *game)
{
	if (game->gameSound->gameTheme.getVolume() < 90.f)
		game->gameSound->gameTheme.setVolume(game->gameSound->gameTheme.getVolume() + 10.f);
};