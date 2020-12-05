#include "sprite.hpp"

Sprite::Sprite(SDL_Texture *img)
{ //default constructor for all sprites.

    asset = img;
}

int Sprite::getWidth()
{
    return (mover.w);
}
int Sprite::getHeight()
{
    return (mover.h);
}

void Sprite::general_render(int x, int y, SDL_Texture *img, SDL_Renderer *gRenderer, double angle, SDL_RendererFlip turn)
{
    SDL_Rect dstrect = {x, y, mover.w, mover.h};
    SDL_RenderCopyEx(gRenderer, img, &src, &dstrect, angle, NULL, turn); //included the angle because of the ship
}
