#include "location.hpp"
#include "sprite.hpp"
#pragma once

class Alien:public Sprite
{
    int strength; //stores either how many hits an alien needs to die OR how much damage they do to player with their hit. We need to choose one
    int difficultyLevel; //stores at which difficulty level i.e. above what score will this alien be displayed
    
    public:
    Alien();
    ~Alien();
    void shoot(); 
    virtual void kill(); //display animation of alien dying?? - not a priority rn!
    void setStrength(int s);
    void setDifficulty(int d);
    int getStrength();
    int getDifficulty();
};