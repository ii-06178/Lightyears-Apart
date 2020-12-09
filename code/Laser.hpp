#pragma once
#include "sprite.hpp"
#include <SDL.h>

class Laser : public Sprite
{
    bool contact = false;   //contact with the ship
    int strength = 0;

protected:

    SDL_Rect src[2];
    static int frame;
    std::string type = "hero";
    bool cstate;

public:

    Laser(SDL_Texture *);
    void setcstate(bool s);
    bool getcontact();
    void setcontact();
    void setstrength(int);
    int getstrength();
    SDL_Rect getmover();
    void drawSprite(SDL_Renderer *) override;
    void setPos(SDL_Rect);
    void setType(std::string);
};
