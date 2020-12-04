#include "sprite.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;
#pragma once

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
    int pos_x, pos_y;
    bool alive;

public:
    static PlayerSpaceship *getinstance(SDL_Texture *);
    void updateScore(int s);
    void updateLives(int l);
    void updateFuel(int f);
    int operator - (int);  //operator overloading
    int getScore();
    int getLives();
    int getFuel();
    SDL_Rect getmover();
    void setScore(int s);
    void setLives(int l);
    void setFuel(int f);
    void setFuel();
    void updateFuel(Uint32);
    void setMover(SDL_Rect m);
    int getPos();
    void EventHandler(SDL_Event);
    void moveShip(bool s);
    void drawSprite(SDL_Renderer *);
    void shoot();
};
class Lives : public Sprite
{
    int y[3] = {0, 50, 100}; //position of lives, might have to change when the game logic is set
    int life = 3;

public:
    int getLives();
    void setLives(int l);
    Lives(SDL_Texture *);
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
    int getFuel();
    void setFuel(int f);

    Fuel(SDL_Texture *);
    void drawSprite(SDL_Renderer *) override;
};
