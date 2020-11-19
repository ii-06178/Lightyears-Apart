#include "alien.hpp"
#pragma once

class GeoYielders:public Alien
{
    public:
    void kill(); //function to kill the alien based on how many times it is hit by player
    GeoYielders(SDL_Texture*);
};

class ThunderBearers:public Alien
{
    public:
    void kill();
    ThunderBearers(SDL_Texture*);
};

class StormCarriers:public Alien
{
    public:
    void kill();
    StormCarriers(SDL_Texture*);
};

class FireBreathers:public Alien
{
    public:
    void kill();
    FireBreathers(SDL_Texture*);
};