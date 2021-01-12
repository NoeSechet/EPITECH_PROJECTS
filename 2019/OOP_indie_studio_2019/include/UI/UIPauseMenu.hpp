/*
** EPITECH PROJECT, 2020
** UIPAUSEMENU_HPP
** File description:
** UIPAUSEMENU_HPP
*/

#ifndef UIPAUSEMENU_HPP
#define UIPAUSEMENU_HPP

#include "IUI.hpp"

class UIPauseMenu : public IUI {
	private:
		irr::gui::IGUIEnvironment* _env;
		std::vector<IButton *> _buttons;
	public:
		UIPauseMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
		~UIPauseMenu();
		void initialization();
        std::vector<IButton *> getVectorButton();
        irr::s32 getID();
		void clearInterface();
};

#endif /* !UIPAUSEMENU_HPP */
