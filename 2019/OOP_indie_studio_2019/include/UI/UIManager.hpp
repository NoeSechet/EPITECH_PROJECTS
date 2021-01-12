/*
** EPITECH PROJECT, 2020
** UIManager
** File description:
** UIManager
*/

#ifndef UIManager_HPP
#define UIManager_HPP

#include <vector>

#include "IUI.hpp"

class UIManager {
    private:
        std::vector<IUI*> _interfaces;
    public:
        UIManager();
        ~UIManager();

        void add(IUI* interface);
        void clear();
        void clear(irr::s32 id);
        std::vector<IUI*> getInterfaces() const;
        IUI* getInterface(irr::s32 id) const;
};

#endif /* !UIManager_HPP */