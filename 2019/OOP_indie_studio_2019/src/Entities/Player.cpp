/*
** EPITECH PROJECT, 2020
** src
** File description:
** Player
*/

#include "../../include/Entities/Player.hpp"
#include "../../include/EventReceiver.hpp"

Player::Player(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* driver, EventReceiver* eventReceiver, irr::scene::IMetaTriangleSelector* listTriSelectors)
    : _smgr(smgr), _driver(driver), _listTriSelectors(listTriSelectors), _eventReceiver(eventReceiver)
{
    if (smgr == nullptr|| driver == nullptr || listTriSelectors == nullptr)
        throw std::logic_error("Player constructor error: invalid scene/driver/collision list");
    _playerMesh = smgr->addMeshSceneNode(smgr->getMesh("../asset/chaffee_tank.obj"), 0, ID_rayPickable::IsPickable);

    irr::video::SMaterial material = irr::video::SMaterial();
    _playerMesh->setMaterialTexture(0, driver->getTexture("../asset/gray_blue.jpg"));

    _playerMesh->setTriangleSelector(_smgr->createTriangleSelector(_playerMesh->getMesh(), _playerMesh));

    if (listTriSelectors)
    {
        irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(
            listTriSelectors, _playerMesh, irr::core::vector3df(10.0f, 10.0f, 10.0f),
            irr::core::vector3df(0, -10, 0)
        );
        _playerMesh->addAnimator(anim);
        anim->drop();
    }
    _reloadTimer.start();
    _rateOfFire.start();
    _scorePtr = &_score;
}

irr::core::vector3df Player::getPosition() const
{
    if (_playerMesh != nullptr)
        return _playerMesh->getPosition();
    else
        return irr::core::vector3df();
}
void Player::setPosition(irr::core::vector3df pos)
{
    if (_playerMesh != nullptr)
        _playerMesh->setPosition(pos);
}

bool Player::update(float elapsedTime)
{
    irr::core::vector3df nodePosition = this->getPosition();

    if (_eventReceiver->IsKeyDown(_keyMap[0])) {
        nodePosition.X -= _speed * elapsedTime;
        _playerMesh->setRotation(irr::core::vector3df(0.0f, -90.0f, 0.0f));
    }
    else if (_eventReceiver->IsKeyDown(_keyMap[1])) {
        nodePosition.X += _speed * elapsedTime;
        _playerMesh->setRotation(irr::core::vector3df(0.0f, 90.0f, 0.0f));
    }
    if (_eventReceiver->IsKeyDown(_keyMap[2])) {
        nodePosition.Z -= _speed * elapsedTime;
        _playerMesh->setRotation(irr::core::vector3df(0.0f, 180.0f, 0.0f));
    }
    else if (_eventReceiver->IsKeyDown(_keyMap[3])) {
        nodePosition.Z += _speed * elapsedTime;
        _playerMesh->setRotation(irr::core::vector3df(0.0f, 0.0f, 0.0f));
    }
    if (_eventReceiver->IsKeyDown(_keyMap[4]) && _nbLoadedBombs > 0 && _rateOfFire.getElapsedSeconds() > 0.3) {
        _isBombing = true;
        _rateOfFire.restart();
    }
    if (_reloadTimer.getElapsedSeconds() > 2 && _nbLoadedBombs < _magSize) {
        _nbLoadedBombs += 1;
        _reloadTimer.restart();
    }
    this->setPosition(nodePosition);
    return true;
}

void Player::bindKeyMovements(const std::vector<irr::EKEY_CODE> keyMap)
{
    for (size_t i = 0; i < keyMap.size(); i += 1) {
        _keyMap.push_back(keyMap[i]);
    }
}

void Player::putBomb(std::vector<std::shared_ptr<IEntity>> &listEntities)
{
    if (_isBombing && _nbLoadedBombs > 0) {
        std::shared_ptr<Bomb> bomb = std::make_shared<Bomb>(_smgr, _driver, _listTriSelectors, _firePower);
        bomb->setPosition(this->getPosition());
        bomb->setOwner(_playerMesh, _scorePtr);
        listEntities.push_back(bomb);
        setBombing(false);
        _nbLoadedBombs -= 1;
    }
}