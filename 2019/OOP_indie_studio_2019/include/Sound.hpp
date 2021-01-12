/*
** EPITECH PROJECT, 2020
** ENTITY_HPP
** File description:
** SOUND_HPP
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio.hpp>

class Sound {
    private:
        sf::SoundBuffer gameThemeBuffer;
        sf::SoundBuffer buttonClickBuffer;
        sf::SoundBuffer explosionBuffer;

    public:
        sf::Sound gameTheme;
        sf::Sound buttonClick;
        sf::Sound explosionSound;

        Sound() {};
        void loadGameTheme(void);
        void loadClickSound(void);
        void loadExplosionSound(void);
};

#endif /* !SOUND_HPP */