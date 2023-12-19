/**
 * TextBox.h:
 * Declaration of the TextBox class
 * 
 * This class is responsible for being a text box, which is just a RenderObject that is just text.
 * 
 * @author Declan McGrellis
*/

#include <string>
#include "RenderObject.h"

namespace engine {

    class TextBox : RenderObject {

        public:
            TextBox(std::string displayText);
    
        private:
            std::string text;
    };

}