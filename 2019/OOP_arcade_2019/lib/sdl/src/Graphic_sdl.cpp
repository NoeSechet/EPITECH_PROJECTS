/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Graphic_sdl
*/

#include "Graphic_sdl.hpp"

namespace graphical {

    Graphic_sdl::Graphic_sdl()
        : m_name("sdl"), m_winSize(std::make_pair<uint, uint>(1920, 1080))
    {
        init();
    }

    Graphic_sdl::~Graphic_sdl()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(m_window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        std::cout << "Terminated sdl lib" << std::endl;
    }

    bool Graphic_sdl::init()
    {
        std::cout << "Initialized sdl lib" << std::endl;

        SDL_Init(SDL_INIT_VIDEO);
        TTF_Init();
        IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
        m_window = SDL_CreateWindow(m_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_winSize.first, m_winSize.second, SDL_WINDOW_OPENGL);
        renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        return true;
    }

    bool Graphic_sdl::initAssets(std::vector<IObjectToDraw *> assetList)
    {
        for (auto &asset : assetList) {
            if (isAlreadyLoaded(asset)) {
                std::cout << "already loaded" << std::endl;
                continue;
            }
            if (asset->getType() == IObjectToDraw::text) {
                m_assetList.push_back(new AssetSDL(asset->getId(), asset->getType(), asset->getPath(), asset->getSpritePos(), renderer));
            }
            if (CheckAssetPath(asset->getPath()) == true)
                m_assetList.push_back(new AssetSDL(asset->getId(), asset->getType(), asset->getPath(), asset->getSpritePos(), renderer));
        }
        return true;
    }

    bool Graphic_sdl::destroyAssets()
    {
        return true;
    }

    bool Graphic_sdl::destroy()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(m_window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return true;
    }

    COMMAND Graphic_sdl::getInput()
    {
        while (SDL_PollEvent(&m_event)) {
            if (m_event.window.event == SDL_WINDOWEVENT_CLOSE ||
                m_event.key.keysym.sym == SDLK_BACKSPACE) return EXIT;
            if (m_event.key.keysym.sym == SDLK_UP) return UP;
            if (m_event.key.keysym.sym == SDLK_DOWN) return DOWN;
            if (m_event.key.keysym.sym == SDLK_LEFT) return LEFT;
            if (m_event.key.keysym.sym == SDLK_RIGHT) return RIGHT;
            if (m_event.key.keysym.sym == SDLK_SPACE) return ACTION;
            if (m_event.key.keysym.sym == SDLK_q) return PREV_GRAPH;
            if (m_event.key.keysym.sym == SDLK_e) return NEXT_GRAPH;
            if (m_event.key.keysym.sym == SDLK_a) return PREV_GAME;
            if (m_event.key.keysym.sym == SDLK_d) return NEXT_GAME;
        }
        return NO_INPUT;
    }

    bool Graphic_sdl::draw(std::vector<IObjectToDraw *> objectList)
    {
        SDL_RenderClear(renderer);
        AssetSDL *assetPtr = nullptr;
        SDL_Texture *textptr = nullptr;
        SDL_Surface *surfPtr = nullptr;
        std::pair<uint, uint> objCoord = {0,0};
        SDL_Rect rect;

        for (auto &obj : objectList)
        {

            if ((assetPtr = getObjectContent(obj)) == nullptr) {
                continue;
            }
            if ((textptr = assetPtr->getTex()) == nullptr) {
                std::cout << "Sprite not found:" << obj->getId() << std::endl;
                continue;
            }

            if (assetPtr->getType() == IObjectToDraw::text) {
                surfPtr = TTF_RenderText_Solid(assetPtr->getFont(), obj->getValue().c_str(), {255, 255, 255, 255});
                textptr = SDL_CreateTextureFromSurface(renderer, surfPtr);
                SDL_FreeSurface(surfPtr);
            }

            std::tuple<uint,uint,uint,uint> color = obj->getColor();
            SDL_SetTextureColorMod(textptr, std::get<0>(color), std::get<1>(color), std::get<2>(color));

            objCoord = obj->getCoords();
            rect = assetPtr->getRect();
            rect.x = objCoord.first - std::get<2>(assetPtr->getSpritePos()) / 2;
            rect.y = objCoord.second - std::get<3>(assetPtr->getSpritePos()) / 2;
            if (assetPtr->getType() == IObjectToDraw::text) {
                rect.x += 80;
                rect.y += 30;
                SDL_QueryTexture(textptr, NULL, NULL, &rect.w, &rect.h);
            }
            SDL_RenderCopy(renderer, textptr, NULL, &rect);
        }
        SDL_RenderPresent(renderer);
        return true;
    }

    bool Graphic_sdl::isAlreadyLoaded(IObjectToDraw * object) const
    {
        for (auto &asset : m_assetList) {
            if (object->getId().compare(asset->getId()) == 0) {
                return true;
            }
        }
        return false;
    }

    AssetSDL *Graphic_sdl::getObjectContent(IObjectToDraw *object) const
    {
        for (auto asset : m_assetList) {
            if (object->getId().compare(asset->getId()) == 0) {
                return asset;
            }
        }
        return nullptr;
    }

    bool Graphic_sdl::CheckAssetPath(std::string path)
    {
        struct stat buffer;

        if (stat (path.append("texture.png").c_str(), &buffer) == 0) {
            return true;
        }
        return false;
    }

    extern "C" {
        IGraphicalInterface *entryPoint()
        {
            return new Graphic_sdl();
        }
    }
}