/*
** EPITECH PROJECT, 2020
** UIPLAYERSELECTION_HPP
** File description:
** UIPLAYERSELECTION_HPP
*/

#ifndef UIPLAYERSELECTION_HPP
#define UIPLAYERSELECTION_HPP

#include "../../UI/IUI.hpp"

#include <array>

class UIPlayerSelection : public IUI {
  private:
    irr::gui::IGUIEnvironment* _env;
    std::vector<IButton *> _button;;
    irr::gui::IGUIImage *_background;
    irr::gui::IGUIImage *_selectionPanel;
    std::array<irr::gui::IGUICheckBox *, 4> _numberPlayer;
    std::array<irr::gui::IGUICheckBox *, 4> _numberAI;

  int _player = 1;
  int _ai = 3;
  public:
    UIPlayerSelection(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver);
    ~UIPlayerSelection();
    std::vector<IButton *> getVectorButton();
    irr::s32 getID();
    void update();
    void clearInterface();
    int getPlayer() {return _player;}
    int getAI() {return _ai;}
};

#endif /* !UIPLAYERSELECTION_HPP */


