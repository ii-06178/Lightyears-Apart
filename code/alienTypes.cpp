#include "alienTypes.hpp"

//Polymorphism on Alien Constructor
GeoYielders::GeoYielders(SDL_Texture *img) : Alien(img)
{
    src.x = 10;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 60;
    mover.y = 0 - mover.h;

    destroyed = false;
    shoots = 4; 
    strength = 25;  
    attacked = 1;
    points = 40;    
}
ThunderBearers::ThunderBearers(SDL_Texture *img) : Alien(img)
{
    src.x = 141;
    src.y = 604;
    src.w = 130;
    src.h = 145;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 85;
    mover.y = 0 - mover.h;

    destroyed = false;
    shoots = 2;
    points = 20;
    strength = 15;
    attacked = 1;
}

StormCarriers::StormCarriers(SDL_Texture *img) : Alien(img)
{
    src.x = 282;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 60;
    mover.y = 0 - mover.h;

    destroyed = false;
    shoots = 3;
    points = 30;
    attacked = 1;
    strength = 20;
}
FireBreathers::FireBreathers(SDL_Texture *img) : Alien(img)
{
    src.x = 423;
    src.y = 604;
    src.w = 130;
    src.h = 125;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 65;
    mover.y = 0 - mover.h;

    destroyed = false;
    shoots = 1;
    points = 10;
    strength = 10;
    attacked = 1;

}