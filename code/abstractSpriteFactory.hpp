#pragma once
#include "sprite.hpp"
#include "alien.hpp"
#include "obstacle.hpp"


class abstractSpriteFactory
{
    public:

    virtual void emptyVirtual()=0;
    virtual Alien*  getAlien(std::string alientype,SDL_Texture* img);   //to craete alien
    virtual Obstacle* getObstacle(std::string obstacletype,SDL_Texture* img);   //to create obstacle

};

class abstractFactoryProducer
{
    public:
    
    abstractSpriteFactory* getFactory(std::string factorytype); //to create the object either alien or obstacle
};