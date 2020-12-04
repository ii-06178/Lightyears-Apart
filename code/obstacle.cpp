#include "obstacle.hpp"

Obstacle::Obstacle(SDL_Texture *img) : Sprite(img)
{
}

int Obstacle::frame = 0;
void Obstacle::drawSprite(SDL_Renderer *gRenderer)
{
    if (cstate == true)
    {
        if (thunder == true)
        {
            // printf("thunder == true, thunder condition is working\n");
            SDL_Rect *currentframe = &T_src[frame / 2];
            SDL_RenderCopy(gRenderer, asset, currentframe, &mover);
            SDL_RenderPresent(gRenderer);
            ++frame;
            if (frame / 2 >= 2)
                frame = 0;
            mover.h++;
        }
        else
        {
            general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h);
            if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE)
            {
                mover.x += 15;
            }
            else if (mover.x >= 800 - mover.w)
                turn_h = SDL_FLIP_HORIZONTAL;

            if (mover.x > 0 && turn_h == SDL_FLIP_HORIZONTAL)
            {
                mover.x -= 15;
            }
            else if (mover.x <= 0)
                turn_h = SDL_FLIP_NONE;
            mover.y += 10;
        }
    }
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
void Obstacle::setstate(bool s)
{
    cstate = s;
}
SDL_Rect Obstacle::getmover()
{
    return mover;
}
void Obstacle::hasdestroyed()
{
    destroyed = true;
}
bool Obstacle::getdestroyed()
{
    return destroyed;
}
void Obstacle::setcontact()
{
    contact = true;
}
bool Obstacle::getcontact()
{
    return contact;
}