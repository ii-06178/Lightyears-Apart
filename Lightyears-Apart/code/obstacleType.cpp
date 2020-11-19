#include "obstacleTypes.hpp"
//Just made the constructors for the sprite objects with their respective srcs and movers(places where they'll be placed).
Meteor::Meteor(SDL_Texture* img):Obstacle(img){
    src.x = 0;
    src.y = 250;
    src.w = 220;
    src.h = 220;

    mover.x = 500;
    mover.y = 0;
    mover.w = 160;
    mover.h = 160;
}
Fireball::Fireball(SDL_Texture* img):Obstacle(img){//Need to find a sprite for this
    src.x;
    src.y;
    src.w;
    src.h;

    mover.x;
    mover.y;
    mover.w;
    mover.h;
}
Thunderbolt::Thunderbolt(SDL_Texture* img):Obstacle(img){
    src.x = 580;
    src.y = 430;
    src.w = 55;
    src.h = 245;

    mover.x = 550;
    mover.y = 200;
    mover.w = 55;
    mover.h = 250;
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