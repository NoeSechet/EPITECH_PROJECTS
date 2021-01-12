/*
** EPITECH PROJECT, 2020
** GAME_CPP
** File description:
** GAME_CPP
*/

#include "../include/Sound.hpp"

void Sound::loadGameTheme(void)
{
    if (!this->gameThemeBuffer.loadFromFile("../wav/game_theme.wav"))
        throw std::logic_error("Error: loading sound game_theme.wav failed!");
    
    this->gameTheme.setBuffer(this->gameThemeBuffer);
    this->gameTheme.setLoop(true);
}

void Sound::loadClickSound(void)
{
    if (!this->buttonClickBuffer.loadFromFile("../wav/click_01.wav"))
        throw std::logic_error("Error: loading sound click_01.wav failed!");
    
    this->buttonClick.setBuffer(this->buttonClickBuffer);
    this->buttonClick.setLoop(false);
}

void Sound::loadExplosionSound(void)
{
    if (!this->explosionBuffer.loadFromFile("../wav/explosion.wav"))
        throw std::logic_error("Error: loading sound explosion.wav failed!");
    
    this->explosionSound.setBuffer(this->explosionBuffer);
    this->explosionSound.setLoop(false);
}