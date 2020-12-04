//#include "location.hpp"
#include "sprite.hpp"
#include <SDL.h>
#include <iostream>
#pragma once

class Alien : public Sprite
{
    int strength; //stores either how many hits an alien needs to die OR how much damage they do to player with their hit. We need to choose one
    bool cstate;//current state

public:
    Alien(SDL_Texture *);
    //~Alien();
    void shoot();
    virtual void hasdestroyed()=0;
    virtual bool getdestroyed()=0; //check
    virtual void setStrength(int s)=0;
    virtual int getStrength()=0;
    virtual int getPoints()=0;
    virtual SDL_Rect getmover()=0;
    void setstate(bool s); 
    void drawSprite(SDL_Renderer *);
};