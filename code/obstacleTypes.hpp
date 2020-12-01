#include "obstacle.hpp"

#pragma once

class Meteor:public Obstacle
{   bool destroyed=false;
    public:
    Meteor(SDL_Texture*);
    void hasdestroyed();
    bool getdestroyed();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Fireball:public Obstacle
{   bool destroyed=false;
    public:
    Fireball(SDL_Texture*);
    void hasdestroyed();
    bool getdestroyed();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Thunderbolt:public Obstacle
{   bool destroyed=false;
    public:
    Thunderbolt(SDL_Texture*);
    void hasdestroyed();
    bool getdestroyed();
    SDL_Rect getmover();
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

