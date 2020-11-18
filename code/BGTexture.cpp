#include "BGTexture.hpp"

BGTexture::BGTexture(){//constructor
    assets = NULL;
    bgWidth = 0;
    bgHeight = 0;
    scrollingOffSet = 0;
}
BGTexture::~BGTexture(){//destructor
    //destroying the background
    SDL_DestroyTexture(assets);
    bgWidth = bgHeight = scrollingOffSet = 0;
}

void BGTexture::render( int x, int y, SDL_Renderer* gRenderer)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, bgWidth, bgHeight };

	//Render to screen
	SDL_RenderCopy( gRenderer, assets, NULL, &renderQuad);

}
void BGTexture::drawBG(SDL_Renderer* gRenderer){

    scrollingOffSet -= 5;
    if(scrollingOffSet < -bgWidth){//condition for resetting
        scrollingOffSet = 0;
    }

    //rendering background
    render(scrollingOffSet, 0, gRenderer);
    render(scrollingOffSet+bgWidth, 0, gRenderer);
}