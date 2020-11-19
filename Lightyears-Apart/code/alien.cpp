#include "alien.hpp"

Alien::Alien(SDL_Texture* img):Sprite(img){//constructor for all aliens, I was thinking of using the Sprite constructor, but didn't for now, might change it later.
}
void Alien::drawSprite(SDL_Renderer* gRenderer){//the draw function
    SDL_RenderCopy(gRenderer, asset, &src, &mover);
}
void Alien::shoot()
{

}

void Alien::kill()
{

}

void Alien::setStrength(int s)
{
    strength = s;
}
void Alien::setDifficulty(int d)
{
    difficultyLevel = d;
}
int Alien::getStrength()
{
    return strength;
}
int Alien::getDifficulty()
{
    return difficultyLevel;
}
