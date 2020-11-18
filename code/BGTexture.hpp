//#include "location.hpp"
#include "SDL.h"
#include <string>
#pragma once

class BGTexture{
public:
    SDL_Texture* assets;
    int bgWidth, bgHeight, scrollingOffSet;

    BGTexture();
    ~BGTexture();
    void render(int, int, SDL_Renderer*);
    void drawBG(SDL_Renderer*);
};