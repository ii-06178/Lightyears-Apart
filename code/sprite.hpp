//#include "location.hpp"
#include <SDL.h>
#include <string>
#pragma once

class Sprite
{ //this is the abstract class from which spaceship, alien, obstacle will be made.
protected:
    
    SDL_Texture *asset; //texture from the sprite
    SDL_Rect src;   //position on the sprite
    SDL_Rect mover; //position on the screen
    SDL_RendererFlip turn_h;    //turn for turning the sprites on x axis

public:
    Sprite(SDL_Texture *);
    virtual void drawSprite(SDL_Renderer *) = 0; //virtual void function which draws the sprites
    void general_render(int, int, SDL_Texture *, SDL_Renderer *, double, SDL_RendererFlip); //Modified render function
};
