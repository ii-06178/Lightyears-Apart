#include "obstacle.hpp"

Obstacle::Obstacle(SDL_Texture* img):Sprite(img)
{
    
}
void Obstacle::drawSprite(SDL_Renderer* gRenderer){
    general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h);
    //mover.x += 15;
    if (cstate==true)
    {
        if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE){
        mover.x += 15;
    }
    else if (mover.x >= 800 - mover.w) turn_h = SDL_FLIP_HORIZONTAL;

    if (mover.x > 0 && turn_h == SDL_FLIP_HORIZONTAL){
        mover.x -= 15;
    }
    else if (mover.x <= 0) turn_h = SDL_FLIP_NONE;
    }
    mover.y += 10;
    
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
void Obstacle::setstate(bool s)
{
    cstate=s;
}
SDL_Rect Obstacle::getmover()
{
    return mover;
}
void Obstacle::hasdestroyed()
{
    destroyed=true;
}
bool Obstacle::getdestroyed()
{
    return destroyed;
}
void Obstacle::setcontact()
{
    contact=true;
}
bool Obstacle::getcontact()
{
    return contact;
}