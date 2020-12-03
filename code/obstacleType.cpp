#include "obstacleTypes.hpp"
//Just made the constructors for the sprite objects with their respective srcs and movers(places where they'll be placed).
Meteor::Meteor(SDL_Texture *img) : Obstacle(img)
{
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
Fireball::Fireball(SDL_Texture *img) : Obstacle(img)
{
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
Thunderbolt::Thunderbolt(SDL_Texture *img) : Obstacle(img)
{   
    src[0].x = 300;
    src[0].y = 300;
    src[0].w = 70;
    src[0].h = 250;

    src[1].x = 370;
    src[1].y = 300;
    src[1].w = 70;
    src[1].h = 250;

    mover.w = 70;
    mover.h = 250;
    mover.x = rand() % 800;
    mover.y = -5;
   
}

void Thunderbolt::drawBolt(SDL_Renderer *gRenderer)
{

    // SDL_Rect* currentframe = &src[frame%1];
    // general_render(mover.x, mover.y, asset, gRenderer, 0.0, SDL_FLIP_NONE);
    // ++frame;
    // if(frame > 1) frame = 0;
    // mover.h++;
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
    destroyed = true;
}

void Fireball::hasdestroyed()
{
    destroyed = true;
}

void Thunderbolt::hasdestroyed()
{
    destroyed = true;
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
void Fireball::setStrength(int s)
{
    strength = s;
}
int Fireball::getStrength()
{
    return strength;
}
void Thunderbolt::setStrength(int s)
{
    strength = s;
}
int Thunderbolt::getStrength()
{
    return strength;
}
void Meteor::setStrength(int s)
{
    strength = s;
}
int Meteor::getStrength()
{
    return strength;
}
