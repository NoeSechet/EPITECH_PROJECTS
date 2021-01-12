/*
** EPITECH PROJECT, 2020
** MUSICDOWNBUTTON_CPP
** File description:
** MUSICDOWNBUTTON_CPP
*/

#include "../../../include/Menus/SettingsMenu/MusicDownButton.hpp"

MusicDownButton::MusicDownButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(750,785,800,835), 0, GUI_ID_MUSIC_DOWN_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/ArrowLeft.png");
	_button->setImage(image);
};

void MusicDownButton::callback(Game *game)
{
	if (game->gameSound->gameTheme.getVolume() > 15.f)
		game->gameSound->gameTheme.setVolume(game->gameSound->gameTheme.getVolume() - 10.f);
};