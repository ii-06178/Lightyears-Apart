//#include "location.hpp"
#include "SDL.h"
#include <string>
#pragma once

class Sprite
{//spaceship, alien, obstacle. Where will the rest of the assets aka fuel guage/ lives be displayed?
protected:
    //Location loc;
    SDL_Texture* asset;
    //int width;
    //int height;
    SDL_Rect src;
    SDL_Rect mover;
    int hitCount; //stores how many times the sprite has been hit - will be used to determine when it'll be destroyed
    int x_speed, y_speed; //speed of the sprite
    int lives[3];
    SDL_RendererFlip turn_h;

public:
    Sprite(SDL_Texture*);
    //void setLoc(Location l);
    //void setWidth(int w);
    //void setHeight(int h);
    void setHitCount(int hc);
    void setSpeed(int s);
    //Location getLoc();
    SDL_Rect getLoc();
    int getWidth();
    int getHeight();
    int getHitCount();
    int getSpeed();

    //SDL_Rect spriteSource(); //returns the sprite source needed
    virtual void drawSprite(SDL_Renderer*) = 0;
    //SDL_Rect moveSprite();
    void general_render(int, int, SDL_Texture*, SDL_Renderer*, double, SDL_RendererFlip); //I modified the SDL_RenderCopy/Ex for my ease, I'll explain it if needed
};
//The functions and atts commented out are those which i think can be implemented with SDL_Rect alone.