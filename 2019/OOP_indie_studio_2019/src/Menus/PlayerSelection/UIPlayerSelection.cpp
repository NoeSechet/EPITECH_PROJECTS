/*
** EPITECH PROJECT, 2020
** UIPLAYERSELECTION_HPP
** File description:
** UIPLAYERSELECTION_HPP
*/

#include "../../../include/Menus/PlayerSelection/UIPlayerSelection.hpp"
#include "../../../include/Menus/PlayerSelection/LaunchButton.hpp"
#include "../../../include/UI/BackMenuButton.hpp"

UIPlayerSelection::UIPlayerSelection(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
: _env(env)
{
    irr::video::ITexture* image = driver->getTexture("../asset/menus/MenuScreen.png");
	_background = env->addImage(image, irr::core::position2di(0, 0));
    image = driver->getTexture("../asset/menus/SelectionPanel.png");
	_selectionPanel = env->addImage(image, irr::core::position2di(660, 540));

    for (size_t i = 0; i < _numberPlayer.max_size(); i++)
        _numberPlayer[i] = _env->addCheckBox(false, irr::core::rect<irr::s32>(905 + (i * 53), 680, 925 + (i * 53), 700));
    for (size_t i = 0; i < _numberAI.max_size(); i++)
        _numberAI[i] = _env->addCheckBox(false, irr::core::rect<irr::s32>(905 + ((i- 1) * 53), 730, 925 + ((i- 1) * 53), 750));
    _numberPlayer[0]->setChecked(true);
    _numberAI[3]->setChecked(true);
    _button.push_back(new LaunchButton(_env, driver));
    BackMenuButton *backMenuButton = new BackMenuButton(_env, driver);
    backMenuButton->getButton()->setRelativePosition(irr::core::rect<irr::s32>(965,790,1265,890));
    _button.push_back(backMenuButton);
}

UIPlayerSelection::~UIPlayerSelection()
{
}

std::vector<IButton *> UIPlayerSelection::getVectorButton()
{
    return _button;
}

irr::s32 UIPlayerSelection::getID()
{
    return GUI_ID_PLAYERSELECTION_INTERFACE;
}

void UIPlayerSelection::update()
{
    bool player = false;
    bool ai = false;
    for (size_t i = 0; i < _numberPlayer.max_size(); i++) {
        if (_numberPlayer[i]->isChecked() && i + 1 != _player) {
            _numberPlayer[_player - 1]->setChecked(false);
            _player = i + 1;
            player = true;
        }
    }
    if (!player)
            _numberPlayer[_player - 1]->setChecked(true);
    for (size_t i = 0; i < _numberAI.max_size(); i++) {
        if (_numberAI[i]->isChecked() && i != _ai) {
            _numberAI[_ai]->setChecked(false);
            _ai = i;
            ai = true;
        }
    }
    if (!ai)
        _numberAI[_ai]->setChecked(true);
}

void UIPlayerSelection::clearInterface()
{
    for (auto *j : getVectorButton())
    {
        j->getButton()->remove();
    }
    for (size_t i = 0; i < _numberPlayer.max_size(); i++)
    _numberPlayer[i]->remove();
    for (size_t i = 0; i < _numberAI.max_size(); i++)
        _numberAI[i]->remove();
    _background->remove();
    _selectionPanel->remove();
}
