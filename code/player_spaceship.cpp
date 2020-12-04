#include <iostream>
#include "player_spaceship.hpp"
#include <sstream>
#include <SDL_ttf.h>
#include <SDL.h>

using namespace std;
PlayerSpaceship *PlayerSpaceship::obj = NULL;
PlayerSpaceship *PlayerSpaceship::getinstance(SDL_Texture *img)
{
    if (obj == NULL)
    {
        obj = new PlayerSpaceship(img);
    }
    return obj;
}

PlayerSpaceship::PlayerSpaceship(SDL_Texture *img) : Sprite(img)
{
    //setting ships position;using just first one right, 
    src.x = 10;
    src.y = 0;
    src.w = 90;
    src.h = 120;

    mover.x = pos_x;
    mover.y = pos_y;
    mover.w = 70;
    mover.h = 100;
    // all these stats will be updated:
    score = 0;//default score 
    lives = 3;//default lives
    fuel = 140;//default fuel
    //speed of the ship
    x_speed = 0;
    y_speed = 0;
    //position of the ship
    pos_x = (800 - mover.w) / 2;
    pos_y = 600 - mover.h; //ship is at center of screen by default.
}
int PlayerSpaceship::operator - (int strength)
{//operator overloaded to subtract player fuel lost upon collision with laser/obstacle, depending on their "strength"
    return fuel - strength; 
}
void PlayerSpaceship::EventHandler(SDL_Event event)
{

    if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    { //when the key is pressed

        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            x_speed -= S_VELOCITY;
            break; //moves left
        case SDLK_RIGHT:
            x_speed += S_VELOCITY;
            break; //moves right
        case SDLK_UP:
            y_speed -= S_VELOCITY;
            break; //moves up
        case SDLK_DOWN:
            y_speed += S_VELOCITY;
            break; //moves down
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    { //to stop the ship when the key is released

        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            x_speed += S_VELOCITY;
            break;
        case SDLK_RIGHT:
            x_speed -= S_VELOCITY;
            break;
        case SDLK_UP:
            y_speed += S_VELOCITY;
            break;
        case SDLK_DOWN:
            y_speed -= S_VELOCITY;
            break;
        }
    }
}
void PlayerSpaceship::moveShip(bool state)
{
    //the ship moves forward/backward until it hits either wall
    if (state == true)//if the game is not paused
    {
        pos_x += x_speed;
        if (pos_x + mover.w > 800 || pos_x < 0)
        {
            pos_x -= x_speed;
        }
        //the ship moves up/down until it hits roof/bottom
        pos_y += y_speed;
        if (pos_y + mover.h > 600 || pos_y < 400)
        {
            pos_y -= y_speed;
        }
    }
}

void PlayerSpaceship::drawSprite(SDL_Renderer *gRenderer)
{
    general_render(pos_x, pos_y, asset, gRenderer, 0.0, SDL_FLIP_NONE);
}

SDL_Rect PlayerSpaceship::getmover()
{// return mover;
    SDL_Rect sre = {pos_x, pos_y, mover.w, mover.h};
    return sre;
}
void PlayerSpaceship::updateFuel(Uint32 ct)
{
    Uint32 t = ct % 5000;

    if (fuel != 0 && t < 200)
    {
        std::cout << t << std::endl;
        fuel = fuel - 5;
    }
}
//get functions
int PlayerSpaceship::getScore()
{
    return score;
}
int PlayerSpaceship::getLives()
{
    return lives;
}
int PlayerSpaceship::getFuel()
{
    return fuel;
}
//set functions
void PlayerSpaceship::setScore(int s)
{
    score = s;
}
void PlayerSpaceship::setLives(int l)
{
    lives = l;
}
void PlayerSpaceship::setFuel(int f)
{
    fuel = f;
}
void PlayerSpaceship::setFuel()
{
    fuel = defaultFuel;
}

//Lives class Functions
Lives::Lives(SDL_Texture *img) : Sprite(img)
{
    src.x = 390;
    src.y = 0;
    src.w = 92;
    src.h = 140;

    mover.x = 0;
    mover.y = 0;
    mover.w = 46;
    mover.h = 70;
}
void Lives::setLives(int l)
{
    life = l;
}
int Lives::getLives()
{
    return life;
}
// overides the default drawSprite
void Lives::drawSprite(SDL_Renderer *gRenderer)
{
    for (int x = 0; x < life; x++)
    {
        general_render(0, y[x], asset, gRenderer, 0.0, SDL_FLIP_NONE);
    }
}

// Score Class Functions
Score::Score()
{
    scored = 0;
}
void Score::setScore(int s)
{
    scored = s;
}
int Score::getScore()
{
    return scored;
}


void Score::display(TTF_Font *f, SDL_Texture *t, SDL_Renderer *renderer)
{//this brings the score in text form.
    stringstream ss;
    ss << scored;
    string s;
    ss >> s;
    string news = "score:" + s; //concatenates the string with the score
    SDL_Color white = {255, 255, 255}; //sets the font color
    SDL_Surface *sc = TTF_RenderText_Solid(f, news.c_str(), white);//generates the text into a surface
    if (sc == NULL)
    {
        printf("Unable to render sc! SDL_ttf Error: %s\n", TTF_GetError());//checks for error
    }
    t = SDL_CreateTextureFromSurface(renderer, sc);//surface is then converted into texture

    SDL_Rect Message_rect;  //create SDL_rect
    Message_rect.x = 650;   // x coordinate
    Message_rect.y = 0;     //  y coordinte
    Message_rect.w = sc->w; // width
    Message_rect.h = sc->h; //height
    SDL_RenderCopy(renderer, t, NULL, &Message_rect);//texture is brought on screen 
    SDL_FreeSurface(sc); //frees the surface
}

//Fuel ClassFunction
Fuel::Fuel(SDL_Texture *img) : Sprite(img)
{
    src.x = 860;
    src.y = 550;
    src.w = 150;
    src.h = 463;

    mover.h = 200;
    mover.w = 100;
    //(x,y) left corner of the screen
    mover.x = 800 - mover.w;
    mover.y = 600 - mover.h;
    rect.h = 140;
    rect.w = 65;
    rect.x = 800 - rect.w - 10;
    rect.y = 600 - rect.h - 10;


}
void Fuel::drawSprite(SDL_Renderer *gRenderer)
{   
// this is used to set the fill color
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//this draws the rectangle behind the gauge to make an animation
    SDL_RenderDrawRect(gRenderer, &rect);
    // this fills the color in the rectangle
    SDL_RenderFillRect(gRenderer, &rect);

    general_render(mover.x, mover.y, asset, gRenderer, 0.0, SDL_FLIP_NONE); //drawing the fuel guage
}

int Fuel::getFuel()
{
    return rect.h;
}
void Fuel::setFuel(int f)
{
    if (rect.h != f)
    {
        rect.y = rect.y + (rect.h - f);
    }

    rect.h = f;
}
