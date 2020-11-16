#include "alienTypes.hpp"

//Polymorphism on Alien Constructor
GeoYielders::GeoYielders(SDL_Texture* img):Alien(img){
    src.x = 450;
    src.y = 700;
    src.w = 120;
    src.h = 120;

    mover.x = (800 - src.w)/2;
    mover.y = 0;
    mover.w = 80;
    mover.h = 80;
}
ThunderBearers::ThunderBearers(SDL_Texture* img):Alien(img){
    src.x = 580;
    src.y = 700;
    src.w = 130;
    src.h = 150;

    mover.x = (800 - src.w)/2;
    mover.y = 90;
    mover.w = 90;
    mover.h = 110;
}
StormCarriers::StormCarriers(SDL_Texture* img):Alien(img){
    src.x = 720;
    src.y = 700;
    src.w = 130;
    src.h = 120;

    mover.x = (800 - src.w)/2;
    mover.y = 200;
    mover.w = 90;
    mover.h = 80;
}
FireBreathers::FireBreathers(SDL_Texture* img):Alien(img){
    src.x = 860;
    src.y = 700;
    src.w = 120;
    src.h = 125;

    mover.x = (800 - src.w)/2;
    mover.y = 290;
    mover.w = 80;
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