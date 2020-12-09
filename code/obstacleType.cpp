#include "obstacleTypes.hpp"

Meteor::Meteor(SDL_Texture *img) : Obstacle(img)    //Using the Obstacle parent class constructor for setting the texture
{
    src.x = 0;  //src indicating to the position of the object on the sprite
    src.y = 140;
    src.w = 155;
    src.h = 140;

    mover.w = 130;  //mover to place the object on screen
    mover.h = 130;
    mover.x = rand() % 800; //random value of x
    mover.y = 0 - mover.h;  //creating an effect that the object is coming from out of the screen

    setDestroyed(false);    //setting attributes defined in the parent class Obstacle to optimize space
    setStrength(20);
    turn_h = SDL_FLIP_NONE;
}
Fireball::Fireball(SDL_Texture *img) : Obstacle(img){

    src.x = 306;
    src.y = 146;
    src.w = 150;
    src.h = 130;

    mover.w = 140;
    mover.h = 140;
    mover.x = rand() % 800;
    mover.y = 0 - mover.h;

    setDestroyed(false);
    setStrength(40);
    turn_h = SDL_FLIP_HORIZONTAL;
}
Thunderbolt::Thunderbolt(SDL_Texture* img):Obstacle(img){

    //2 srcs for the animation
    T_src[0].x = 570;
    T_src[0].y = 615;
    T_src[0].w = 100;
    T_src[0].h = 350;

    T_src[1].x = 670;
    T_src[1].y = 615;
    T_src[1].w = T_src[0].w;
    T_src[1].h = T_src[0].h;

    mover.w = 100;
    mover.h = 500;
    mover.x = rand() % 800;
    mover.y = -15;

    setStrength(60);
    setDestroyed(false);
    thunder = true;
}