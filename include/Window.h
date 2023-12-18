/**
 * Window.h:
 * Declaration of the Window class.
 * This class is responsible for managing the window of the program and drawing/displaying objects to the screen.
 * 
 * @author Declan McGrellis
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "RenderObject.h"

namespace engine {

    class Window {
            
        public:
            Window(const char *title, int screenWidth = 1280, int screenHeight = 720);
            ~Window();
            void render(RenderObject* obj);
            void renderPresent();
            void clearScreen();
        
        private:
            SDL_Renderer* renderer;
            SDL_Window* window;
            int height;
            int width;

    };

}

#endif