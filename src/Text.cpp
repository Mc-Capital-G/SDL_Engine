/**
 * Text.h:
 * Definition of the Text class
 * 
 * This class is a child of the RenderObject class, and is designed to hold data corresponding
 * to a specific string of text that we can draw to the screen.
 * 
 * @author Declan McGrellis
*/

#include "Text.h"

using namespace engine;

/**
 * Initialize the text that we are going to render
 * 
 * @param text the text we should generate
 * @param font a file path to the ttf font that should be used
 * @param fontSize the size the text should be generated at
 * @param wrapLength the length the text should be wrapped at - no value / 0 will mean the text is unwrapped
 * @param color the color the text should be
*/
Text::Text(std::string __text, std::string font, int fontSize, SDL_Color color, Uint32 wrapLength) : RenderObject() {

    text = __text;

    TTF_Font* tFont = TTF_OpenFont(font.c_str(), fontSize);

    // initialize the text as a white color so that we can mod it easliy with the color
    if(wrapLength == 0) surface = TTF_RenderUTF8_Solid(tFont, text.c_str(), {255, 255, 255, 0});
    else surface = TTF_RenderUTF8_Solid_Wrapped(tFont, text.c_str(), {255, 255, 255, 0}, wrapLength);

    // give the text the desired color
    SDL_SetSurfaceColorMod(surface, color.r, color.g, color.b);

    setScale(surface->w, surface->h);
    

}

/** Set the color of the text */
void Text::setColor(SDL_Color color) {
    if(texture == nullptr) SDL_SetSurfaceColorMod(surface, color.r, color.g, color.b);
    else SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

/** Get the text that the object is displaying */
std::string Text::getText() {
    return text;
}