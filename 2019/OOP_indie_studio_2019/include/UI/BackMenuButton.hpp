/*
** EPITECH PROJECT, 2020
** BACKMENUBUTTON_HPP
** File description:
** BACKMENUBUTTON_HPP
*/

#ifndef BACKMENUBUTTON_HPP
#define BACKMENUBUTTON_HPP

#include "IButton.hpp"

class BackMenuButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		BackMenuButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game);
};

#endif /* !BACKMENUBUTTON_HPP */
