/*
** EPITECH PROJECT, 2020
** UIPAUSEMENU_CPP
** File description:
** UIPAUSEMENU_CPP
*/

#include "../../include/UI/UIPauseMenu.hpp"

#include "../../include/UI/SaveButton.hpp"
#include "../../include/UI/ResumeButton.hpp"
#include "../../include/UI/BackMenuButton.hpp"

UIPauseMenu::UIPauseMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver) : _env(env)
{
    _buttons.push_back(new SaveButton(_env, driver));
	_buttons.push_back(new BackMenuButton(_env, driver));
	_buttons.push_back(new ResumeButton(_env, driver));
};
		
UIPauseMenu::~UIPauseMenu()
{
};

std::vector<IButton *> UIPauseMenu::getVectorButton()
{
	return _buttons;
};

irr::s32 UIPauseMenu::getID()
{
    return GUI_ID_PAUSEMENU_INTERFACE;
}

void UIPauseMenu::clearInterface()
{
	for (auto *j : getVectorButton())
    {
        j->getButton()->remove();
    }
}


