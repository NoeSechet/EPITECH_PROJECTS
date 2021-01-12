/*
** EPITECH PROJECT, 2020
** SETTINGSMENU_CPP
** File description:
** SETTINGSMENU_CPP
*/

#include "../../../include/Menus/SettingsMenu/SettingsMenu.hpp"
#include "../../../include/Menus/SettingsMenu/MusicDownButton.hpp"
#include "../../../include/Menus/SettingsMenu/MusicUpButton.hpp"
#include "../../../include/Menus/SettingsMenu/SFXUpButton.hpp"
#include "../../../include/Menus/SettingsMenu/SFXDownButton.hpp"
#include "../../../include/UI/BackMenuButton.hpp"

SettingsMenu::SettingsMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver) : _env(env)
{
    irr::video::ITexture* image = driver->getTexture("../asset/menus/MenuScreen.png");
	_background = env->addImage(image, irr::core::position2di(0, 0));
    image = driver->getTexture("../asset/menus/SFXSettings.png");
    _sfx = env->addImage(image, irr::core::position2di(810, 650));
    image = driver->getTexture("../asset/menus/MusicSettings.png");
    _music = env->addImage(image, irr::core::position2di(810, 760));

    _buttons.push_back(new MusicUpButton(_env, driver));
    _buttons.push_back(new MusicDownButton(_env, driver));
    _buttons.push_back(new SFXUpButton(_env, driver));
    _buttons.push_back(new SFXDownButton(_env, driver));
    BackMenuButton *backMenuButton = new BackMenuButton(_env, driver);
    backMenuButton->getButton()->setRelativePosition(irr::core::rect<irr::s32>(810,870,1110,970));
    _buttons.push_back(backMenuButton);
}

SettingsMenu::~SettingsMenu()
{
	for (auto *j : getVectorButton()) {
		if (!j) continue;
        j->getButton()->remove();
    }
}

void SettingsMenu::clearInterface()
{
	for (auto *j : getVectorButton()) {
		if (!j) continue;
        j->getButton()->remove();
    }
	_background->remove();
    _music->remove();
    _sfx->remove();
}