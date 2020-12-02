#include "alien.hpp"

Alien::Alien(SDL_Texture *img) : Sprite(img)
{ //constructor for all aliens, I was thinking of using the Sprite constructor, but didn't for now, might change it later.
    turn_h = SDL_FLIP_NONE;
    up = false;
    cstate = true;
}
void Alien::drawSprite(SDL_Renderer *gRenderer)
{ //the draw function

    general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h); //renders the alien
    if (cstate == true)
    {
        if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE)
        { //moving towards right wallssswaarrrrra
            mover.x += 20;
        }
        else if (mover.x >= 800 - mover.w)
            turn_h = SDL_FLIP_HORIZONTAL; //turns when hit the right wall
        if (mover.x > 0 && turn_h == SDL_FLIP_HORIZONTAL)
        { //moving towards left wall
            mover.x -= 20;
        }
        else if (mover.x <= 0)
            turn_h = SDL_FLIP_NONE; //turns when hit the left wall

        //movement for y axis
        if (mover.y < 600 - mover.h && up == false)
        { //moving down
            mover.y += 10;
        }
        else if (mover.y >= 600 - mover.h)
            up = true; //strikes bottom

        if (mover.y > 0 && up == true)
        { //moving up
            mover.y -= 10;
        }
        else if (mover.y <= 0)
            up = false; //stikes roof
    }
    //movement for x axis
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
void Alien::setstate(bool s)
{
cstate=s;
}