#include "Engine.h"
#include <iostream>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::GameObject test("../IMG_3407.jpeg");

    SDL_Event e;
    bool mousepress = false;
    while(true) {

        SDL_PollEvent(&e);

        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_MOUSEBUTTONDOWN) mousepress = true;
        if(e.type == SDL_MOUSEBUTTONUP) mousepress = false;

        int x, y;
        SDL_GetMouseState(&x, &y);

        if(mousepress) test.setPosition(x, y);

        GameWindow.clearScreen();
        GameWindow.render(&test);
        GameWindow.renderPresent();

    }

    return 0;
}