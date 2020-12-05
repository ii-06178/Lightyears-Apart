#include "obstacleFactory.hpp"

void obstacleFactory::emptyVirtual(){}

Obstacle * obstacleFactory::getObstacle(std::string obstacleType, SDL_Texture *img){

    Obstacle *getObstacleOfType;    //Obstacle object

    if (obstacleType == "meteor"){

        getObstacleOfType=new Meteor(img);  //creating meteor
    }
    else if (obstacleType == "fireball"){

        getObstacleOfType=new Fireball(img);    //creating fireball
    }
    else if (obstacleType == "thunderbolt"){

        getObstacleOfType=new Thunderbolt(img); //creating thunderbolt
    }
    else{

        getObstacleOfType=NULL;
    }
    
    return getObstacleOfType;
}