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
}

//has destroyed functions of the aliens
void GeoYielders::hasdestroyed()
{
    if (attacked == shoots){

        destroyed = true;
    }
    else{

        attacked++;
    }
}
void ThunderBearers::hasdestroyed()
{
    if (attacked == shoots){

        destroyed = true;
    }
    else{

        attacked++;
    }
}

void StormCarriers::hasdestroyed()
{
    if (attacked == shoots){

        destroyed = true;
    }
    else{

        attacked++;
    }
}

void FireBreathers::hasdestroyed()
{
    if (attacked == shoots){

        destroyed = true;
    }
    else{

        attacked++;
    }
}

//get destroyed functions for the the aliens
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

//get mover function for the aliens
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

//get points for the for the aliens
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

//set and get strength for the aliens
void GeoYielders::setStrength(int s)
{
    strength = s;
}
int GeoYielders::getStrength()
{
    return strength;
}
void ThunderBearers::setStrength(int s)
{
    strength = s;
}
int ThunderBearers::getStrength()
{
    return strength;
}
void StormCarriers::setStrength(int s)
{
    strength = s;
}
int StormCarriers::getStrength()
{
    return strength;
}
void FireBreathers::setStrength(int s)
{
    strength = s;
}
int FireBreathers::getStrength()
{
    return strength;
}