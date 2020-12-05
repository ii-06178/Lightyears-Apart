#include "Laser.hpp"

Laser::Laser(SDL_Texture *img) : Sprite(img)
{
    //hero laser
    src[0].x = 0;
    src[0].y = 290;
    src[0].w = 50;
    src[0].h = 110;

    //alien laser
    src[1].x = 0;
    src[1].y = 410;
    src[1].w = 50;
    src[1].h = 110;

    mover.x = 0;
    mover.y = 0;
    mover.w = 20;
    mover.h = 70;

    cstate = true;
}

//set and get for strength
void Laser::setstrength(int s)
{
    strength = s;
}
int Laser::getstrength()
{
    return strength;
}

void Laser::setPos(SDL_Rect s)
{
    mover.x= s.x + (s.w-mover.w)/2;
    if (type == "hero")
    {
        mover.y = s.y - 70;
    }
    if (type == "alien")
    {
        mover.y = s.y + 70;
    }
}
void Laser::setType(std::string t)
{
    type = t;
}
SDL_Rect Laser::getmover()
{
    return mover;
}
void Laser::setcstate(bool s)
{
    cstate = s;
}

void Laser::drawSprite(SDL_Renderer *gRenderer)
{
    if (type == "hero"){ 

        SDL_RenderCopy(gRenderer, asset, &src[0], &mover);

        if (cstate == true)
        {
            mover.y = mover.y - 30;
        }
    }
    if (type == "alien")
    {
        SDL_RenderCopy(gRenderer, asset, &src[1], &mover);
        if (cstate == true)
        {
            mover.y = mover.y + 30;
        }
    }
}

//set and get for contact
void Laser::setcontact()
{
    contact = true;
}
bool Laser::getcontact()
{
    return contact;
}
