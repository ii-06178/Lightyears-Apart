#include "alien.hpp"
#pragma once

class GeoYielders : public Alien
{
    bool destroyed = false;
    int shoots = 4; //required to kill the alien
    int strength = 25;  //the amount of fuel its laser reduces
    int attacked = 1;
    int points = 40;    //points the player gets after killing them

public:

    GeoYielders(SDL_Texture *);
    void hasdestroyed();
    bool getdestroyed(); //check
    void setStrength(int s);
    int getStrength();
    int getPoints();
    SDL_Rect getmover();
};

class ThunderBearers : public Alien
{
    bool destroyed = false;
    int shoots = 2;
    int points = 20;
    int strength = 15;
    int attacked = 1;

public:
    void hasdestroyed();
    bool getdestroyed();
    void setStrength(int s);
    int getStrength();
    void kill();
    int getPoints();
    ThunderBearers(SDL_Texture *);
    SDL_Rect getmover();
};

class StormCarriers : public Alien
{
    bool destroyed = false;
    int shoots = 3;
    int points = 30;
    int attacked = 1;
    int strength = 20;

public:
    void hasdestroyed();
    bool getdestroyed();
    void setStrength(int s);
    int getStrength();
    void kill();
    int getPoints();
    StormCarriers(SDL_Texture *);
    SDL_Rect getmover();
};

class FireBreathers : public Alien
{
    bool destroyed = false;
    int shoots = 1;
    int points = 10;
    int strength = 10;
    int attacked = 1;

public:
    void hasdestroyed();
    bool getdestroyed();
    void setStrength(int s);
    int getStrength();
    void kill();
    int getPoints();
    FireBreathers(SDL_Texture *);
    SDL_Rect getmover();
};