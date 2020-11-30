#include "sprite.hpp"
#include <SDL.h>
#pragma once

class PlayerSpaceship:public Sprite
{
    SDL_Rect l_src, l_mover;
    //int speed;
    int score; 
    int lives; //stores number of player lives left
    int fuel; //stores amount of fuel left 
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
    int  getPos();
    void EventHandler(SDL_Event);
    void moveShip(bool s);
    void drawSprite(SDL_Renderer*);

    void shoot();
    
};
class Lives:public Sprite{
    int y[3] = {0, 50, 100};//position of lives, might have to change when the game logic is set
    public:
    Lives(SDL_Texture*);
    void drawSprite(SDL_Renderer*);
};
// class P_Laser:public Laser{
//     public:
//     P_Laser(SDL_Texture*);
//     void shoot(SDL_Renderer*);
// };