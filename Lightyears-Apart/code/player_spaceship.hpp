#include "sprite.hpp"
#include <SDL.h>
#pragma once

class PlayerSpaceship:public Sprite
{
    int score; 
    int lives; //stores number of player lives left
    int fuel; //stores amount of fuel left 

    public: 
    PlayerSpaceship(SDL_Texture*);
    //~PlayerSpaceship();
    void updateScore(int s);
    void updateLives(int l);
    void updateFuel(int f);
    int getScore();
    int getLives();
    int getFuel();
    void drawSprite(SDL_Renderer*);

    void shoot();
    
};
