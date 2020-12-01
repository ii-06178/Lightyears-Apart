//#include "location.hpp"
#include "sprite.hpp"
#include <SDL.h>
#pragma once

class Obstacle:public Sprite
{   bool destroyed=false;
    bool contact=false;
    int strength; //how much life and/or fuel is effected when the obstacle hits the player's spaceship
    //can't think of what attributes obstacles would need other than those already in sprite
    bool cstate=true;
    public:
    Obstacle(SDL_Texture*);
    ~Obstacle();
    void setStrength(int s);
    int getStrength();

    void drawSprite(SDL_Renderer*);
    void setstate(bool s);
    SDL_Rect getmover();
    void hasdestroyed();
    void setcontact();
    bool getdestroyed();
    bool getcontact();
    void drawM();
    void drawF();
};