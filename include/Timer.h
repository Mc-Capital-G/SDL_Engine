/**
 * Timer.h
 * Declaration of the Timer class
 * 
 * This class is responsible for counting time between frames. 
 * This can be used to calculate movement, as well as to count how many frames have passed since some arbitrary time.
 * 
 * @author Declan McGrellis
*/

#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL.h>

namespace engine {

    class Timer {
        public:
            Timer();
            void start();
            void stop();
            void pause();
            void unpause();
            int getTicks();
        private:
            int startTicks;
            int pausedTicks;
            bool started;
            bool paused;
    };

}

#endif