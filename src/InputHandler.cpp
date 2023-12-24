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
*/
bool InputHandler::pollInput() {

    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        std::vector<SDL_Scancode>::iterator ptr = pressedKeys.begin(); 
        switch(event.type) {
            case SDL_QUIT:
                return true;
            case SDL_KEYDOWN:
                for(int i = 0; i < pressedKeys.size(); i++) {
                    if(pressedKeys[i] == event.key.keysym.scancode) break;
                }
                pressedKeys.emplace_back(event.key.keysym.scancode);
                break;
            case SDL_KEYUP:
                for(int i = 0; i < pressedKeys.size(); i++) {
                    if(pressedKeys[i] == event.key.keysym.scancode) pressedKeys.erase(ptr + i);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                switch(event.button.button) {
                    case SDL_BUTTON_LEFT:
                        break;
                    case SDL_BUTTON_RIGHT:
                        break;
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

