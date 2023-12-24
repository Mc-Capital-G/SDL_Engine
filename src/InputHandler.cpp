/**
 * InputHandler.cpp:
 * Definition of the InputHandler class
 * 
 * This class is responsible for getting input from the user and providing easy to use functions to operate based off of the input
 * 
 * @author Declan McGrellis
*/

#include "InputHandler.h"

using namespace engine;

/** 
 * Initialize the object
*/
InputHandler::InputHandler() {

    pressedKeys = { };
    int x, y;
    SDL_GetMouseState(&x, &y);
    mousePosition.x = x;
    mousePosition.y = y;

}

/**
 * Poll all SDL events and save input
 * Pressed keys are stored separately from mouse presses due to SDL differences. 
 * This works out anyway because the keyboard and mouse do different things, so we can 
 * poll them differently using the class more effectively.
*/
bool InputHandler::pollInput() {

    SDL_Event event;

    while(SDL_PollEvent(&event)) { 
        
        bool heldInput = false;
        std::vector<SDL_Scancode>::iterator keyPtr = pressedKeys.begin();
        std::vector<Uint8>::iterator mousePtr = mouseEvents.begin();

        switch(event.type) {

            case SDL_QUIT: return true;

            case SDL_KEYDOWN:

                heldInput = false;
                for(int i = 0; i < pressedKeys.size(); i++) {
                    if(pressedKeys[i] == event.key.keysym.scancode) heldInput = true;
                }
                if(!heldInput) pressedKeys.push_back(event.key.keysym.scancode);
                break;

            case SDL_KEYUP:
                
                for(int i = 0; i < pressedKeys.size(); i++) {
                    if(pressedKeys[i] == event.key.keysym.scancode) pressedKeys.erase(keyPtr + i);
                }
                break;

            case SDL_MOUSEBUTTONDOWN: // mouse button was pressed
                
                heldInput = false;
                for(int i = 0; i < mouseEvents.size(); i++) {
                    if(mouseEvents[i] == event.button.button) heldInput = true;
                }
                if(!heldInput) mouseEvents.push_back(event.button.button);
                break;

            case SDL_MOUSEBUTTONUP: // mouse button was unpressed
            
                for(int i = 0; i < mouseEvents.size(); i++) {
                    if(mouseEvents[i] == event.button.button) mouseEvents.erase(mousePtr + i);
                }
                break;

        }
    }

    return false;
}

/** Get the position of the mouse */
SDL_Point InputHandler::getMousePosition() {

    int x, y;
    SDL_GetMouseState(&x, &y);
    mousePosition.x = x;
    mousePosition.y = y;

    return mousePosition;
}

