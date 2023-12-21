/**
 * Level.h:
 * Declaration of the level class
 * 
 * This class is responsible for holding all data regarding a "level" in a game. 
 * This includes all GameObjects, as well as any menus, secrets, or other data that needs 
 * to be stored and represented in-game. Levels are normally loaded from a file, and can be fully 
 * initialized with the start function memeber
 * 
 * @author Declan McGrellis
*/

#include <vector>
#include <string>
#include <fstream>
#include "GameObject.h"
#include "Timer.h"

namespace engine {

    class Level {
        public:
            Level(std::string file);
            ~Level();
            bool run();
            void start();
            void end();

        private:
            std::vector<GameObject*> objectList;
            bool complete;
            Timer timer;
            std::string dataFile;
    };

}