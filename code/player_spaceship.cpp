#include<iostream>
#include "player_spaceship.hpp"
#include <SDL.h>

using namespace std;

PlayerSpaceship::PlayerSpaceship(SDL_Texture* img):Sprite(img) {
    //setting ships position; I am using just first one right, will include the other four colors with conditions once the buttons are set up
    src.x = 10;
    src.y = 0;
    src.w = 90;
    src.h = 120;
 
    mover.x = pos_x;
    mover.y = pos_y;
    mover.w = 70;
    mover.h = 100;

    score = 0;
    lives = 3;
    fuel = 100; //percent
    alive = true;
    //speed of the ship
    x_speed = 0;    y_speed = 0;
    //position of the ship
    pos_x = (800 - mover.w)/2;  pos_y = 600 - mover.h;    //center of screen
}

void PlayerSpaceship::EventHandler(SDL_Event event){
    
    if(event.type == SDL_KEYDOWN && event.key.repeat == 0){//when the key is pressed

        switch (event.key.keysym.sym){
            case SDLK_LEFT: x_speed -= S_VELOCITY; break;  //moves back
            case SDLK_RIGHT: x_speed += S_VELOCITY; break; //moves forward
            case SDLK_UP: y_speed -= S_VELOCITY; break;   //moves down
            case SDLK_DOWN: y_speed += S_VELOCITY; break; //moves up
        }
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0){//to stop the ship when the key is released

        switch (event.key.keysym.sym){
            case SDLK_LEFT: x_speed += S_VELOCITY; break;
            case SDLK_RIGHT: x_speed -= S_VELOCITY; break;
            case SDLK_UP: y_speed += S_VELOCITY; break;
            case SDLK_DOWN: y_speed -= S_VELOCITY; break;
        }
    }
}
void PlayerSpaceship::moveShip(){
    //the ship moves forward/backward until it hits either wall
    //cout<<pos_y<<endl;
    pos_x += x_speed;
    if(pos_x + mover.w > 800 || pos_x < 0){
        pos_x -= x_speed;
    }
    //the ship moves up/down until it hits roof/bottom
    pos_y += y_speed;
    if(pos_y + mover.h > 600 || pos_y < 400){
        pos_y -= y_speed;
    }
}

void PlayerSpaceship::drawSprite(SDL_Renderer* gRenderer){
    //flipping horizontally because the sprite has vertical ship
    general_render(pos_x, pos_y, asset, gRenderer, 0.0,SDL_FLIP_NONE);
}

SDL_Rect PlayerSpaceship::getmover(){
    // return mover;
    SDL_Rect sre ={pos_x,pos_y,mover.w,mover.h};
    return sre;
}


//Lives class Functions

Lives::Lives(SDL_Texture* img):Sprite(img){
    src.x = 390;
    src.y = 0;
    src.w = 92;
    src.h = 140;

    mover.x = 0;
    mover.y = 0;
    mover.w = 46;
    mover.h = 70;
}

void Lives::drawSprite(SDL_Renderer* gRenderer){
    for(int x = 0; x < 3; x++){
        general_render(0,y[x],asset,gRenderer,0.0,SDL_FLIP_NONE);
    }
}

//Laser Functions
// P_Laser::P_Laser(SDL_Texture* img):Laser(img){
//     src[0].x = 200;
//     src[0].y = 290;
//     src[0].w = 30;
//     src[0].h = 105;

//     src[1].x = 0;
//     src[1].y = 290;
//     src[1].w = 30;
//     src[1].h = 105;

//     mover.w = 20;
//     mover.h = 70;
// }
// void P_Laser::shoot(SDL_Renderer* gRenderer){//drawing laser
//     SDL_Rect* currentframe = &src[frame/2];
//     SDL_RenderCopy(gRenderer, asset, currentframe, &mover);
//     SDL_RenderPresent(gRenderer);
//     ++frame;
// }