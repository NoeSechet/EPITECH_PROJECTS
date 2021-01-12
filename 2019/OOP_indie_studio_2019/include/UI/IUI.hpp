/*
** EPITECH PROJECT, 2020
** IUI_HPP
** File description:
** IUI_HPP
*/

#ifndef IUI_HPP
#define IUI_HPP

#include <vector>

#include "IButton.hpp"
#include "UIEnumeration.hpp"

class IUI {
    public:
        virtual std::vector<IButton *> getVectorButton() = 0;
        virtual irr::s32 getID() = 0;
        virtual void clearInterface() = 0;
};

#endif /* !IUI_HPP */
