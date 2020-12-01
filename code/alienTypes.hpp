#include "alien.hpp"
#include "sprite.hpp"
#pragma once

class GeoYielders:public Alien
{   
    bool destroyed=false;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill(); //function to kill the alien based on how many times it is hit by player
    GeoYielders(SDL_Texture*);
    SDL_Rect getmover();
};

class ThunderBearers:public Alien
{
    bool destroyed=false;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    ThunderBearers(SDL_Texture*);
    SDL_Rect getmover();
};

class StormCarriers:public Alien
{
    bool destroyed=false;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    StormCarriers(SDL_Texture*);
    SDL_Rect getmover();
};

class FireBreathers:public Alien
{
    bool destroyed=false;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    FireBreathers(SDL_Texture*);
    SDL_Rect getmover();
};
