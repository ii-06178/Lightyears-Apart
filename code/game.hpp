#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
//New included files
#include "sprite.hpp"
#include "Laser.hpp"
#include "player_spaceship.hpp"
#include "alien.hpp"
#include "alienTypes.hpp"
#include "obstacleTypes.hpp"
#include "LinkedList.hpp"
#include "BGTexture.hpp"
#pragma once

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    SDL_Texture* iScreen=NULL;
    SDL_Texture* wScreen=NULL;
    SDL_Texture* gwScreen=NULL;
    SDL_Texture* glScreen=NULL;
    bool menu=true;
	bool game=false;
	bool ins=false;
    bool state=true;
    bool game_is_won=false;
    bool game_is_lost=false;
    int count_tb,count_fb,count_sc,count_gy;
    Mix_Music *bgMusic = NULL;
    Mix_Music *bgMusic2 = NULL;
    Mix_Chunk *shooting= NULL;
    Mix_Chunk *hit=NULL;
    BGTexture texture;  //For animating the background texture
    LinkedList listofobjects;
    //list<Lives*> lives;
     Uint32 start = 0;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    void drawObj();
    void updatealien();
    void updateplayer();
    void updateobstacles();

    void updateLives();
};

