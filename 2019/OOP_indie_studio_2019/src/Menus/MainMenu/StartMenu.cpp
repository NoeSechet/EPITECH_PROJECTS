/*
** EPITECH PROJECT, 2020
** MAINMENU_HPP
** File description:
** MAINMENU_HPP
*/

#include "../../../include/Menus/MainMenu/StartMenu.hpp"
#include "../../../include/Menus/MainMenu/QuitButton.hpp"
#include "../../../include/Menus/MainMenu/PlayButton.hpp"
#include "../../../include/Menus/MainMenu/LoadButton.hpp"
#include "../../../include/Menus/MainMenu/SettingsButton.hpp"
#include "../../../include/Menus/MainMenu/CreditsButton.hpp"

StartMenu::StartMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver) : _env(env)
{
	irr::video::ITexture* image = driver->getTexture("../asset/menus/MenuScreen.png");
	_background = env->addImage(image, irr::core::position2di(0, 0));
	_buttons.push_back(new QuitButton(_env, driver));
	_buttons.push_back(new PlayButton(_env, driver));
	_buttons.push_back(new LoadButton(_env, driver));
	_buttons.push_back(new SettingsButton(_env, driver));
	_buttons.push_back(new CreditsButton(_env, driver));
}
		
StartMenu::~StartMenu()
{
	for (auto *j : getVectorButton()) {
		if (!j) continue;
        j->getButton()->remove();
    }
}

std::vector<IButton *> StartMenu::getVectorButton()
{
	return _buttons;
}

irr::s32 StartMenu::getID()
{
    return GUI_ID_MAINMENU_INTERFACE;
}

void StartMenu::clearInterface()
{
	for (auto *j : getVectorButton()) {
		if (!j) continue;
        j->getButton()->remove();
    }
	_background->remove();
}