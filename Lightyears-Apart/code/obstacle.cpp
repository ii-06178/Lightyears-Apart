#include "obstacle.hpp"

Obstacle::Obstacle(SDL_Texture* img):Sprite(img)
{
    
}
void Obstacle::drawSprite(SDL_Renderer* gRenderer){
    SDL_RenderCopy(gRenderer, asset, &src, &mover);
}

void Obstacle::setStrength(int s)
{
    strength = s;
}

int Obstacle::getStrength()
{
    return strength;
}

Obstacle::~Obstacle()
{
    
}