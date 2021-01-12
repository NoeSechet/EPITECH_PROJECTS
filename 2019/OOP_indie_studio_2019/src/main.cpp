/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include "../include/Game.hpp"
#include "../include/Menus/TitleScreen/TitleScreen.hpp"
#include "../include/EventReceiver.hpp"
#include "../include/Sound.hpp"

int main()
{
    std::unique_ptr<Game> bomberman = std::make_unique<Game>();
    irr::IrrlichtDevice* bomb_device = bomberman->getDevice();
    irr::video::IVideoDriver* bomb_driver = bomberman->getDriver();

    irr::scene::ISceneNode* highlightedSceneNode = 0;

    int lastFPS = -1;

	bomberman->getUIManager()->add(new TitleScreen(bomberman->getEnvironment(), bomb_driver));

    irr::u32 then = bomb_device->getTimer()->getTime();

    bomberman->gameSound->gameTheme.play();

	while (bomb_device->run() && bomberman->getStatus() != Game::State::Exit)
	{
        const irr::u32 now = bomb_device->getTimer()->getTime();
        const irr::f32 elapsedTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        if (bomberman->getStatus() == Game::State::Playing)
            bomberman->update(elapsedTime);
        if (bomberman->getStatus() == Game::State::Selection)
            bomberman->selection();
		if (bomb_device->isWindowActive())
        {
            bomberman->getDriver()->beginScene(true, true, 0);
            if (bomberman->getStatus() == Game::State::Playing || bomberman->getStatus() == Game::State::Pause)
                bomberman->getSManager()->drawAll();
		    bomberman->getEnvironment()->drawAll();

            bomb_driver->endScene();
            bomberman->displayFPS(lastFPS);
        }
        else {
            bomb_device->yield();
        }
	}
    bomberman->gameSound->gameTheme.stop();
    bomb_device->drop();
	return 0;
}