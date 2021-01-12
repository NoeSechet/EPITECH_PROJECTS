/*
** EPITECH PROJECT, 2020
** LAUNCBUTTON_CPP
** File description:
** LAUNCBUTTON_CPP
*/

#include "../../../include/Menus/PlayerSelection/LaunchButton.hpp"
#include "../../../include/Game.hpp"
#include "../../../include/Menus/ControlsScreen.hpp"
#include "../../../include/Menus/PlayerSelection/UIPlayerSelection.hpp"

#include <iostream>


LaunchButton::LaunchButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(655,790,955,890), 0, GUI_ID_LAUNCH_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/LaunchButton.png");
	_button->setImage(image);
}

irr::gui::IGUIButton *LaunchButton::getButton()
{
	 return _button;
}

void LaunchButton::callback(Game *game)
{
	std::cout << "Launch button pressed" << std::endl;
	int player_nb = 0;
	int ai_nb = 0;
	
	// Get UIPlayerSelection instance.
	UIPlayerSelection *interface = static_cast <UIPlayerSelection*> (game->getUIManager()->getInterface(GUI_ID_PLAYERSELECTION_INTERFACE));
	
	if (interface == nullptr) return;

	// Get amount of players and ais
	player_nb = interface->getPlayer();
	ai_nb = interface->getAI();

	// Error management.
	if (player_nb + ai_nb > 4 || player_nb + ai_nb == 1)
		return;

	game->getUIManager()->clear();
	game->setStatus(Game::State::Controls);
	game->getUIManager()->add(new ControlsScreen(_env, game->getDriver(), player_nb, ai_nb));
}