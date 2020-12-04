#pragma once
#include "sprite.hpp"
#include "alien.hpp"
#include "obstacle.hpp"
class abstractSpriteFactory
{
public:
virtual void emptyVirtual()=0;
virtual Alien*  getAlien(std::string alientype,SDL_Texture* img);
virtual Obstacle* getObstacle(std::string obstacletype,SDL_Texture* img);

};

class abstractFactoryProducer
{public:

abstractSpriteFactory* getFactory(std::string factorytype);
};