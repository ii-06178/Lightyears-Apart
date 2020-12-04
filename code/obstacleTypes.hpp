#include "obstacle.hpp"

#pragma once

class Meteor : public Obstacle
{
    bool destroyed ;
    int strength;

public:
    Meteor(SDL_Texture *);
    void hasdestroyed();
    bool getdestroyed();
    void setStrength(int s);

    int getStrength();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Fireball : public Obstacle
{
    bool destroyed;
    int strength;

public:
    Fireball(SDL_Texture *);
    void hasdestroyed();
    void setStrength(int s);
    int getStrength();
    bool getdestroyed();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Thunderbolt : public Obstacle
{
    bool destroyed;
    int strength;
    SDL_Rect src[2];
    static int frame;


public:
    Thunderbolt(SDL_Texture *);
    void hasdestroyed();
    bool getdestroyed();
    void setStrength(int s);
    int getStrength();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
    // void drawBolt(SDL_Renderer *);
};
