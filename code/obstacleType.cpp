#include "obstacleTypes.hpp"
//Just made the constructors for the sprite objects with their respective srcs and movers(places where they'll be placed).
Meteor::Meteor(SDL_Texture* img):Obstacle(img){
    src.x = 0;
    src.y = 138;
    src.w = 155;
    src.h = 170;

    mover.x = 500;
    mover.y = 0;
    mover.w = 160;
    mover.h = 160;
}
Fireball::Fireball(SDL_Texture* img):Obstacle(img){
    src.x = 306;
    src.y = 138;
    src.w = 155;
    src.h = 160;

    mover.x = 500;
    mover.y = 170;
    mover.w = 160;
    mover.h = 160;
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