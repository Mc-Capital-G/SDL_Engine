/**
 * RenderObject.h:
 * Declaration of the RenderObject class
 * 
 * This class is responsible for storing data associated with any object we wish to render to the screen.
 * Most other objects we wish to manipulate and also display to the screen will likely be children of this class.
 * 
 * @author Declan McGrellis
*/

#ifndef __RENDEROBJECT_H__
#define __RENDEROBJECT_H__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>

namespace engine {

    enum RenderAlignment {
        TOP_LEFT,
        TOP_RIGHT,
        CENTER,
        BOTTOM_LEFT,
        BOTTOM_RIGHT
    };

    class RenderObject {
            
        public:
            RenderObject(std::string filePath, uint __sWidth, uint __sHeight);
            RenderObject(std::string filePath);
            ~RenderObject();

            SDL_Texture* getTexture();
            SDL_Surface* getSurface();
            SDL_Rect getPosition();
            SDL_Rect getClip();
            SDL_Point getRotatePoint();
            SDL_RendererFlip getFlip();
            double getAngle();
            RenderAlignment getAlignment();

            bool isHidden();
            
            void setPosition(int x, int y);
            void setScale(uint w, uint h);
            void setClip(uint x, uint y);
            void setAlignment(RenderAlignment newAlignment);
            void resetClip();
            void setTexture(SDL_Texture* tex);
            void setFlip(SDL_RendererFlip __flip);
            void hide();
            void unhide();

            SDL_Texture* texture;
            SDL_Surface* surface;
            
        private:
            
            SDL_Rect position;
            SDL_Rect clip;
            SDL_Point rotatePoint;
            SDL_RendererFlip flip;
            double rotateAngle;
            RenderAlignment alignment;
            bool hidden;

            uint width;
            uint height;
                
    };

}

#endif