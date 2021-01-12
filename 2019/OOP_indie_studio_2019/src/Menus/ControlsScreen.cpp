/*
** EPITECH PROJECT, 2020
** MAINMENU_HPP
** File description:
** MAINMENU_HPP
*/

#include "../../include/Menus/ControlsScreen.hpp"

ControlsScreen::ControlsScreen(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver, int players, int AI) : _env(env), _aiNum(AI), _playersNum(players)
{
	irr::video::ITexture* image = driver->getTexture("../asset/menus/MenuScreen.png");
	_background = env->addImage(image, irr::core::position2di(0, 0));
    switch (_playersNum)
    {
        case 4:
            image = driver->getTexture("../asset/menus/Player4_Controls.png");
	        _controls.push_back(_env->addImage(image, irr::core::position2di(1300, 600)));
        case 3:
            image = driver->getTexture("../asset/menus/Player3_Controls.png");
	        _controls.push_back(_env->addImage(image, irr::core::position2di(1000, 600)));
        case 2:
            image = driver->getTexture("../asset/menus/Player2_Controls.png");
	        _controls.push_back(_env->addImage(image, irr::core::position2di(700, 600)));
        case 1:
            image = driver->getTexture("../asset/menus/Player1_Controls.png");
	        _controls.push_back(_env->addImage(image, irr::core::position2di(400, 600)));
        break;
    default:
        break;
    }
}
		
ControlsScreen::~ControlsScreen()
{
}

std::vector<IButton *> ControlsScreen::getVectorButton()
{
	return _buttons;
}

irr::s32 ControlsScreen::getID()
{
    return GUI_ID_CONTROLS_INTERFACE;
}

void ControlsScreen::clearInterface()
{
	_background->remove();
    for (auto i : _controls)
        i->remove();
}

void ControlsScreen::startGame(Game *game)
{
	game->getUIManager()->clear();
	game->setStatus(Game::State::Playing);
	game->initLevel(_playersNum, _aiNum);
	game->getMap()->proceduralGenCubes(game->getListEntities());
}
