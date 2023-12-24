/**
 * InputHandler.h:
 * Declaration of the InputHandler class
 * 
 * This class is responsible for getting input from the user and providing easy to use functions to operate based off of the input
 * 
 * @author Declan McGrellis
*/

#include <SDL.h>
#include <vector>

namespace engine {

    class InputHandler {

        public:
            InputHandler();
            bool pollInput();
            SDL_Point getMousePosition();
            std::vector<SDL_Scancode> pressedKeys;

        private:
            SDL_Point mousePosition;

    };

}