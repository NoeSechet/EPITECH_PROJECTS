/*
** EPITECH PROJECT, 2020
** IBUTTON_HPP
** File description:
** IBUTTON_HPP
*/

#ifndef IBUTTON_HPP
#define IBUTTON_HPP

#include "irrlicht.h"

class IButton {
	public:
	 	virtual irr::gui::IGUIButton *getButton() = 0;
		virtual void callback(class Game *game) = 0;
};

#endif /* !IBUTTON_HPP */
