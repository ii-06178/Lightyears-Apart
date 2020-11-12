#include "location.hpp"
#include "SDL.h"
#pragma once

class Sprite
{//spaceship, alien, obstacle. Where will the rest of the assets aka fuel guage/ lives be displayed?
    Location loc;
    int width;
    int height;
    int hitCount; //stores how many times the sprite has been hit - will be used to determine when it'll be destroyed
    int speed; //speed of the sprite

    public:
    void setLoc(Location l);
    void setWidth(int w);
    void setHeight(int h);
    void setHitCount(int hc);
    void setSpeed(int s);
    Location getLoc();
    int getWidth();
    int getHeight();
    int getHitCount();
    int getSpeed();

    SDL_Rect spriteSource(); //returns the sprite source needed
    void drawSprite();
    SDL_Rect moveSprite();
};