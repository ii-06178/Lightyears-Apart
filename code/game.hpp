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
#include "player_spaceship.hpp"
#include "alien.hpp"
#include "alienTypes.hpp"
#include "obstacleTypes.hpp"
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
    bool menu=true;
	bool game=false;
	bool ins=false;

    Mix_Music *bgMusic = NULL;

    BGTexture texture;  //For animating the background texture

    //list<Lives*> lives;

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
    void drawObj();

    void updateLives();
};

