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

GameObject::GameObject(std::string filePath) : RenderObject(filePath) {

    hitbox = nullptr;

}

void GameObject::update() {

    std::cout << "This is the default definition of GameObject::update running!" << std::endl;

}

SDL_Rect* GameObject::getHitbox() {
    return hitbox;
}

bool GameObject::isCollidable() {
    return collision;
}



GameObject::~GameObject() {

    if(hitbox != nullptr) delete hitbox;

}