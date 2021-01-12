/*
** EPITECH PROJECT, 2020
** SETTINGSMENU_HPP
** File description:
** SETTINGSMENU_HPP
*/

#ifndef SETTINGSMENU_HPP
#define SETTINGSMENU_HPP

#include "../../UI/IUI.hpp"
#include "../../Game.hpp"

class SettingsMenu : public IUI {
  private:
	irr::gui::IGUIEnvironment* _env;
	std::vector<IButton *> _buttons;
	irr::gui::IGUIImage *_background;
	irr::gui::IGUIImage *_music;
	irr::gui::IGUICheckBox *_musicEnabled;
	irr::gui::IGUIImage *_sfx;
	irr::gui::IGUICheckBox *_sfxEnabled;
  public:
	SettingsMenu(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
	~SettingsMenu();
	std::vector<IButton *> getVectorButton() override {return _buttons;}
	irr::s32 getID() override {return GUI_ID_SETTINGS_INTERFACE;}
	void clearInterface() override;
	void update(Game *game);
};
#endif /* !SETTINGSMENU_HPP */
