#include "player_spaceship.hpp"
#include <SDL.h>
using namespace std;

PlayerSpaceship::PlayerSpaceship(SDL_Texture* img):Sprite(img) {
    //setting ships position
    src.x = 10;
    src.y = 0;
    src.w = 160;
    src.h = 150;

    mover.x = 0;
    mover.y = (600 - src.h)/2;  //center of screen
    mover.w = 100;
    mover.h = 110;

    score = 0;
    lives = 3;
    fuel = 100; //percent
}
void PlayerSpaceship::drawSprite(SDL_Renderer* gRenderer){
    SDL_RenderCopyEx(gRenderer, asset, &src, &mover, 90.0,NULL,SDL_FLIP_NONE);  //flipping horizontally because the sprite has vertical ship
}

