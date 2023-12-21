#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");

    SDL_Event e;
    while(true) {

        SDL_PollEvent(&e);
        
        if(e.type == SDL_QUIT) break;

        GameWindow.clearScreen();
        GameWindow.renderPresent();

    }

    return 0;
}