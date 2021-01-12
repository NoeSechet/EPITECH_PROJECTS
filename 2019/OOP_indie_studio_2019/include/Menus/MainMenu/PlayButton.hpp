/*
** EPITECH PROJECT, 2020
** PLAYBUTTON_HPP
** File description:
** PLAYBUTTON_HPP
*/

#ifndef PLAYBUTTON_HPP
#define PLAYBUTTON_HPP

#include "irrlicht.h"

#include <iostream>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class PlayButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		PlayButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game) override;

};

#endif /* !PLAYBUTTON_HPP */