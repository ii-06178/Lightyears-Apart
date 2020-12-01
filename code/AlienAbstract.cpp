//#include "alienTypes.hpp"
#include "alienTypes.hpp"
#include "sprite.hpp"

class Abstract_Alien{//abstract creator for aliens

    protected:

    bool up;//flag for vertical movement
    bool cstate;

    public:

    virtual Sprite* CreateAlien(int) = 0;
};

class Concrete_Alien:public Abstract_Alien, Sprite{//concrete creator for aliens
    public:
    Sprite* CreateAlien(int n) override{
        printf("came in to make the alien\n");
        if (n == 1) return new GeoYielders(asset);
        else if (n == 2) return new ThunderBearers(asset);
        else if (n == 3) return new StormCarriers(asset);
        else if (n == 4) return new FireBreathers(asset);
    }
    void drawSprite(SDL_Renderer* gRenderer) override{
        general_render(mover.x, mover.y, asset, gRenderer, 0.0, turn_h); //renders the alien
        if (cstate == true)
        {
         //movement for x axis
        if (mover.x < 800 - mover.w && turn_h == SDL_FLIP_NONE)
        { //moving towards right wallssswaarrrrra
            mover.x += 20;
        }
        else if (mover.x >= 800 - mover.w)
            turn_h = SDL_FLIP_HORIZONTAL; //turns when hit the right wall
        if (mover.x > 0 && turn_h == SDL_FLIP_HORIZONTAL)
        { //moving towards left wall
            mover.x -= 20;
        }
        else if (mover.x <= 0)
            turn_h = SDL_FLIP_NONE; //turns when hit the left wall

        //movement for y axis
        if (mover.y < 600 - mover.h && up == false)
        { //moving down
            mover.y += 10;
        }
        else if (mover.y >= 600 - mover.h)
            up = true; //strikes bottom

        if (mover.y > 0 && up == true)
        { //moving up
            mover.y -= 10;
        }
        else if (mover.y <= 0)
            up = false; //stikes roof
        }
    }
};