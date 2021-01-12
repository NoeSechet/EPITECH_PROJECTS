/*
** EPITECH PROJECT, 2020
** QUITBUTTON_HPP
** File description:
** QUITBUTTON_HPP
*/

#ifndef QUITBUTTON_HPP
#define QUITBUTTON_HPP

#include "irrlicht.h"

#include <iostream>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class QuitButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		QuitButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game) override;

};

#endif /* !QUITBUTTON_HPP */