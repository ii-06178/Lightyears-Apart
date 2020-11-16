#include "sprite.hpp"

Sprite::Sprite(SDL_Texture* img){   //kinda default constructor for all sprites. 

    asset = img;
    src = {0,0,0,0};
    mover = {0,0,0,0};
    hitCount = 0;
    speed = 0;

    if(asset == NULL) printf("Unable to load sprite\n");//To detect the error IF the sprite is not loaded through the constructors.
}

int Sprite::getWidth(){
    return(mover.w);
}
int Sprite::getHeight(){
    return(mover.h);
}
