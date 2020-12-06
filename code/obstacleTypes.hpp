#include "obstacle.hpp"

#pragma once

//Child classes of the Obstacle class
class Meteor : public Obstacle{

    public:
    Meteor(SDL_Texture *);

};

class Fireball : public Obstacle{
    
    public:
    Fireball(SDL_Texture *);

};

class Thunderbolt : public Obstacle{

    public:
    Thunderbolt(SDL_Texture *);
};
