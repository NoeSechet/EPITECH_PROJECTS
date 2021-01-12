/*
** EPITECH PROJECT, 2020
** SFXDOWNBUTTON_HPP
** File description:
** SFXDOWNBUTTON_HPP
*/

#ifndef SFXDOWNBUTTON_HPP
#define SFXDOWNBUTTON_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"
#include "../../Game.hpp"

class SFXDownButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;

	public:
		SFXDownButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton() {return _button;};
		void callback(class Game *game) override;
};

#endif /* !SFXDOWNBUTTON_HPP */