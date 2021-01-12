/*
** EPITECH PROJECT, 2020
** ENTITYENUMERATION_HPP
** File description:
** ENTITYENUMERATION_HPP
*/

#ifndef ENTITYENUMERATION_HPP
#define ENTITYENUMERATION_HPP

enum ID_rayPickable {
    // use this ISceneNode ID to indicate a scene node that is
    // not pickable by getSceneNodeAndCollisionPointFromRay()
    IsNotPickable = 0,
    // use this flag in ISceneNode IDs to indicate that the
    // scene node can be picked by ray selection.
    IsPickable = 1 << 0
};

enum POWER_TYPE {
    NO_POWER,
    INTENSITY,
    SPEED,
    MAG_SIZE
};

enum EntityType
{
    PLAYER = 301,
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4,
    OBSTACLE,
    IA,
    BOMB,
    POWER,
    BLAST,
    ENTITY,
};

#endif /* !ENTITYENUMERATION_HPP */
