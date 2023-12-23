/**
 * RenderObject.h:
 * Definition of the RenderObject class
 * 
 * This class is responsible for storing data associated with any object we wish to render to the screen.
 * Most other objects we wish to manipulate and also display to the screen will likely be children of this class.
 * 
 * @author Declan McGrellis
*/

#include "RenderObject.h"

using namespace engine;

/**
 * Initialize the RenderObject
 * 
 * Most values will default to NULL or zero for consistency, and can be changed later with other object member functions
 * An SDL_Surface is initially created upon object initialization, while the SDL_Texture is initialized as nullptr. This 
 * is because we need a renderer to generate a texture, and we will generate the texture when we eventually give it to a 
 * window object for rendering, where the surface will then be converted and destroyed.
 *  
 * @param filePath the path to the file that should be the source for the texture of the object
 * @param __sWidth explicity declares the width of the texture for the object, used for children that require such a definition
 * @param __sHeight explicity declares the height of the texture for the object, used for children that require such a definition
*/
RenderObject::RenderObject(std::string filePath, uint __sWidth, uint __sHeight) {

    texture = nullptr;
    alignment = CENTER;
    flip = SDL_FLIP_NONE;
    rotateAngle = 0;
    hidden = false;

    surface = IMG_Load(filePath.c_str());

    width = __sWidth;
    height = __sHeight;

    position.x = 0;
    position.y = 0;

    target.x = 0;
    target.y = 0;
    target.w = width;
    target.h = height;

    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;

}

/**
 * Initialize the RenderObject
 * 
 * Most values will default to NULL or zero for consistency, and can be changed later with other object member functions
 * An SDL_Surface is initially created upon object initialization, while the SDL_Texture is initialized as nullptr. This 
 * is because we need a renderer to generate a texture, and we will generate the texture when we eventually give it to a 
 * window object for rendering, where the surface will then be converted and destroyed.
 *  
 * @param filePath the path to the file that should be the source for the texture of the object
*/
RenderObject::RenderObject(std::string filePath) {

    texture = nullptr;
    alignment = CENTER;
    flip = SDL_FLIP_NONE;
    rotateAngle = 0;
    hidden = false;

    surface = IMG_Load(filePath.c_str());

    width = surface->w;
    height = surface->h;

    position.x = 0;
    position.y = 0;

    target.x = 0;
    target.y = 0;
    target.w = width;
    target.h = height;

    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;

}

/**
 * Change the position of the RenderObject. 
 * 
 * The position defines where on the screen the object will be rendered.
 * This function also calculates position based on the object's alignment
 * 
 * @param x new x position
 * @param y new y position
*/
void RenderObject::setPosition(int x, int y) {

    position.x = x;
    position.y = y;

    // offset x and y based on the alignment of the object
    switch(alignment) {
        case TOP_LEFT:
            target.x = x;
            target.y = y;
            break;
        case TOP_RIGHT:
            target.x = x - target.w;
            target.y = y;
            break;
        case CENTER:
            target.x = x - target.w/2;
            target.y = y - target.h/2;
            break;
        case BOTTOM_LEFT:
            target.x = x;
            target.y = y - target.h;
            break;
        case BOTTOM_RIGHT:
            target.x = x - target.w;
            target.y = y - target.h;
            break;
    }
   
}

/** 
 * Set the rendering scale for the object. 
 * These values cannot be negative 
*/
void RenderObject::setScale(uint w, uint h) {
    
    target.w = w;
    target.h = h;
}

/**
 * Set the rendering clip for the RenderObject.
 * The clip defines what section of the objects texture should be displayed. 
 * If it is NULL, the full texture will be displayed. 
 * 
 * Clip values cannot be negative, and thus are unsigned.
 * 
 * @param x new x position 
 * @param y new y position
*/
void RenderObject::setClip(uint x, uint y) {

    clip.x = x;
    clip.y = y;

}

/**
 * Reset the RenderObject clip to 
*/
void RenderObject::resetClip() {
    clip.x = 0;
    clip.y = 0;
}

/**
 * Set the texture of the RenderObject
 * 
 * Should be mainly called to set the texture when the texture has not been initialized, 
 * but it is valid to use this elsewhere. Free the current surface that the object has if any.
 * 
 * @param tex the texture to assign to the RenderObject - CANNOT BE NULL
*/
void RenderObject::setTexture(SDL_Texture* tex) {

    if(tex == nullptr) return;

    if(texture != nullptr) SDL_DestroyTexture(texture);

    texture = tex;

    if(surface != nullptr) {
        // SDL_FREESURFACE LEAVES A HANGING POINTER ! ALWAYS SET TO NULLPTR OR SEGFAULT WILL HAPPEN
        SDL_FreeSurface(surface);
        surface = nullptr;
    }

}

/**
 * Set the RenderObject's alignment
 * 
 * alignment defines where the object's position is defined on the RenderObject. For example, 
 * center alignment means that the object's x,y position is measured at the center of the object.
*/
void RenderObject::setAlignment(RenderAlignment newAlignment) {
    alignment = newAlignment;
}

/**
 * Set the object's flip status
*/
void RenderObject::setFlip(SDL_RendererFlip __flip) {
    flip = __flip;
}

/**
 * Get the RenderObject's texture
 * */
SDL_Texture* RenderObject::getTexture() {
    return texture;
}

/**
 * Get the RenderObject's surface
*/
SDL_Surface* RenderObject::getSurface() {
    return surface;
}

/**
 * Get the RenderObject's clip
 * 
 * The clip defines what section of the objects texture should be displayed. 
 * If it is NULL, the full texture will be displayed. 
*/
SDL_Rect RenderObject::getClip() {
    return clip;
}

/**
 * Get the RenderObject's position
 * 
 * The position defines where on the screen the object "is"
*/
SDL_Point RenderObject::getPosition() {
    return position;
}

/** Get the rendering target of the object */
SDL_Rect RenderObject::getTarget() {
    return target;
}

/**
 * Get the RenderObject's point of rotation.
 * 
 * rotatePoint defines where the point that the RenderObject will be rotated around if it is being rotated
*/
SDL_Point RenderObject::getRotatePoint() {
    return rotatePoint;
}

/**
 * Get the RenderObject's rotate angle
 * 
 * rotateAngle defines how much an object should be rotated. Rotation is measured clockwise.
*/
double RenderObject::getAngle() {
    return rotateAngle;
}

/**
 * Get the type of flip the RenderObject has
 * 
 * flip defines how the RenderObject should be flipped. Types are vertical, horizontal, or none
*/
SDL_RendererFlip RenderObject::getFlip() {
    return flip;
}

/**
 * Get the RenderObject's alignment
 * 
 * alignment defines where the object's position is defined on the RenderObject. For example, 
 * center alignment means that the object's x,y position is measured at the center of the object.
*/
RenderAlignment RenderObject::getAlignment() {
    return alignment;
}

/**
 * Check to see if the RenderObject is hidden. When the RenderObject is hidden, it cannot be rendered.
*/
bool RenderObject::isHidden() {
    return hidden;
}

/**
 * Set the RenderObject as "hidden". When the RenderObject is hidden, it cannot be rendered.
*/
void RenderObject::hide() {
    hidden = true;
}

/**
 * Set the RenderObject's hidden flag as false so the object is visible. When the RenderObject is hidden, it cannot be rendered.
*/
void RenderObject::unhide() {
    hidden = false;
}

/**
 * Destroy the RenderObject
 * 
 * Check if each dynamic member is nullptr before freeing to avoid double deallocation.
*/
RenderObject::~RenderObject() {
    
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if(surface != nullptr) {
        SDL_FreeSurface(surface);
        surface = nullptr;
    }

}