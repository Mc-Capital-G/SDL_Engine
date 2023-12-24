/**
 * Text.h:
 * Declaration of the Text class
 * 
 * This class is a child of the RenderObject class, and is designed to hold data corresponding
 * to a specific string of text that we can draw to the screen.
 * 
 * @author Declan McGrellis
*/

#include <string>
#include "RenderObject.h"

namespace engine {

    class Text : public RenderObject {

        public:
            Text(std::string __text, std::string font, int fontSize, SDL_Color color, Uint32 wrapLength = 0);
            std::string getText();
            void setColor(SDL_Color color);
        private:
            std::string text;
    };

}