#include <iostream>
#include "game.hpp"
using namespace std;
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Lightyears Apart", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	assets = loadTexture("sprite.png");
	gTexture = loadTexture("stars.png");
	wScreen = loadTexture("Welcome Screen.png");
	iScreen = loadTexture("Instructions Screen.png");
	bgMusic = Mix_LoadMUS("SkyFire (Title Screen).wav");
	bgMusic2 = Mix_LoadMUS("Space Heroes.wav");
	shooting = Mix_LoadWAV("laser4.wav");
	// hit=Mix_LoadWAV();
	texture.assets = gTexture;

	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	if (bgMusic == NULL || bgMusic2 == NULL || shooting== NULL)
	{
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	texture.~BGTexture();
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	Mix_FreeMusic(bgMusic2);
	bgMusic2 = NULL;
	Mix_FreeChunk(shooting);
	shooting = NULL;
	// Mix_FreeChunk(hit);
	// hit=NULL;
	//Quit SDL subsystems
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//storing dimensions of the bg
		texture.bgWidth = loadedSurface->w;
		texture.bgHeight = loadedSurface->h;

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//texture.assets = newTexture;
	return newTexture;
}
//list<Alien *>::iterator A;//list for aliens
void Game::updatealien()
{
}
void Game::updateplayer()
{
}
void Game::updateobstacles()
{
}
void Game::drawObj()
{
}

void Game::run()
{
	bool quit = false;
	SDL_Event e;
	PlayerSpaceship p = {assets};
	//ThunderBearers th = {assets};
	ThunderBearers t = {assets};
	GeoYielders g = {assets};
	StormCarriers s = {assets};
	FireBreathers f = {assets};
	Meteor m = {assets};
	Fireball fb = {assets};
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			p.EventHandler(e); //handles ship events

			//texture.drawBG(gRenderer);	//moving background

			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				cout << xMouse << ", " << yMouse << endl;

				if (menu == true)
				{ 

					if (ins == false)
					{
						if (xMouse >= 330 and xMouse <= 470 and yMouse >= 370 and yMouse <= 400)
						{
							menu = false;
							ins = false;
							game = true;
						}
						if (xMouse >= 325 and xMouse <= 470 and yMouse >= 420 and yMouse <= 450)
						{
							menu = true;
							ins = true;
							game = false;
						}
						if (xMouse >= 325 and xMouse <= 470 and yMouse >= 475 and yMouse <= 505)
						{
							menu = false;
							ins = false;
							game = false;
							quit = true;
						}
					}
					else if (ins = true)
					{
						if (xMouse >= 605 and xMouse <= 706 and yMouse >= 490 and yMouse <= 520) //going back from instructions back to menu
						{
							menu = true;
							ins = false;
							game = false;
						}
					}
				}
			}
			if (game == true)
			{
				p.moveShip();
				if (e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_SPACE)
						{
							Mix_PlayChannel(-1, shooting, 0);
						}
					}
			}
		}

		SDL_RenderClear(gRenderer); //removes everything from renderer
		//for screens
		if (menu == true)
		{
			if (Mix_PlayingMusic() == 0)
			{
				//Play the music
				Mix_PlayMusic(bgMusic, -1);
			}
			// else
			// {
			// 	Mix_PauseMusic();
			// }
			texture.drawBG(gRenderer);
			if (ins == false)
			{
				
				SDL_RenderCopy(gRenderer, wScreen, NULL, NULL);
			}
			if (ins == true)
			{	
				SDL_RenderCopy(gRenderer, iScreen, NULL, NULL);
			}
		}
		// else
		// {
		// 	texture.drawBG(gRenderer);
		// }
		//for game
		if (game == true)
		{	texture.drawBG(gRenderer);
			Mix_HaltMusic();
			// if (Mix_PlayingMusic() == 0)
			// 	{
			// 	Mix_PlayMusic(bgMusic2, 2);
			// 	}
			//ThunderBearers t = {assets}; FireBreathers f = {assets}; StormCarriers s = {assets}; GeoYielders g = {assets};

			p.drawSprite(gRenderer);
			m.drawSprite(gRenderer);
			fb.drawSprite(gRenderer);
			//tb.drawSprite(gRenderer);

			//th.drawSprite(gRenderer);
			t.drawSprite(gRenderer);
			g.drawSprite(gRenderer);
			f.drawSprite(gRenderer);
			s.drawSprite(gRenderer);
		}

		//***********************draw the objects here********************

		//****************************************************************

		SDL_RenderPresent(gRenderer); //displays the updated renderer

		SDL_Delay(200); //causes sdl engine to delay for specified miliseconds
	}
}
