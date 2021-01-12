/*
** EPITECH PROJECT, 2020
** TitleScreen_CPP
** File description:
** TitleScreen_CPP
*/

#include "../../../include/Menus/TitleScreen/TitleScreen.hpp"

TitleScreen::TitleScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
{
    irr::video::ITexture* image = driver->getTexture("../asset/menus/TitleScreen.png");
    _titleScreen = env->addImage(image, irr::core::position2di(0, 0));
}

TitleScreen::~TitleScreen()
{
    for (auto *j : _buttons) {
		if (!j) continue;
        j->getButton()->remove();
    }
}

std::vector<IButton *> TitleScreen::getVectorButton()
{
	return _buttons;
}

irr::s32 TitleScreen::getID()
{
    return GUI_ID_TITLESCREEN_INTERFACE;
}

void TitleScreen::clearInterface()
{
    for (auto *j : getVectorButton()) {
		if (!j) continue;
        j->getButton()->remove();
    }
    _titleScreen->remove();
}