/**
 * Vector2.cpp
 * Definition of the Vector2 class
 * 
 * This is a template class that stores data for a vector object (NOT the list) that can have x and y magnitudes.
 * Designed that it can be used for int, double, float, or other number based data types.
 * 
 * @author Declan McGrellis
*/

#include "Vector2.h"

using namespace engine;

template <typename T> Vector2<T>::Vector2(T X, T Y) {
    x = X;
    y = Y;
}