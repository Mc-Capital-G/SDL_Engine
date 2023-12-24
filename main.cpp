#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::InputHandler handler;

    engine::Entity test("../IMG_3407.jpeg", 10, 459, 394, 0);

    test.setScale(100, 100);
    test.setAlignment(engine::RenderAlignment::TOP_LEFT);

    SDL_Event e;
    bool mPress = false;
    bool quit = false;
    while(!handler.pollInput()) {

        

        test.update();

        GameWindow.clearScreen();
        GameWindow.render(&test);
        GameWindow.renderPresent();

    }

    return 0;
}