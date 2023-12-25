/**
 * Entity.cpp
 * Definition of the Entity class
 * 
 * This class is the base class for all GameObjects that can be further classified as "entities". 
 * The definition this engine uses for entity is anything that can move in an 
 * inspecific manner and can have a health pool (players, enemies, npcs, etc.) as well as an animation.
 * 
 * @author Declan McGrellis
*/

#include "Entity.h"

using namespace engine;

/**
 * Initialize the Entity class
 * Mostly forwards parameters down to parent constructors
 * 
 * @param filePath path to the file representing the entities spritesheet
 * @param __health the health the entity will have
 * @param __sWidth the width of the entity's sprite
 * @param __sHeight the height of the entity's sprite
 * @param __typeID a number representing the type of entity. Specific numbers will be associated with children of this class
*/
Entity::Entity(std::string filePath, int __health, uint __sWidth, uint __sHeight, uint __typeID) : GameObject(filePath, __sWidth, __sHeight, __typeID) {

    health = __health;
    typeID = __typeID;

    timer.start();
    velocity.x = 0;
    velocity.y = 0;
    acceleration.x = 0;
    acceleration.y = 0;

}

/** temp !!! */
void Entity::update() {
    move();
    timer.start();
}

/**
 * Move the entity by incrementing its position by its velocity over the amount of time has passed since the previous frame
*/
void Entity::move() {

    SDL_Point pos = getPosition();
    int x = pos.x;
    int y = pos.y;

    int dTime = timer.getTicks();

    setPosition(x + (velocity.x * dTime), y + (velocity.y * dTime));
}

/** Get the entity's health */
int Entity::getHealth() {
    return health;
}

/** Get the entity's type */
uint Entity::getTypeID() {
    return typeID;
}

/** temp */
void Entity::animate() {

}