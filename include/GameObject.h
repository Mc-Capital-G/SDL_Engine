/**
 * GameObject.h:
 * Declaration of the GameObject class
 * 
 * This class is responsible for storing data related to any object we are going to interact with in a game. 
 * This should primarily only be a parent class for other implementations of classes we wish 
 * to use in a specific game
 * 
 * @author Declan McGrellis
*/

#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "RenderObject.h"
#include "Vector2.h"
#include "Timer.h"

namespace engine {

    class GameObject : public RenderObject {

        public:
            GameObject(std::string filePath);
            GameObject(std::string filePath, uint __sWidth, uint __sHeight);
            virtual void update() = 0;
            bool hasCollision();
            SDL_Rect getHitbox();
            Vector2<int> getVelocity();

            bool collision;
            SDL_Rect hitbox;
            Vector2<int> velocity;
            Vector2<int> acceleration;
            Timer timer;
            
    };

}

#endif