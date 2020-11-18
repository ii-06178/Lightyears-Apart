#include "obstacle.hpp"
#pragma once

class Meteor:public Obstacle
{
    public:
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Fireball:public Obstacle
{
    public:
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

class Thunderbolt:public Obstacle
{
    public:
    void destroy(); //function to destroy the obstacle based on the number/type of hits by player
};

