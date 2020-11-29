//#include "location.hpp"
#include <SDL.h>
#pragma once

class Laser{
    protected:
    SDL_Texture* asset;
    SDL_Rect src[2], mover;
    static int frame;
    public:
    Laser(SDL_Texture*);
    virtual void shoot(SDL_Renderer*, SDL_Rect) = 0;
};
