/*
** EPITECH PROJECT, 2020
** CREDITSBUTTON_HPP
** File description:
** CREDITSBUTTON_HPP
*/

#ifndef CREDITSBUTTON_HPP
#define CREDITSBUTTON_HPP

#include "irrlicht.h"

#include <iostream>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class CreditsButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		CreditsButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game) override;

};

#endif /* !CREDITSBUTTON_HPP */