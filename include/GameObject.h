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

namespace engine {

    class GameObject : RenderObject {

        public:
            GameObject();
            virtual ~GameObject();
            virtual void update();
            bool isCollidable();
            SDL_Rect* getHitbox();
        private:
            bool collision;
            SDL_Rect* hitbox;
            Vector2<int> velocity;
            Vector2<int> acceleration;
            Timer timer;
            
    };

}

#endif