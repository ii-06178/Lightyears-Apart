#pragma once
#include "sprite.hpp"
#include "obstacle.hpp"
#include "obstacleTypes.hpp"
#include "abstractSpriteFactory.hpp"
class obstacleFactory:public abstractSpriteFactory
{   
    public:

    void emptyVirtual();
    Obstacle* getObstacle(std::string,SDL_Texture*);    //creating obstacle
};