#include "Laser.hpp"

Laser::Laser(SDL_Texture* img){
    asset = img;
}
int Laser::frame = 0;