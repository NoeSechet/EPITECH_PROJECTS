/*
** EPITECH PROJECT, 2020
** MUSICUPBUTTON_HPP
** File description:
** MUSICUPBUTTON_HPP
*/

#ifndef MUSICUPBUTTON_HPP
#define MUSICUPBUTTON_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"
#include "../../Game.hpp"

class MusicUpButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;

	public:
		MusicUpButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton() {return _button;}
		void callback(class Game *game) override;
};

#endif /* !MUSICUPBUTTON_HPP */