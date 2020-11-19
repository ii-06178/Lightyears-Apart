#include "sprite.hpp"
#include <SDL.h>
#pragma once

class PlayerSpaceship:public Sprite
{
    //int speed;
    int score; 
    int lives; //stores number of player lives left
    int fuel; //stores amount of fuel left 
    const int S_VELOCITY = 15;  //setting it as constant right now, will change this with conditions as we progress and calculate the milestones of the player
    int pos_x, pos_y;

    public: 
    PlayerSpaceship(SDL_Texture*);
    //~PlayerSpaceship();
    void updateScore(int s);
    void updateLives(int l);
    void updateFuel(int f);
    int getScore();
    int getLives();
    int getFuel();

    void EventHandler(SDL_Event);
    void moveShip();
    void drawSprite(SDL_Renderer*);

    void shoot();
    
};
