/*
** EPITECH PROJECT, 2020
** UIEND_HPP
** File description:
** UIEND_HPP
*/

#ifndef UIEND_HPP
#define UIEND_HPP

#include "IUI.hpp"
#include "../Entities/EntityEnumeration.hpp"
#include "../UI/BackMenuButton.hpp"

class UIEnd : public IUI {
	private:
		irr::gui::IGUIEnvironment* _env;
		std::vector<IButton *> _buttons;
		irr::gui::IGUIImage *_endScreen;

	public:
		UIEnd(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver, int type);
		~UIEnd();
		void initialization();
        std::vector<IButton *> getVectorButton();
        irr::s32 getID();
		void clearInterface();
};

#endif /* !END_HPP */
