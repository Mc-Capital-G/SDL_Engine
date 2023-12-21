#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::RenderObject test("../IMG_3407.jpeg");

    SDL_Event e;
    bool mPress = false;
    while(true) {

        SDL_PollEvent(&e);
        
        if(e.type == SDL_QUIT) break;
        if(e.type == SDL_MOUSEBUTTONDOWN) mPress = true;
        if(e.type == SDL_MOUSEBUTTONUP) mPress = false;

        int x, y;
        SDL_GetMouseState(&x, &y);
        if(mPress) test.setPosition(x, y);

        GameWindow.clearScreen();
        GameWindow.render(&test);
        GameWindow.renderPresent();

    }

    return 0;
}