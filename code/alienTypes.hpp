#include "alien.hpp"
#pragma once

class GeoYielders:public Alien
{
    public:
    void kill(); //function to kill the alien based on how many times it is hit by player
};

class ThunderBearers:public Alien
{
    public:
    void kill();
};

class StormCarriers:public Alien
{
    public:
    void kill();
};

class FireBreathers:public Alien
{
    public:
    void kill();
};