#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <fstream>

//Game Header files
#include "Laser.hpp"
#include "player_spaceship.hpp"
#include "abstractSpriteFactory.hpp"
#include "LinkedList.hpp"
#include "BGTexture.hpp"
#include "gameSave.hpp"

#pragma once

class Game
{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window *gWindow = NULL;

    //The window renderer
    SDL_Renderer *gRenderer = NULL;

    //Current displayed texture
    SDL_Texture *gTexture = NULL;
    //global reference to png image sheets

    //Uint32 current_time = SDL_GetTicks() + start;
    Uint32 current_time = SDL_GetTicks() - start;

    //Textures for the screens
    SDL_Texture *assets = NULL;
    SDL_Texture *iScreen = NULL;
    SDL_Texture *wScreen = NULL;
    SDL_Texture *gwScreen = NULL;
    SDL_Texture *glScreen = NULL;
    SDL_Texture *score_display = NULL;

    //boolean flags for the screens
    bool menu = true;
    bool gamecond = false;
    bool load = false;
    bool ins = false;
    bool state = true;
    bool game_is_won = false;
    bool game_is_lost = false;

    //Music objects
    Mix_Music *bgMusic = NULL;
    Mix_Music *bgMusic2 = NULL;
    Mix_Music *bgMusicW = NULL;
    Mix_Music *bgMusicL = NULL;
    Mix_Chunk *shooting = NULL;
    Mix_Chunk *hit = NULL;

    TTF_Font *font = NULL;

    BGTexture texture; //For animating the background texture

    LinkedList listofobjects;
    int start = 0;  //for noting the starting point of the game
    gameSave game;  //for loading and saving the game
    
	//creating game objects
	int count_aliens = 0;
	Score scoring;
	abstractFactoryProducer* abfactprod= new abstractFactoryProducer;
	abstractSpriteFactory* alfact= abfactprod->getFactory("alien");
	abstractSpriteFactory* obfact= abfactprod->getFactory("obstacle");
    PlayerSpaceship *p = NULL;
    Lives l = NULL;
    Fuel f = NULL;

public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture *loadTexture(std::string path);
    void run();
    void drawObj();
    void updatealien(PlayerSpaceship *);
    void updateplayer(PlayerSpaceship *);
    void updateobstacles(PlayerSpaceship *);
};
