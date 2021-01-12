/*
** EPITECH PROJECT, 2020
** LAUNCHBUTTON_HPP
** File description:
** LAUNCHBUTTON_HPP
*/

#ifndef LAUNCHBUTTON_HPP
#define LAUNCHBUTTON_HPP

#include <irrlicht.h>
#include <iostream>
#include <string>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class LaunchButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;

	public:
		LaunchButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game) override;
};

#endif /* !LAUNCHBUTTON_HPP */