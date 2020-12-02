#include "alien.hpp"
#pragma once

class GeoYielders:public Alien
{   bool destroyed=false;
    int shoots=4;
    int attacked=1;
    int points=40;
    public:
    void hasdestroyed();
    bool getdestroyed();
    int getPoints();
    void kill(); //function to kill the alien based on how many times it is hit by player
    GeoYielders(SDL_Texture*);
    SDL_Rect getmover();
};

class ThunderBearers:public Alien
{bool destroyed=false;
int shoots=2;
int points=20;
    int attacked=1;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    int getPoints();
    ThunderBearers(SDL_Texture*);
    SDL_Rect getmover();
};

class StormCarriers:public Alien
{bool destroyed=false;
int shoots=3;
int points=30;
    int attacked=1;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    int getPoints();
    StormCarriers(SDL_Texture*);
    SDL_Rect getmover();
};

class FireBreathers:public Alien
{bool destroyed=false;
int shoots=1;
int points=10;
    int attacked=1;
    public:
    void hasdestroyed();
    bool getdestroyed();
    void kill();
    int getPoints();
    FireBreathers(SDL_Texture*);
    SDL_Rect getmover();
};