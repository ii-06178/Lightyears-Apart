#include <iostream>
#include "sprite.hpp"
#include "alien.hpp"
#include "obstacle.hpp"
#include "obstacleTypes.hpp"
#include "obstacleFactory.hpp"
#include "abstractSpriteFactory.hpp"
#include "alienFactory.hpp"
Alien* abstractSpriteFactory::getAlien(std::string alientype,SDL_Texture* img)
{
return NULL;
}
Obstacle* abstractSpriteFactory::getObstacle(std::string obstacletype,SDL_Texture* img)
{
return NULL;
}

abstractSpriteFactory* abstractFactoryProducer::getFactory(std::string factorytype)
{
abstractSpriteFactory* factoryOfType;
if (factorytype=="alien")
{
    factoryOfType=new alienFactory() ;
}
else if (factorytype=="obstacle")
{   
        factoryOfType=new obstacleFactory() ;
}
else
{
    factoryOfType=NULL;
}

return factoryOfType;
}