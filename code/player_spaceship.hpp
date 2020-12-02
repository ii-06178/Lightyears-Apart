#include "sprite.hpp"
#include <SDL.h>
#include <SDL_ttf.h>
#pragma once

class PlayerSpaceship:public Sprite
{
    SDL_Rect l_src, l_mover;
    //int speed;
    int score=0; 
    int lives=3; //stores number of player lives left
    int fuel=50; //stores amount of fuel left 
    const int S_VELOCITY = 15;  //setting it as constant right now, will change this with conditions as we progress and calculate the milestones of the player
    int pos_x, pos_y;
    bool alive;
    public: 
    PlayerSpaceship(SDL_Texture*);
    //~PlayerSpaceship();
    void updateScore(int s);
    void updateLives(int l);
    void updateFuel(int f);
    int getScore();
    int getLives();
    int getFuel();
    SDL_Rect getmover();
    void setScore(int s);
    void setLives(int l);
    void setFuel(int f);
    void setMover(SDL_Rect m);
    int  getPos();
    void EventHandler(SDL_Event);
    void moveShip(bool s);
    void drawSprite(SDL_Renderer*);

    void shoot();
    
};
class Lives:public Sprite{
    int y[3] = {0, 50, 100};//position of lives, might have to change when the game logic is set
    int life=3;
    public:
    int getLives();
    void setLives(int l);
    Lives(SDL_Texture*);
    void drawSprite(SDL_Renderer*);
};
class Score
{ 
int scored;
public:
Score();
int getScore();
void setScore(int s);
void display(TTF_Font*,SDL_Texture*,SDL_Renderer*);
};
// class P_Laser:public Laser{
//     public:
//     P_Laser(SDL_Texture*);
//     void shoot(SDL_Renderer*);
// };