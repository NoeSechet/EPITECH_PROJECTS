/*
** EPITECH PROJECT, 2020
** MUSICDOWNBUTTON_HPP
** File description:
** MUSICDOWNBUTTON_HPP
*/

#ifndef MUSICDOWNBUTTON_HPP
#define MUSICDOWNBUTTON_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"
#include "../../Game.hpp"

class MusicDownButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;

	public:
		MusicDownButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton() override {return _button;}
		void callback(class Game *game) override;
};

#endif /* !MUSICDOWNBUTTON_HPP */