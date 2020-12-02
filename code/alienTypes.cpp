#include "alienTypes.hpp"

//Polymorphism on Alien Constructor
GeoYielders::GeoYielders(SDL_Texture* img):Alien(img){
    src.x = 10;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 60;
    mover.y = 0 - mover.h;
}
ThunderBearers::ThunderBearers(SDL_Texture* img):Alien(img){
    src.x = 141;
    src.y = 604;
    src.w = 130;
    src.h = 145;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 85;
    mover.y = 0 - mover.h;
    //printf("First Constructor Functional");
}

StormCarriers::StormCarriers(SDL_Texture* img):Alien(img){
    src.x = 282;
    src.y = 605;
    src.w = 130;
    src.h = 120;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 60;
    mover.y = 0 - mover.h;
}
FireBreathers::FireBreathers(SDL_Texture* img):Alien(img){
    src.x = 423;
    src.y = 604;
    src.w = 130;
    src.h = 125;

    mover.x = rand() % 800;
    mover.w = 70;
    mover.h = 65;
    mover.y = 0 - mover.h;
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
void GeoYielders::hasdestroyed()
{ if (attacked==shoots)
{
        destroyed=true;
}
else
{
    attacked++;
}

}

void ThunderBearers::hasdestroyed()
{
if (attacked==shoots)
{
        destroyed=true;
}
else
{
    attacked++;
}
}

void StormCarriers::hasdestroyed()
{
if (attacked==shoots)
{
        destroyed=true;
}
else
{
    attacked++;
}   
}

void FireBreathers::hasdestroyed()
{
if (attacked==shoots)
{
        destroyed=true;
}
else
{
    attacked++;
}
}
bool GeoYielders::getdestroyed()
{
    return destroyed;
}

bool ThunderBearers::getdestroyed()
{
    return destroyed;
}

bool StormCarriers::getdestroyed()
{
    return destroyed;   
}

bool FireBreathers::getdestroyed()
{
    return destroyed;
}
SDL_Rect GeoYielders::getmover()
{
return mover;
}
SDL_Rect ThunderBearers::getmover()
{
return mover;
}
SDL_Rect StormCarriers::getmover()
{
return mover;
}
SDL_Rect FireBreathers::getmover()
{
return mover;
}
int GeoYielders::getPoints()
{
    return points;
}
int ThunderBearers::getPoints()
{
    return points;
}
int StormCarriers::getPoints()
{
    return points;
}
int FireBreathers::getPoints()
{
    return points;
}