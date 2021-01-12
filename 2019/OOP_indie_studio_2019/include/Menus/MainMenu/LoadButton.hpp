/*
** EPITECH PROJECT, 2020
** LOADBUTTON_HPP
** File description:
** LOADBUTTON_HPP
*/

#ifndef LOADBUTTON_HPP
#define LOADBUTTON_HPP

#include "irrlicht.h"

#include <iostream>
#include <vector>

#include "../../UI/IButton.hpp"
#include "../../UI/UIEnumeration.hpp"

class LoadButton : public IButton {
	private:
		irr::gui::IGUIButton *_button;
		irr::gui::IGUIEnvironment* _env;
		std::vector<irr::core::vector3df> _cubePos;
		int _nbPlayers = 0;
		int _nbAI = 0;
	public:
		LoadButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	 	irr::gui::IGUIButton *getButton();
		void saveEntity(irr::s32 id, irr::core::vector3df position);
		void callback(class Game *game) override;
		irr::core::vector3df getPosition(std::string str);
		void fillGameList(Game *game);
};

#endif /* !LOADBUTTON_HPP */