/*
** EPITECH PROJECT, 2020
** RESUMEBUTTON_HPP
** File description:
** RESUMEBUTTON_HPP
*/

#ifndef RESUMEBUTTON_HPP
#define RESUMEBUTTON_HPP

#include "irrlicht.h"

#include <iostream>

#include "IButton.hpp"
#include "UIEnumeration.hpp"

class ResumeButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		ResumeButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game);
};

#endif /* !RESUMEBUTTON_HPP */
