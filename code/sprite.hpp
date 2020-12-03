//#include "location.hpp"
#include <SDL.h>
#include <string>
#pragma once

class Sprite
{ //this is the abstract class from which spaceship, alien, obstacle will be made.
protected:
    //Location loc;
    SDL_Texture *asset;
    SDL_Rect src;
    SDL_Rect mover;
    int hitCount;         //stores how many times the sprite has been hit - will be used to determine when it'll be destroyed
    int x_speed, y_speed; //speed of the sprite
    int lives[3];
    SDL_RendererFlip turn_h;

public:
    Sprite(SDL_Texture *);
    void setHitCount(int hc);
    void setSpeed(int s);
    //Location getLoc();
    SDL_Rect getLoc();
    int getWidth();
    int getHeight();
    int getHitCount();
    int getSpeed();
    virtual void drawSprite(SDL_Renderer *) = 0; //virtual void function which draws the sprites unless it has been overrided by the child class.
    void general_render(int, int, SDL_Texture *, SDL_Renderer *, double, SDL_RendererFlip); //I modified the SDL_RenderCopy/Ex for my ease, I'll explain it if needed
};
