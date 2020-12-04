#include "obstacleFactory.hpp"

void obstacleFactory::emptyVirtual()
{
    
}
Obstacle * obstacleFactory::getObstacle(std::string obstacleType, SDL_Texture *img)
{
    Obstacle *getObstacleOfType;
    if (obstacleType == "meteor")
    {
        getObstacleOfType=new Meteor(img);
    }
    else if (obstacleType == "fireball")
    {
        getObstacleOfType=new Fireball(img);
    }
    else if (obstacleType == "thunderbolt")
    {
        getObstacleOfType=new Thunderbolt(img);
    }
    else
    {
        getObstacleOfType=NULL;
    }
    
    return getObstacleOfType;
}