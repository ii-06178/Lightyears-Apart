#include "alienFactory.hpp"

void alienFactory::emptyVirtual() {}

Alien* alienFactory::getAlien(std::string alientype,SDL_Texture* img)
    {
        Alien *getAlienoftype;
        if (alientype == "alien1")  //Flag for Firebreathers
        {
            getAlienoftype=new FireBreathers(img);
        }
        else if (alientype == "alien2") //Flag for ThunderBearers
        {
             getAlienoftype=new ThunderBearers(img);
        }
        else if (alientype == "alien3") //Flag for StormCarriers
        {
            getAlienoftype=new StormCarriers(img);
        }
        else if (alientype == "alien4") //Flag for GeoYielders
        {
            getAlienoftype=new GeoYielders(img);
        }
        else    //When the flag is other than the given options
        {
            getAlienoftype=NULL;
        }
        return getAlienoftype;
    }