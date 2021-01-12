/*
** EPITECH PROJECT, 2020
** SETTINGSBUTTON_CPP
** File description:
** SETTINGSBUTTON_CPP
*/

#include "../../../include/Menus/MainMenu/SettingsButton.hpp"
#include "../../../include/Game.hpp"
#include "../../../include/Menus/SettingsMenu/SettingsMenu.hpp"

SettingsButton::SettingsButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(965,500,1265,600), 0, GUI_ID_SETTINGS_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/SettingsButton.png");
	_button->setImage(image);
};

irr::gui::IGUIButton *SettingsButton::getButton()
{
	 return _button;
}
void SettingsButton::callback(Game *game)
{
	std::cout << "Settings button pressed" << std::endl;

	game->getUIManager()->clear();
	game->getUIManager()->add(new SettingsMenu(_env, game->getDriver()));
};