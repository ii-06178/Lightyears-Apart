//#include "location.hpp"
#include "sprite.hpp"
#include <SDL.h>
#pragma once

class Obstacle : public Sprite
{
    bool destroyed = false;
    bool contact = false;
    int strength; //how much life and/or fuel is effected when the obstacle hits the player's spaceship
    bool cstate = true;
    static int frame;

    protected:
    bool thunder;
    SDL_Rect T_src[2];

public:
    Obstacle(SDL_Texture *);
    ~Obstacle();
    void setStrength(int s);
    int getStrength();

    void drawSprite(SDL_Renderer *);
    void setstate(bool s);
    SDL_Rect getmover();
    void hasdestroyed();
    void setcontact();
    bool getdestroyed();
    bool getcontact();
    void drawM();
    void drawF();
};