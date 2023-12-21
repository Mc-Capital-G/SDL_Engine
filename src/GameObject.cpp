/**
 * GameObject.cpp:
 * Definition of the GameObject class
 * 
 * This class is responsible for storing data related to any object we are going to interact with in a game. 
 * This should primarily only be a parent class for other implementations of classes we wish 
 * to use in a specific game
 * 
 * @author Declan McGrellis
*/

#include <iostream>
#include "GameObject.h"

using namespace engine;

/**
 * Initialize the GameObject. All pointers are initialized as nullptr.
 * @param filePath just forwards to the RenderObject's constructor
*/
GameObject::GameObject(std::string filePath) : RenderObject(filePath) {

    hitbox = nullptr;

}

/**
 * Get the object's hitbox
*/
SDL_Rect* GameObject::getHitbox() {
    return hitbox;
}

/**
 * Get the object's velocity.
*/
Vector2<int> GameObject::getVelocity() {
    return velocity;
}

/**
 * See if the GameObject has collision
*/
bool GameObject::hasCollision() {
    return collision;
}

/**
 * Destroy the GameObject
*/
GameObject::~GameObject() {

    if(hitbox != nullptr) delete hitbox;

}