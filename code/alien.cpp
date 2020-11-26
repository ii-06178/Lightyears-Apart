#include "alien.hpp"

Alien::Alien(SDL_Texture* img):Sprite(img){//constructor for all aliens, I was thinking of using the Sprite constructor, but didn't for now, might change it later.
    turn = SDL_FLIP_NONE;
    loc_x = 0;
    loc_y = 0;
}
void Alien::drawSprite(SDL_Renderer* gRenderer){//the draw function
    //SDL_RenderCopy(gRenderer, asset, &src, &mover);
    Sprite::general_render(loc_x, loc_y, asset, gRenderer,0.0,turn);//renders the alien

    if(mover.x < 800-mover.w && turn == SDL_FLIP_NONE){//moving towards right wall
        loc_x += 20;
    }
    else if (mover.x > 800-mover.w) turn = SDL_FLIP_HORIZONTAL;//turns when hit the right wall
    if (mover.x > 0+mover.w && turn == SDL_FLIP_HORIZONTAL){//moving towards left wall
        loc_x -= 20;
    }
    else if (mover.x < 0+mover.w) turn = SDL_FLIP_NONE;//turns when hit the left wall
}
void Alien::shoot()
{

}

void Alien::kill()
{

}

void Alien::setStrength(int s)
{
    strength = s;
}
void Alien::setDifficulty(int d)
{
    difficultyLevel = d;
}
int Alien::getStrength()
{
    return strength;
}
int Alien::getDifficulty()
{
    return difficultyLevel;
}
