#include "sprite.hpp"

Sprite::Sprite(SDL_Texture *img)
{ //default constructor for all sprites.

    asset = img;
}
//Sprite::~Sprite(){
    //SDL_DestroyTexture(asset);
    //asset = NULL;
    //src = mover = {0,0,0,0};
//}

void Sprite::general_render(int x, int y, SDL_Texture *img, SDL_Renderer *gRenderer, double angle, SDL_RendererFlip turn)
{
    SDL_Rect dstrect = {x, y, mover.w, mover.h};
    SDL_RenderCopyEx(gRenderer, img, &src, &dstrect, angle, NULL, turn); //included the angle because of the ship
}
