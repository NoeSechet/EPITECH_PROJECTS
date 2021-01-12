/*
** EPITECH PROJECT, 2020
** SAVEBUTTON_CPP
** File description:
** SAVEBUTTON_CPP
*/

#include "../../include/UI/SaveButton.hpp"
#include "../../include/Game.hpp"
#include "../../include/Entities/IEntity.hpp"

#include <iostream>
#include <string>
#include <fstream>

SaveButton::SaveButton(irr::gui::IGUIEnvironment* env, irr::video::IVideoDriver *driver)
:  _env(env)
{
	_button = _env->addButton(irr::core::rect<irr::s32>(810,490,1110,590), 0, GUI_ID_SAVE_BUTTON);
	irr::video::ITexture* image = driver->getTexture("../asset/menus/SaveButton.png");
	_button->setImage(image);
}

irr::gui::IGUIButton *SaveButton::getButton()
{
	 return _button;
}

void SaveButton::callback(Game *game)
{
	std::cout << "Save button pressed" << std::endl;

	std::ofstream save("../save/save.txt");
	std::vector<std::shared_ptr<IEntity>> entities = game->getEntities();

	for (auto entity : entities)
	{
		if (!entity)
			continue;
		if (entity->getType() == EntityType::OBSTACLE && std::static_pointer_cast<Cube>(entity)->isDestructible() == false) {
			continue;
		}
		irr::core::vector3df pos = entity->getPosition();

		save << std::to_string(entity->getType()) << ";";
		save << std::to_string(pos.X) << ",";
		save << std::to_string(pos.Y) << ",";
		save << std::to_string(pos.Z);
		save << std::endl;
	}
	save.close();
}