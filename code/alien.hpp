//#include "location.hpp"
#include "sprite.hpp"
#include <SDL.h>
#include <iostream>
#pragma once

class Alien : public Sprite
{
protected:
    int strength; //the amount of fuel its laser reduces
    bool cstate;//current state
    bool destroyed;
    int shoots; //required to kill the alien
    int attacked;   //to check how many lasers they were attacked with
    int points; //points the player gets after killing them

public:
    Alien(SDL_Texture *);

    void hasdestroyed();    //set destroyed
    bool getdestroyed(); //check if destroyed
    void setStrength(int s);
    int getStrength();
    int getPoints();
    SDL_Rect getmover();
    void setstate(bool s); 
    void drawSprite(SDL_Renderer *) override;
};