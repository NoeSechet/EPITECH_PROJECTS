/*
** EPITECH PROJECT, 2020
** UIMANAGER_CPP
** File description:
** UIMANAGER_CPP
*/

#include <iostream>

#include "../../include/UI/UIManager.hpp"

UIManager::UIManager()
{
    std::cout << "UIManager created" << std::endl;
}

UIManager::~UIManager()
{
}

void UIManager::add(IUI *interface)
{
    _interfaces.push_back(interface);
}

void UIManager::clear()
{
    for (auto *i : _interfaces)
    {
        if (i == nullptr) continue;
        i->clearInterface();
    }
    _interfaces.clear();
}

void UIManager::clear(irr::s32 id)
{
    for (size_t i = 0; i < _interfaces.size(); i++)
    {
        if (_interfaces[i] == nullptr) continue;
        if (_interfaces[i]->getID() == id)
        {
            _interfaces[i]->clearInterface();
            _interfaces.erase(_interfaces.begin() + i);
            return;
        }
    }
}

std::vector<IUI*> UIManager::getInterfaces() const
{
    return _interfaces;
}

IUI* UIManager::getInterface(irr::s32 id) const
{
    for (auto i : getInterfaces())
	{
		if (i->getID() == id)
			return i;
	}
    return nullptr;
}
