#include "sprite.hpp"

Sprite::Sprite(SDL_Texture* img){   //kinda default constructor for all sprites. 

    asset = img;
    //src = {0,0,0,0};
    //mover = {0,0,0,0};
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

void Sprite::general_render(int x, int y, SDL_Texture* img, SDL_Renderer* gRenderer, double angle, SDL_RendererFlip turn){
    SDL_Rect dstrect = {x , y, mover.w, mover.h};
    SDL_RenderCopyEx(gRenderer, img, &src, &dstrect,angle,NULL,turn);//included the angle because of the ship
    SDL_RenderPresent(gRenderer);
}
// SDL_Rect Sprite::spriteSource()
// {//returns the source for next frame needed for animation
//     // SDL_Rect s[3] = {{0,0,160,133}, {0,133,160,133}, {0,266,160,133}};
//     // SDL_Rect temp;
// //     temp = s[frame];

// //    if (frame == 2)
// //    {
// //        frame = 0;
// //    }
// //    else
// //    {
// //        frame++;
// //    }
//     // return s;
// }

// SDL_Rect Sprite::moveSprite()
// {//returns a position for the sprite to be displayed at
//     // SDL_Rect m = {x, y, 50, 50};
//     // return m;
// }
