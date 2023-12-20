/**
 * Vector2.h
 * Declaration of the Vector2 class
 * 
 * This is a template class that stores data for a vector object (NOT the list) that can have x and y magnitudes.
 * Designed that it can be used for int, double, float, or other number based data types.
 * 
 * @author Declan McGrellis
*/

#ifndef __VECTOR2_H__
#define __VECTOR2_H__

namespace engine {

    template <typename T> class Vector2 {
        public:
            Vector2(T x, T y);
            T x;
            T y;
    };

}

#endif