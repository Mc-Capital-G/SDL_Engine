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
    position.w = width;
    position.h = height;

    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;

}

/**
 * Change the position of the RenderObject. 
 * 
 * The position defines where on the screen the object will be rendered.
 * 
 * Can also change the width and height of the object, but by default will not touch it, 
 * so passing values to w and h is not required. Any negative number passed to w or h will also not 
 * affect object width/height respectively.
 * 
 * @param x new x position
 * @param y new y position
 * @param w new width - negative values will not change the width
 * @param h new height - negative values will not change the height
*/
void RenderObject::setPosition(int x, int y, int w, int h) {

    position.x = x;
    position.y = y;

    if(w > 0) position.w = w;
    else position.w = width;
    if(h > 0) position.h = h;
    else position.h = height;
   
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

    if(surface != nullptr) SDL_FreeSurface(surface);

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
 * The position defines where on the screen the object will be rendered.
*/
SDL_Rect RenderObject::getPosition() {
    return position;
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
    
    if(texture != nullptr) SDL_DestroyTexture(texture);
    if(surface != nullptr) SDL_FreeSurface(surface);

}