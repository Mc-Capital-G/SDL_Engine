/**
 * Menu.h:
 * Declaration of the Menu class
 * 
 * Instances of this class are responsible for holding data associated with a menu and doing other normal menu things
 * 
 * @author Declan McGrellis
*/

#ifndef __MENU_H__
#define __MENU_H__

#include <vector>
#include <string>
#include "RenderObject.h"
#include "Button.h"

namespace engine {

    class Menu : RenderObject {

        public:
            Menu();
            ~Menu();

            void handle();
            Button* getSelectedButton();
            std::string getName();

        private:
            std::vector<Button*> buttonList;
            std::string name;

    };

}

#endif