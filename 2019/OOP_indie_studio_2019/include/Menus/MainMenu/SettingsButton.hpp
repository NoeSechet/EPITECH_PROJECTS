/*
** EPITECH PROJECT, 2020
** SETTINGSBUTTON_HPP
** File description:
** SETTINGSBUTTON_HPP
*/

#ifndef SETTINGSBUTTON_HPP
#define SETTINGSBUTTON_HPP

#include "irrlicht.h"

#include <iostream>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class SettingsButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		SettingsButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game) override;

};

#endif /* !SETTINGSBUTTON_HPP */