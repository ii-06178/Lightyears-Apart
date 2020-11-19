#include "sprite.hpp"

Sprite::Sprite(SDL_Texture* img){   //kinda default constructor for all sprites. 

    asset = img;
    src = {0,0,0,0};
    mover = {0,0,0,0};
    hitCount = 0;
    x_speed = 0;
    y_speed = 0;

    if(asset == NULL) printf("Unable to load sprite\n");//To detect the error IF the sprite is not loaded through the constructors.
}

int Sprite::getWidth(){
    return(mover.w);
}
int Sprite::getHeight(){
    return(mover.h);
}

void Sprite::general_render(int x, int y, SDL_Texture* img, SDL_Renderer* gRenderer, double angle){
    SDL_Rect dstrect = {x , y, mover.w, mover.h};
    SDL_RenderCopyEx(gRenderer, img, &src, &dstrect,angle,NULL,SDL_FLIP_NONE);//included the angle because of the ship
}
