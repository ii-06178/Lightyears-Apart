#include <SDL.h>

#pragma once

//Independent class for scrolling background
class BGTexture
{
public:
    SDL_Texture *assets;
    int bgWidth, bgHeight, scrollingOffSet;

    BGTexture();
    ~BGTexture();
    void render(int, int, SDL_Renderer *);  //simplified renderer for the bg
    void drawBG(SDL_Renderer *);    //draw function
};