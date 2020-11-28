//#include "location.hpp"
#include "sprite.hpp"
#include <SDL.h>
#pragma once

class Obstacle:public Sprite
{
    int strength; //how much life and/or fuel is effected when the obstacle hits the player's spaceship
    //can't think of what attributes obstacles would need other than those already in sprite

    public:
    Obstacle(SDL_Texture*);
    ~Obstacle();
    void setStrength(int s);
    int getStrength();

    void drawSprite(SDL_Renderer*);
    void drawM();
    void drawF();
};