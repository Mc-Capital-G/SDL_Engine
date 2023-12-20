/**
 * Timer.cpp
 * Definition of the Timer class
 * 
 * This class is a timer (duh). It holds a value that represents how long it has been (in ms) 
 * since the timer has started / been paused.
 * This can be used to calculate how much an object should move, as well as to count how many 
 * frames have passed since some arbitrary time.
 * 
 * @author Declan McGrellis
*/

#include "Timer.h"

using namespace engine;

/**
 * Initialize the timer and set all values to 0/false
*/
Timer::Timer() {
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

/**
 * Start the timer. Can be again after the initial call to "reset" the timer.
*/
void Timer::start() {
    startTicks = SDL_GetTicks64();
    pausedTicks = 0;
    started = true;
    paused = false;
}

/**
 * Stop the timer. This also resets all values to default (0 / false)
*/
void Timer::stop() {
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

/**
 * Pause the timer. Does nothing if the timer has not started / is already paused.
*/
void Timer::pause() {
    if(started && !paused) {
        paused = true;
        pausedTicks = SDL_GetTicks64() - startTicks;
        startTicks = 0;
    }
}

/**
 * Unpause the timer. Does nothing if the timer has not started / is already unpaused.
*/
void Timer::unpause() {
    if(started && paused) {
        paused = false;
        startTicks = SDL_GetTicks64() - pausedTicks;
        pausedTicks = 0;
    }
}

/**
 * Get the timer's value.
 * This value will be 0 if the timer has not been started.
 * This value it returns is time measured in milliseconds.
*/
int Timer::getTicks() {
    if(!started) return 0;
    if(paused) return pausedTicks;
    return SDL_GetTicks64() - startTicks;
}
