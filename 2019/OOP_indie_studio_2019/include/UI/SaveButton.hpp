/*
** EPITECH PROJECT, 2020
** SAVEBUTTON_HPP
** File description:
** SAVEBUTTON_HPP
*/

#ifndef SAVEBUTTON_HPP
#define SAVEBUTTON_HPP

#include "IButton.hpp"

class SaveButton : public IButton{
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
	public:
		SaveButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void callback(class Game *game);
};

#endif /* !SAVEBUTTON_HPP */
