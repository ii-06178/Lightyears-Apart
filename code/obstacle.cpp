#include "obstacle.hpp"

Obstacle::Obstacle(SDL_Texture* img):Sprite(img)
{
    
}
void Obstacle::drawSprite(SDL_Renderer* gRenderer){
    general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h);
    //mover.x += 15;
    mover.y += 10;
    if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE){
        mover.x += 15;
    }
    else if (mover.x >= 800 - mover.w) turn_h = SDL_FLIP_HORIZONTAL;

    if (mover.x > 0 && turn_h == SDL_FLIP_HORIZONTAL){
        mover.x -= 15;
    }
    else if (mover.x <= 0) turn_h = SDL_FLIP_NONE;
}

void Obstacle::setStrength(int s)
{
    strength = s;
}

int Obstacle::getStrength()
{
    return strength;
}

Obstacle::~Obstacle()
{
    
}