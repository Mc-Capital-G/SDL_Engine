#include "Engine.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {

    engine::Window GameWindow("Game");
    engine::InputHandler handler;

    engine::Text TitleTest("This is some test text!", "../PublicPixel.ttf", 16, {0, 0, 0, 0});
    TitleTest.setAlignment(engine::RenderAlignment::TOP_LEFT);
    TitleTest.setPosition(100, 100);

    engine::Entity Chicken("../IMG_3407.jpeg", 3, 459, 394, 0);
    Chicken.setScale(100, 100);
    Chicken.setAlignment(engine::RenderAlignment::BOTTOM_LEFT);
    Chicken.setPosition(100, 720);

    while(!handler.pollInput()) {

        
        for(int i = 0; i < handler.pressedKeys.size(); i++) {
        
            switch(handler.pressedKeys[i]) {
                case SDL_SCANCODE_D:
                    TitleTest.setColor({0, 255, 0, 0});
                    break;
                case SDL_SCANCODE_A:
                    TitleTest.setColor({0, 0, 255, 0});
                    break;
                case SDL_SCANCODE_SPACE:
                    TitleTest.setColor({255, 0, 0, 0});
                    break;
            }
        }
        
        Chicken.update();

        GameWindow.clearScreen();
        GameWindow.render(&Chicken);
        GameWindow.render(&TitleTest);
        GameWindow.renderPresent();

    }

    return 0;
}