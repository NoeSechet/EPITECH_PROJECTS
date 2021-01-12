/*
** EPITECH PROJECT, 2020
** MAINMENU_HPP
** File description:
** MAINMENU_HPP
*/

#include "../../include/UI/UIEnd.hpp"

UIEnd::UIEnd(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver, int type) : _env(env)
{
    irr::video::ITexture* image;
    switch (type) {
        case PLAYER_1:
            image = driver->getTexture("../asset/EndScreens/Player1_Win.png");
            break;
        case PLAYER_2:
            image = driver->getTexture("../asset/EndScreens/Player2_Win.png");
            break;
        case PLAYER_3:
            image = driver->getTexture("../asset/EndScreens/Player3_Win.png");
            break;
        case PLAYER_4:
            image = driver->getTexture("../asset/EndScreens/Player4_Win.png");
            break;
        default:
            image = driver->getTexture("../asset/EndScreens/AI_Win.png");
            break;
    }
    _endScreen = env->addImage(image, irr::core::position2di(0, 0));
    BackMenuButton *backMenuButton = new BackMenuButton(_env, driver);
    backMenuButton->getButton()->setRelativePosition(irr::core::rect<irr::s32>(810,820,1110,920));
    _buttons.push_back(backMenuButton);
};
		
UIEnd::~UIEnd()
{
};

std::vector<IButton *> UIEnd::getVectorButton()
{
	return _buttons;
};

irr::s32 UIEnd::getID()
{
    return GUI_ID_END_INTERFACE;
}

void UIEnd::clearInterface()
{
	for (auto *j : getVectorButton())
    {
		if (!j) continue;
        j->getButton()->remove();
    }
    _endScreen->remove();
}


