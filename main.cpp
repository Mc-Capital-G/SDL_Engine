#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::InputHandler handler;

    engine::Entity Chicken("../IMG_3407.jpeg", 3, 459, 394, 0);

    Chicken.setScale(100, 100);
    Chicken.setAlignment(engine::RenderAlignment::BOTTOM_LEFT);
    Chicken.setPosition(100, 720);

    while(!handler.pollInput()) {

        
        for(int i = 0; i < handler.pressedKeys.size(); i++) {
        
            switch(handler.pressedKeys[i]) {
                case SDL_SCANCODE_A:
                    
                    break;
                case SDL_SCANCODE_D:
                    
                    break;
                case SDL_SCANCODE_SPACE:
                    break;
            }
        }
        
        Chicken.update();

        GameWindow.clearScreen();
        GameWindow.render(&Chicken);
        GameWindow.renderPresent();

    }

    return 0;
}