#include "obstacleTypes.hpp"
//Just made the constructors for the sprite objects with their respective srcs and movers(places where they'll be placed).
Meteor::Meteor(SDL_Texture* img):Obstacle(img){
    src.x = 0;
    src.y = 140;
    src.w = 155;
    src.h = 140;

    mover.w = 130;
    mover.h = 130;
    mover.x = rand() % 800;
    mover.y = 0 - mover.h;

    turn_h = SDL_FLIP_NONE;
}
Fireball::Fireball(SDL_Texture* img):Obstacle(img){
    src.x = 306;
    src.y = 146;
    src.w = 150;
    src.h = 130;

    mover.w = 140;
    mover.h = 140;
    mover.x = rand() % 800;
    mover.y = 0 - mover.h;

    turn_h = SDL_FLIP_HORIZONTAL;
}
Thunderbolt::Thunderbolt(SDL_Texture* img):Obstacle(img){
    /*src.x = 580;
    src.y = 430;
    src.w = 55;
    src.h = 245;

    mover.x = 550;
    mover.y = 200;
    mover.w = 55;
    mover.h = 250;*/
}

void Meteor::destroy()
{

}

void Fireball::destroy()
{
    
}

void Thunderbolt::destroy()
{
    
}
void Meteor::hasdestroyed()
{
    destroyed=true;
}

void Fireball::hasdestroyed()
{
    destroyed=true;
}

void Thunderbolt::hasdestroyed()
{
    destroyed=true;
}
bool Meteor::getdestroyed()
{
    return destroyed;
}

bool Fireball::getdestroyed()
{
        return destroyed;
}

bool Thunderbolt::getdestroyed()
{
        return destroyed;
}
SDL_Rect Meteor::getmover()
{
    return mover;
}

SDL_Rect Fireball::getmover()
{
        return mover;
}

SDL_Rect Thunderbolt::getmover()
{
        return mover;
}