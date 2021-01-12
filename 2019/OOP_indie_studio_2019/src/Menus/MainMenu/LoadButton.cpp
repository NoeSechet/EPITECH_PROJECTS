/*
** EPITECH PROJECT, 2020
** LOADBUTTON_CPP
** File description:
** LOADBUTTON_CPP
*/

#include "../../../include/Menus/MainMenu/LoadButton.hpp"
#include "../../../include/Game.hpp"
#include "../../../include/Entities/IEntity.hpp"
#include "../../../include/Utils.hpp"
#include "../../../include/Entities/EntityEnumeration.hpp"

#include <string>

LoadButton::LoadButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(655,610,955,710), 0, GUI_ID_LOAD_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/LoadButton.png");
	_button->setImage(image);
};

irr::gui::IGUIButton *LoadButton::getButton()
{
	 return _button;
}


irr::core::vector3df LoadButton::getPosition(std::string str)
{
	size_t index = 0;
	irr::core::vector3df position;

	// Get X
	index = str.find(",");
	std::string X = str.substr(0, index);
	str = str.substr(index+1, str.find('\n'));
	// Get Y
	index = str.find(",");
	std::string Y = str.substr(0, index);
	str = str.substr(index+1, str.find('\n'));
	// Get Z
	index = str.find(",");
	std::string Z = str.substr(0, index);
	str = str.substr(index+1, str.find('\n'));
	try
	{
		position.X = std::stoi(X);
		position.Y = std::stoi(Y);
		position.Z = std::stoi(Z);
	}
	catch (std::invalid_argument const &e)
	{
		position.X = 0;
		position.Y = 0;
		position.Z = 0;
	}
	return position;
}

void LoadButton::saveEntity(irr::s32 id, irr::core::vector3df position)
{
	switch (id)
	{
		case OBSTACLE: _cubePos.push_back(position); break;
		case PLAYER: _nbPlayers += 1; break;
		case IA: _nbAI += 1; break;
		default: break;
	}
}

void LoadButton::fillGameList(Game *game)
{
	std::shared_ptr<Map> map = game->getMap();
	if (map) {
		for (auto position : _cubePos)
		{
			std::shared_ptr<Cube> newCube = std::make_shared<Cube>(
				game->getSManager(), game->getDriver(), game->getMap()->getTriSelector(), position,
				ID_rayPickable::IsPickable, true
			);
			game->getMap()->addCubeToMap(newCube);
			game->getListEntities().push_back(newCube);
		}
		// init borders and undestructible cubes
		for (unsigned int x = 0; x < 15; x++) {
			for (unsigned int y = 0; y < 15; y++) {
				if (map->isBorder(x,y) || (x % 2 == 0 && y % 2 == 0)) {
					std::shared_ptr<Cube> cube = map->placeCube(x, y, ID_rayPickable::IsPickable, false);
					game->getListEntities().push_back(cube);
					game->getMap()->addCubeToMap(cube);
				}
			}
		}
	}
}

void LoadButton::callback(Game *game)
{
	std::cout << "Load button pressed" << std::endl;

	std::vector <std::string> save = getFileContent("../save/save.txt");
	std::vector<std::shared_ptr<IEntity>> entities = game->getEntities();
	// Reset variables
	_nbPlayers = 0;
	_nbAI = 0;
	_cubePos.clear();

	// If the load did not work
	if (save.size() == 0)
		return;

	for (auto line : save)
	{
		irr::s32 id = std::stoi(line.substr(0, line.find(";")));
		irr::core::vector3df position = getPosition(line.substr(line.find(";") + 1, line.find("\n"))); // Send the end of the string, without the ID.
		saveEntity(id, position);
	}
	game->initLevel(_nbPlayers, _nbAI);
	game->getUIManager()->clear();
	game->setStatus(Game::State::Playing);
	fillGameList(game);
};