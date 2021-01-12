/*
** EPITECH PROJECT, 2020
** PLAYBUTTON_CPP
** File description:
** PLAYBUTTON_CPP
*/

#include "../../../include/Menus/MainMenu/PlayButton.hpp"
#include "../../../include/Game.hpp"
#include "../../../include/Menus/PlayerSelection/UIPlayerSelection.hpp"


PlayButton::PlayButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(655,500,955,600), 0, GUI_ID_PLAY_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/PlayButton.png");
	_button->setImage(image);
};

irr::gui::IGUIButton *PlayButton::getButton()
{
	 return _button;
}
void PlayButton::callback(Game *game)
{
	std::cout << "Play button pressed" << std::endl;

	game->getUIManager()->clear();
	game->getUIManager()->add(new UIPlayerSelection(_env, game->getDriver()));
	game->setStatus(Game::State::Selection);
};