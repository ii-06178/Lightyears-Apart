#include "alien.hpp"

Alien::Alien(SDL_Texture *img) : Sprite(img)
{ //constructor for all aliens
    turn_h = SDL_FLIP_NONE;
    cstate = true;
}

void Alien::drawSprite(SDL_Renderer *gRenderer)
{ //the draw function
    if (cstate == true)
    {
        general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h); //renders the alien
        
        mover.y += 10;
        //movement for x axis
        if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE)
        { //moving towards right walls
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
    }
}

void Alien::setstate(bool s)
{
    cstate = s;
}