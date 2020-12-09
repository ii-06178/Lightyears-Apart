#include "sprite.hpp"
#include <SDL.h>
#include <sstream>
#include <iostream>
#include <SDL_ttf.h>

using namespace std;

#pragma once
//applying singleton design pattern on PlayerSpaceship
class PlayerSpaceship : public Sprite
{
    SDL_Rect l_src, l_mover;
    static PlayerSpaceship *obj;
    PlayerSpaceship(SDL_Texture *);
    int score ;
    int lives;  //stores number of player lives left
    int fuel; //stores amount of fuel left

    const int defaultFuel=140;
    const int S_VELOCITY = 15; 

    int pos_x, pos_y;   //x and y position of the ship
    int x_speed, y_speed; //speed of the sprite
    bool alive;

    public:

    static PlayerSpaceship *getinstance(SDL_Texture *);
    int operator - (int);  //operator overloading

    //get functions
    int getScore();
    int getLives();
    int getFuel();
    SDL_Rect getmover();

    //set functions
    void setScore(int s);
    void setLives(int l);
    void setFuel(int f);
    void setFuel();

    void updateFuel(Uint32);    //update fuel
    //ship movement and draw functions
    void EventHandler(SDL_Event);
    void moveShip(bool s);
    void drawSprite(SDL_Renderer *);
};
class Lives : public Sprite
{
    int y[3] = {0, 50, 100}; //position of lives
    int life;

    public:

    Lives(SDL_Texture *);
    int getLives();
    void setLives(int l);
    void drawSprite(SDL_Renderer *);
};
class Score
{
    int scored;

    public:

    Score();
    int getScore();
    void setScore(int s);
    void display(TTF_Font *, SDL_Texture *, SDL_Renderer *);
};
class Fuel : public Sprite
{
    int fuelLeft = 190;
    SDL_Rect rect;

    public:

    Fuel(SDL_Texture *);
    int getFuel();
    void setFuel(int f);
    void drawSprite(SDL_Renderer *) override;
};
