/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AssetsSDL
*/

#ifndef ASSETSSDL_HPP_
#define ASSETSSDL_HPP_

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <memory>
#include <tuple>

#include "../../../GlobalHeaders.hpp"

class AssetSDL : public IObjectToDraw {
    private:
        std::string m_id;
        Type m_type = objects;
        std::string m_value = " ";
        SDL_Texture *m_tex = nullptr;
        SDL_Rect m_rect = {0, 0, 0, 0};
        std::tuple<uint, uint, uint, uint> rect;
        std::tuple<uint, uint, uint, uint> m_color = {255,255,255,255};
        TTF_Font *m_font = nullptr;
        SDL_Surface *surfaceMessage = nullptr;

    public:
        AssetSDL(const std::string &id, Type type, const std::string &path, std::tuple<uint, uint, uint, uint> sprRec, SDL_Renderer *renderer)
            : m_id(id), m_type(type), rect(sprRec)
        {
            std::string filepath = path; 
            if (filepath[filepath.size() - 1] != '/')
                filepath = filepath + "/";
            if (type == objects) {
                filepath = filepath + "texture.png";
                if (!(m_tex = IMG_LoadTexture(renderer, filepath.c_str())))
                    throw std::logic_error("Texture not found. Maybe the given path is invalid");
                m_rect.x = std::get<0>(sprRec);
                m_rect.y = std::get<1>(sprRec);
                m_rect.w = std::get<2>(sprRec);
                m_rect.h = std::get<3>(sprRec);
                SDL_QueryTexture(m_tex, NULL, NULL, &m_rect.w, &m_rect.h);
            }
            if (type == text) {
                filepath = filepath + "font.ttf";
                if (!(m_font = TTF_OpenFont(filepath.c_str(), 22)))
                    throw std::logic_error("Texture not found. Maybe the given path is invalid");
                m_rect.x = std::get<0>(sprRec);
                m_rect.y = std::get<1>(sprRec);
                m_rect.w = std::get<2>(sprRec);
                m_rect.h = std::get<3>(sprRec);
                surfaceMessage = TTF_RenderText_Solid(m_font, getValue().c_str(), {255, 255, 255, 255});
                m_tex = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
                SDL_QueryTexture(m_tex, NULL, NULL, &m_rect.w, &m_rect.h);
                SDL_FreeSurface(surfaceMessage);
            }
        };
        ~AssetSDL() {};

        std::string getId() const { return m_id; };
        std::string getPath() const { return std::string(""); };
        Type getType() const {return m_type; };
        std::string getValue() const { return m_value; };
        std::pair<long int, long int> getCoords() const { return std::make_pair<uint, uint>(m_rect.x, m_rect.y); };
        SDL_Texture *getTex() const { return m_tex; }
        std::tuple <uint, uint, uint, uint> getSpritePos() const { return rect; }
        std::tuple<uint, uint, uint, uint> getColor() const { return m_color; }
        SDL_Rect getRect() const { return m_rect; }
        TTF_Font *getFont() const { return m_font; }
};

#endif /* !ASSETSSDL_HPP_ */
