/**
 * Level.cpp:
 * Definition of the Level class
 * 
 * This class is responsible for holding all data regarding a "level" in a game. 
 * This includes all GameObjects, as well as any menus, secrets, or other data that needs 
 * to be stored and represented in-game.
 * 
 * @author Declan McGrellis
*/

#include "Level.h"

using namespace engine;

/**
 * Initialize the level
 * 
 * Level.start() will actually load all the level data such as objects, backgrounds, etc.
*/
Level::Level(std::string file) {
    dataFile = file;
    complete = false;
}

/**
 * Run the level.
 * 
 * Updates game objects and manages the level's runtime
 * 
 * @return if the level was completed or not
*/
bool Level::run() {
    
    for(int i = 0; i < objectList.size(); i++) {
        objectList[i]->update();
    }

    return complete;
}

/**
 * Destruct the level
*/
Level::~Level() {
    for(int i = 0; i < objectList.size(); i++) delete objectList[i];
}