//#include "location.hpp"
 #pragma once
#include "sprite.hpp"
#include <SDL.h>

class Laser:public Sprite 
{
    protected:
    SDL_Texture* asset;
    SDL_Rect src[2], mover;
    static int frame;
    std::string type="hero";
    public:
    Laser(SDL_Texture*);
    void shoot(SDL_Renderer*, SDL_Rect);
    SDL_Rect getmover();
    void drawSprite(SDL_Renderer*);
    void setPos(SDL_Rect);
    void setType(std::string);
};
