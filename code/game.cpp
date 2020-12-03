#include <iostream>
#include "game.hpp"
#include "LinkedList.hpp"
// #include "gameSave.hpp"
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
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
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
	gwScreen = loadTexture("win screen 2.png");
	glScreen = loadTexture("game over screen 1.png");
	font = TTF_OpenFont("Westmeath.ttf", 32);
	bgMusic = Mix_LoadMUS("SkyFire (Title Screen).wav");
	bgMusic2 = Mix_LoadMUS("Space Heroes.wav");
	bgMusicW = Mix_LoadMUS("Victory Tune.wav");
	bgMusicL = Mix_LoadMUS("Defeated.wav");
	shooting = Mix_LoadWAV("laser4.wav");
	hit = Mix_LoadWAV("twoTone2.wav");

	// hit=Mix_LoadWAV();
	texture.assets = gTexture;
	if (font == NULL)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	if (gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}

	if (bgMusic == NULL || bgMusic2 == NULL || shooting == NULL)
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
	SDL_DestroyTexture(score_display);
	score_display = NULL;
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;
	SDL_DestroyTexture(iScreen);
	iScreen = NULL;
	SDL_DestroyTexture(wScreen);
	wScreen = NULL;
	SDL_DestroyTexture(gwScreen);
	gwScreen = NULL;
	SDL_DestroyTexture(glScreen);
	glScreen = NULL;
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	Mix_FreeMusic(bgMusic2);
	bgMusic2 = NULL;
	Mix_FreeMusic(bgMusicW);
	bgMusicW = NULL;
	Mix_FreeMusic(bgMusicL);
	bgMusicL = NULL;
	Mix_FreeChunk(shooting);
	shooting = NULL;
	Mix_FreeChunk(hit);
	hit = NULL;
	// Mix_FreeChunk(hit);
	// hit=NULL;
	//Quit SDL subsystems
	TTF_CloseFont(font);
	TTF_Quit();
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
void Game::updatealien(PlayerSpaceship *pl)
{
	listofobjects.deletealien(assets, pl);
}
void Game::updateplayer(PlayerSpaceship *pl)
{
	listofobjects.check_collision_with_shooter(pl);
	listofobjects.check_collisions_with_obstacles(pl);
	listofobjects.deletelaser(assets);
}
void Game::updateobstacles(PlayerSpaceship *pl)
{
	listofobjects.deleteobstacle(assets);
}
void Game::drawObj()
{
	listofobjects.drawAllaliens(gRenderer, assets, state);
	listofobjects.drawAllobstacles(gRenderer, state);
	listofobjects.drawAlllasers(gRenderer, state);
}

void Game::updateLives()
{
}
void Game::run()
{
	bool quit = false;
	int count_aliens = 0;
	SDL_Event e;
	//PlayerSpaceship *p = new PlayerSpaceship(assets);
	PlayerSpaceship *p = PlayerSpaceship::getinstance(assets);
	Score scoring;
	//ThunderBearers th = {assets};

	// Meteor m = {assets};
	// Fireball fb = {assets};
	Lives l = {assets};
	Fuel f = {assets};
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
			p->EventHandler(e); //handles ship events

			//texture.drawBG(gRenderer);	//moving background
			if (e.type == SDL_KEYDOWN) //when it is pressed once
			{
				if (e.key.keysym.sym == SDLK_p && game == true) //if it is the key k
				{
					if (state == false) //resume the game if it is already paused
					{
						state = true;
					}
					else
					{
						state = false; //pause the game
					}
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				//cout << xMouse << ", " << yMouse << endl;

				if (menu == true)
				{

					if (ins == false)
					{
						if (xMouse >= 330 and xMouse <= 470 and yMouse >= 370 and yMouse <= 400)
						{
							menu = false;
							ins = false;
							game = true;
							Mix_HaltMusic();
							start = SDL_GetTicks();
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
				if (Mix_PlayingMusic() == 0)
				{
					Mix_PlayMusic(bgMusic2, -1);
					Mix_VolumeMusic(128 / 8);
				}
				p->moveShip(state);
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_SPACE)
					{
						Laser *hlaser = new Laser(assets);
						SDL_Rect mo = p->getmover();
						//std::cout<<"what we are passing"<<mo.x<<","<<mo.y<<std::endl;
						hlaser->setPos(mo);
						listofobjects.addUnit(hlaser, "hero");

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

		//for game
		if (game == true)
		{
			Uint32 current_time = SDL_GetTicks() - start;
			Uint32 m_time = ((SDL_GetTicks() - start) % 10000);
			Uint32 f_time = ((SDL_GetTicks() - start) % 30000);
			//cout << "m_time " << m_time << endl;
			texture.drawBG(gRenderer);

			p->drawSprite(gRenderer);
			listofobjects.check_collision_with_enemyshooter(p, hit);
			listofobjects.check_hit_with_obstacle(p, hit);
			//ThunderBearers t = {assets}; FireBreathers f = {assets}; StormCarriers s = {assets}; GeoYielders g = {assets};
			if (count_aliens < 100 && state == true)
			{

				// int prob;
				// prob = rand() % 10000000;
				// if (prob <= 1)
				// {
				if ((current_time > (4000 * count_fb)) && count_fb < 25)
				{
					FireBreathers *f = new FireBreathers(assets);
					count_fb++;
					listofobjects.addUnit(f);
					count_aliens++;
					//cout<<"count_fb "<<count_fb<<endl;
				}
				if (m_time <= 100)
				{
					Meteor *m = new Meteor(assets);
					listofobjects.addUnit(m);
				}
				if (f_time <= 100)
				{
					Fireball *fi = new Fireball(assets);
					listofobjects.addUnit(fi);
				}
				// }

				if (count_fb > 24)
				{
					//cout<<"current_time should be 100000, but it is "<<current_time<<endl;
					//cout<<"count_tb"<<count_tb<<endl;
					if ((current_time > ((4000 * 25) + (3500 * (count_tb)))) && count_tb < 25)
					{
						ThunderBearers *t = new ThunderBearers(assets);
						count_tb++;
						listofobjects.addUnit(t);
						count_aliens++;
					}
				}
				if (count_tb > 24)
				{
					if ((current_time > ((4000 * 24) + (3500 * 24) + (2500 * count_sc))) && count_sc < 25)
					{
						StormCarriers *s = new StormCarriers(assets);
						count_sc++;
						listofobjects.addUnit(s);
						count_aliens++;
					}
				}
				if (count_sc > 24)
				{
					if ((current_time > ((4000 * 24) + (3500 * 24) + (2500 * 24) + (1000 * count_gy))) && count_gy < 25)
					{
						GeoYielders *g = new GeoYielders(assets);
						count_gy++;
						listofobjects.addUnit(g);
						count_aliens++;
					}
				}
				//count_aliens=count_tb+count_fb+count_sc+count_gy;
			}

			if (count_aliens >= 100 && p->getLives() != 0)
			{
				//cout << listofobjects.check_empty_aliens() << endl;
				if (listofobjects.check_empty_aliens() == true)
				{
					game_is_won = true;
				}
			}
			if (p->getLives() == 0)
			{
				game_is_lost = true;
			}
			if (game_is_won == true or game_is_lost == true)
			{
				game = false;
				Mix_HaltMusic();
			}
			//tb.drawSprite(gRenderer);

			//th.drawSprite(gRenderer);
			// t.drawSprite(gRenderer);
			// g.drawSprite(gRenderer);
			// f.drawSprite(gRenderer);
			// s.drawSprite(gRenderer);
			drawObj();
			l.setLives(p->getLives());
			l.drawSprite(gRenderer);
			f.drawSprite(gRenderer);
			p->updateFuel(current_time);
			f.setFuel(p->getFuel());
			scoring.setScore(p->getScore());
			scoring.display(font, score_display, gRenderer);
			gS.gameUnload();
		}
		if (game_is_won == true)
		{
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(bgMusicW, -1);
			}
			texture.drawBG(gRenderer);
			SDL_RenderCopy(gRenderer, gwScreen, NULL, NULL);
		}
		if (game_is_lost == true)
		{
			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(bgMusicL, -1);
			}
			texture.drawBG(gRenderer);
			SDL_RenderCopy(gRenderer, glScreen, NULL, NULL);
		}
		if (state == true)
		{
			updateplayer(p);
			updatealien(p);
			updateobstacles(p);
		}

		SDL_RenderPresent(gRenderer); //displays the updated renderer

		SDL_Delay(200); //causes sdl engine to delay for specified miliseconds
	}
}
