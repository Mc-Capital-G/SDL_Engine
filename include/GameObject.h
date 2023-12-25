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
#include "Timer.h"

namespace engine {

    class GameObject : public RenderObject {

        public:
            GameObject(std::string filePath, uint __typeID);
            GameObject(std::string filePath, uint __sWidth, uint __sHeight, uint __typeID);
            virtual void update() = 0;
            bool hasCollision();
            void setCollision(bool __collision);
            SDL_Rect getHitbox();

            bool collision;
            SDL_Rect hitbox;
            uint typeID;
            Timer timer;
            
    };

}

#endif