#include "Engine.h"
#include <iostream>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::RenderObject TestRender("../IMG_3407.jpeg");

    SDL_Event e;
    while(true) {

        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT) break;

        GameWindow.clearScreen();
        GameWindow.render(&TestRender);
        GameWindow.renderPresent();

    }

    return 0;
}