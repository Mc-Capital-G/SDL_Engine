/**
 * Window.cpp:
 * Definition of the Window class.
 * This class is responsible for managing the window of the program and drawing/displaying objects to the screen.
 * 
 * @author Declan McGrellis
 * @cite Lazy Foo Productions 
*/

#include "Window.h"

using namespace engine;

/**
 * Initialize the Window and a rendering context for the program. Also initialize the SDL Library and it's subsytems
 * Logs any errors to the console
 * 
 * @param title name of the window. Passed as a const char* because SDL was written in C, and therefore uses C strings
 * @param screenWidth initial width of the window
 * @param screenHeight initial height of the window
*/
Window::Window(const char *title, int screenWidth, int screenHeight) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { //initialize SDL
		SDL_Log("SDL could not be initialized. SDL Error: %s\n", SDL_GetError());
	}
	else {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_INPUT_FOCUS); //create window
		if (window == NULL) {
			SDL_Log("SDL Window could not be created. SDL Error: %s\n", SDL_GetError());
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC); //create renderer
			if (renderer == NULL) {
				SDL_Log("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
			}
			else { //initialize SDL Subsystems

				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00); //initialize default render color

				int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG; //flags to give to SDL_image init function - defines what extensions can be loaded 
				if (IMG_Init(imgFlags) != imgFlags) { //initialize SDL_image
					SDL_Log("SDL Image could not be initialized. SDL Error: %s\n", SDL_GetError());
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) { //initialize SDL_mixer
					SDL_Log("SDL Mixer could not initialize. SDL Error: %s\n", SDL_GetError());
				}

				if (TTF_Init() == -1) { //initialize SDL_ttf
					SDL_Log("SDL ttf could not not initialize. SDL Error: %s\n", SDL_GetError());
					
				}
			}
		}
	}
}

/**
 * Render an object to the screen
 * 
 * If the RenderObject does not have a defined texture, attempt to generate one from the object's surface.
 * 
 * Forwards to SDL_RenderCopyEx while passing the window renderer and all of the object's data - 
 * means you don't have to call a function with 7 arguments every time you want to render something.
 * 
 * @param obj desired object to render
*/
void Window::render(RenderObject* obj) {

	if(obj->getTexture() == nullptr) {
		SDL_Texture* newTex = SDL_CreateTextureFromSurface(renderer, obj->getSurface());
		obj->setTexture(newTex);
	}

	SDL_RenderCopyEx(renderer, obj->getTexture(), obj->getClip(), obj->getPosition(), obj->getAngle(), obj->getRotatePoint(), obj->getFlip());

}

/**
 * Render the existing buffer to the screen
 * Forwards to SDL_RenderPresent while passing the window renderer
*/
void Window::renderPresent() {

	SDL_RenderPresent(renderer);

}

/**
 * Empty the rendering buffer for the screen, effectively "clearing" it
 * Forwards to SDL_RenderClear() and passes the window renderer
*/
void Window::clearScreen() {

	SDL_RenderClear(renderer);

}

/**
 * Destroy the Window, its renderer, and shutdown all SDL subsystems
*/
Window::~Window() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	IMG_Quit();
	Mix_Quit();
	TTF_Quit();
}
