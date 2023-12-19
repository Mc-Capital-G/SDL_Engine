/**
 * Button.h:
 * The Declaration of the Button class
 * 
 * This class is responsible for holding data associated with a button, such as whether it is pressed, able to be pressed, displayed, etc.
 * 
 * @author Declan McGrellis
*/

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <string>
#include "RenderObject.h"

namespace engine {

    class Button : RenderObject {
        
        public:
            Button();
            
            std::string getLabel();
            bool isSelected();
            void select();
            void unselect();

        private:
            bool selected;
            std::string label;
    };

}

#endif