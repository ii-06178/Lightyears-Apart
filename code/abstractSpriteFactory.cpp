#include <iostream>

#include "obstacleFactory.hpp"
#include "alienFactory.hpp"
#include "abstractSpriteFactory.hpp"

Alien* abstractSpriteFactory::getAlien(std::string alientype,SDL_Texture* img){

    return NULL;
}
Obstacle* abstractSpriteFactory::getObstacle(std::string obstacletype,SDL_Texture* img){

    return NULL;
}

abstractSpriteFactory* abstractFactoryProducer::getFactory(std::string factorytype){

    abstractSpriteFactory* factoryOfType;   //abstract factory object

    if (factorytype=="alien"){  //creating alien object when the factory type is alien

        factoryOfType=new alienFactory();
    }
    else if (factorytype=="obstacle"){  //creating obstacle when the factory type is obstacle

            factoryOfType=new obstacleFactory() ;
    }
    else{
        
        factoryOfType=NULL;
    }
    return factoryOfType;
}