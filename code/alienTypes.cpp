#include "alienTypes.hpp"

//Polymorphism on Alien Constructor
GeoYielders::GeoYielders(SDL_Texture* img):Alien(img){
    src.x = 10;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = (800 - src.w)/2;
    mover.y = 0;
    mover.w = 90;
    mover.h = 80;
}
ThunderBearers::ThunderBearers(SDL_Texture* img):Alien(img){
    src.x = 141;
    src.y = 604;
    src.w = 130;
    src.h = 145;

    mover.x = loc_x;
    mover.y = loc_y;
    mover.w = 90;
    mover.h = 105;
}
StormCarriers::StormCarriers(SDL_Texture* img):Alien(img){
    src.x = 282;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = (800 - src.w)/2;
    mover.y = 200;
    mover.w = 90;
    mover.h = 80;
}
FireBreathers::FireBreathers(SDL_Texture* img):Alien(img){
    src.x = 423;
    src.y = 604;
    src.w = 130;
    src.h = 125;

    mover.x = (800 - src.w)/2;
    mover.y = 290;
    mover.w = 90;
    mover.h = 85;
}

//using polymorphism by having the kill method work differently for each type of alien 
void GeoYielders::kill()
{

}

void ThunderBearers::kill()
{
    
}

void StormCarriers::kill()
{
    
}

void FireBreathers::kill()
{
    
}