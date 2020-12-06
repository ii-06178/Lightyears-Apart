#include "BGTexture.hpp"

BGTexture::BGTexture()
{ //constructor
    assets = NULL;
    bgWidth = 0;
    bgHeight = 0;
    scrollingOffSet = 0;
}
BGTexture::~BGTexture()
{ //destructor
    //destroying the background
    SDL_DestroyTexture(assets);
    bgWidth = bgHeight = scrollingOffSet = 0;
}

void BGTexture::render(int x, int y, SDL_Renderer *gRenderer)
{
    //destination Rect 
    SDL_Rect renderQuad = {x, y, bgWidth, bgHeight};

    //Rendering to the screen
    SDL_RenderCopy(gRenderer, assets, NULL, &renderQuad);
}
void BGTexture::drawBG(SDL_Renderer *gRenderer)
{

    scrollingOffSet += 5;
    if (scrollingOffSet >= bgHeight){   //resetting scrolling off set when it is greater than the screen's height

        scrollingOffSet = 0;
    }

    //rendering background
    render(0, scrollingOffSet, gRenderer);
    render(0, scrollingOffSet - bgHeight, gRenderer);
}