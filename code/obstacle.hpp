#include "sprite.hpp"

#pragma once

class Obstacle : public Sprite
{
    bool destroyed;
    bool contact;
    int strength; //how much life and/or fuel is effected when the obstacle hits the player's spaceship
    bool cstate;
    
    //attributes for Thunderbolt
    static int frame;
protected:
    bool thunder;
    SDL_Rect T_src[2];

public:
    Obstacle(SDL_Texture *);
    ~Obstacle();

    void setStrength(int);
    int getStrength();
    SDL_Rect getmover();
    void setstate(bool);
    void setDestroyed(bool);
    void hasdestroyed();
    bool getdestroyed();
    void setcontact();
    bool getcontact();

    void drawSprite(SDL_Renderer*) override;
};