/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "Entities/Block.hpp"
#include "RNGenerator.hpp"

class Map {
    private:
        irr::scene::ISceneManager* _smgr = nullptr;
        irr::video::IVideoDriver* _driver = nullptr;
        irr::scene::IMetaTriangleSelector* _listTriSelectors = nullptr;

        std::vector<std::shared_ptr<Cube>> _listCubes;
        RNGenerator _rng;

    public:
        Map(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver);
        ~Map();

        irr::scene::IMetaTriangleSelector* getTriSelector() const { return _listTriSelectors; }
        std::vector<std::shared_ptr<Cube>> &getListCube() { return _listCubes; }

        bool proceduralGenCubes(std::vector<std::shared_ptr<IEntity>> &listEntities);
        std::shared_ptr<Cube> placeCube(unsigned int x, unsigned int y, ID_rayPickable, bool destructible);
        bool addCubeToMap(std::shared_ptr<Cube> newCube);
        bool isBorder(unsigned int x, unsigned int y);

    protected:
        bool isPlayerZone(unsigned int x, unsigned int y);
};

#endif /* !MAP_HPP_ */
