#include "location.hpp"
#include "sprite.hpp"

void Sprite::setLoc(Location l)
{
    loc = l;
}
void Sprite::setWidth(int w)
{
    width = w;
}
void Sprite::setHeight(int h)
{
    height = h;
}
Location Sprite::getLoc()
{
    return loc;
}
int Sprite::getWidth()
{
    return width;
}
int Sprite::getHeight()
{
    return height;
}
void Sprite::setHitCount(int hc)
{
    hitCount = hc;
}
void Sprite::setSpeed(int s)
{
    speed = s;
}
int Sprite::getHitCount()
{
    return hitCount;
}
int Sprite::getSpeed()
{
    return speed;
}

void Sprite::drawSprite()
{

}

SDL_Rect Sprite::spriteSource()
{//returns the source for next frame needed for animation
    // SDL_Rect s[3] = {{0,0,160,133}, {0,133,160,133}, {0,266,160,133}};
    // SDL_Rect temp;
    SDL_Rect s = {268,273,0,0};
//     temp = s[frame];

//    if (frame == 2)
//    {
//        frame = 0;
//    }
//    else
//    {
//        frame++;
//    }
    return s;
}

SDL_Rect Sprite::moveSprite()
{//returns a position for the sprite to be displayed at
    SDL_Rect m = {x, y, 50, 50};
    return m;
}