//#include "location.hpp"
#include <SDL.h>
#include <string>
#pragma once
//abstract class for all the objects to be created
class Sprite
{//spaceship, alien, obstacle. Where will the rest of the assets aka fuel guage/ lives be displayed?
protected:
    
    SDL_Texture* asset;
    SDL_Rect src;
    SDL_Rect mover;
    int hitCount; //stores how many times the sprite has been hit - will be used to determine when it'll be destroyed
    SDL_RendererFlip turn_h;

public:

    Sprite(SDL_Texture*);
    ~Sprite();
    void setHitCount(int hc);
    void setSpeed(int s);
    int getWidth();
    int getHeight();

    virtual void drawSprite(SDL_Renderer*) = 0;
    void general_render(int, int, SDL_Texture*, SDL_Renderer*, double, SDL_RendererFlip); //I modified the SDL_RenderCopy/Ex for my ease, I'll explain it if needed
};
//The functions and atts commented out are those which i think can be implemented with SDL_Rect alone.