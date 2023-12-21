#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::RenderObject test("../IMG_3407.jpeg");

    SDL_Event e;
    bool mPress = false;
    bool quit = false;
    while(!quit) {

        while(SDL_PollEvent(&e)) {
            switch(e.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mPress = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                    mPress = false;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.scancode) {
                        case SDL_SCANCODE_1:
                            test.setAlignment(engine::RenderAlignment::TOP_LEFT);
                            break;
                        case SDL_SCANCODE_2:
                            test.setAlignment(engine::RenderAlignment::TOP_RIGHT);
                            break;
                        case SDL_SCANCODE_3:
                            test.setAlignment(engine::RenderAlignment::CENTER);
                            break;
                        case SDL_SCANCODE_4:
                            test.setAlignment(engine::RenderAlignment::BOTTOM_LEFT);
                            break;
                        case SDL_SCANCODE_5:
                            test.setAlignment(engine::RenderAlignment::BOTTOM_RIGHT);
                            break;
                    }
                    break;
            }
        }

        int x, y;
        SDL_GetMouseState(&x, &y);
        if(mPress) test.setPosition(x, y);

        GameWindow.clearScreen();
        GameWindow.render(&test);
        GameWindow.renderPresent();

    }

    return 0;
}