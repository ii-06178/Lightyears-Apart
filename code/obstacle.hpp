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
    virtual void setStrength(int s)=0;
    virtual int getStrength();

    void setstate(bool s);
    virtual SDL_Rect getmover();
    virtual void hasdestroyed();
    void setcontact();
    virtual bool getdestroyed();
    bool getcontact();
    void drawM();
    void drawF();
    void drawSprite(SDL_Renderer *);
};