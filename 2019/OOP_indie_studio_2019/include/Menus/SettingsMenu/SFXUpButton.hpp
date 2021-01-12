/*
** EPITECH PROJECT, 2020
** SFXUPBUTTON_HPP
** File description:
** SFXUPBUTTON_HPP
*/

#ifndef SFXUPBUTTON_HPP
#define SFXUPBUTTON_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"
#include "../../Game.hpp"

class SFXUpButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;

	public:
		SFXUpButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton() {return _button;};
		void callback(class Game *game) override;
};

#endif /* !SFXUPBUTTON_HPP */