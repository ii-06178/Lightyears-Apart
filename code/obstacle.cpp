#include "obstacle.hpp"

Obstacle::Obstacle(SDL_Texture *img) : Sprite(img){
    destroyed = false;
    cstate = true;
    strength = 0;
    contact = false;
}

int Obstacle::frame = 0;
void Obstacle::drawSprite(SDL_Renderer *gRenderer)
{
    if (cstate == true)
    {
        if (thunder == true)//animating till the thunder is present on the screen
        {
            SDL_Rect *currentframe = &T_src[frame / 2];
            SDL_RenderCopy(gRenderer, asset, currentframe, &mover);
            SDL_RenderPresent(gRenderer);
            ++frame;
            if (frame / 2 >= 2) //resetting to frame zero
                frame = 0;

            if (mover.h >= 600) {//destroying the thunder if it doesn't collide with the ship and reaches the end of the screen
                thunder = false;
                hasdestroyed();
            }
            mover.h += 40;
        }
        else//setting moving conditions for meteor and fireball
        {
            general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h);

            mover.y += 10;  //movement on y axis
            
            //movement on x axis
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
        }
    }
}

void Obstacle::setDestroyed(bool d){
    destroyed = d;
}

//get and set for the strength
void Obstacle::setStrength(int s)
{
    strength = s;
}
int Obstacle::getStrength()
{
    return strength;
}

//Destructor for the obstacles
Obstacle::~Obstacle()
{
    SDL_DestroyTexture(asset);
    asset = NULL;
    src = {0,0,0,0};
    mover = {0,0,0,0};
    strength = 0;
}

//set for the state
void Obstacle::setstate(bool s)
{
    cstate = s;
}

//getting mover of the obstacle
SDL_Rect Obstacle::getmover()
{
    return mover;
}

//get and set for destroyed flag
void Obstacle::hasdestroyed()
{
    destroyed = true;
}
bool Obstacle::getdestroyed()
{
    return destroyed;
}

//get and ser for contact with the ship
void Obstacle::setcontact()
{
    contact = true;
}
bool Obstacle::getcontact()
{
    return contact;
}