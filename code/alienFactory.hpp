#pragma once
#include "sprite.hpp"
#include "alien.hpp"
#include "alienTypes.hpp"
#include "abstractSpriteFactory.hpp"
class alienFactory:public abstractSpriteFactory
{
public:
void emptyVirtual();
Alien* getAlien(std::string alientype,SDL_Texture* img);
    
};