/**
 * Entity.h:
 * Declaration for the Entity class
 * 
 * This class is the base class for all GameObjects that can be further classified as "entities". 
 * The definition this engine uses for entity is anything that can move in an 
 * inspecific manner and can have a health pool (players, enemies, npcs, etc.) as well as an animation.
 * 
 * @author Declan McGrellis
*/

#include <SDL.h>

#include "GameObject.h"
#include "Vector2.h"

namespace engine {

    class Entity : public GameObject {

        public:
            Entity(std::string filePath, int __health, uint __sWidth, uint __sHeight, uint __typeID);
            virtual void move();
            virtual void update(); // temp !!!!!
            int getHealth();
            uint getTypeID();
            virtual void animate(); // = 0 -> for later when i define how animation should work

        private:
            int health;
            uint typeID;
            Vector2<int> velocity;
            Vector2<int> acceleration;
    };

}