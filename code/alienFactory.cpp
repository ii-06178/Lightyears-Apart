#include "sprite.hpp"
#include "alien.hpp"
#include "alienTypes.hpp"
#include "alienFactory.hpp"
void alienFactory::emptyVirtual()
{
    
}
Alien* alienFactory::getAlien(std::string alientype,SDL_Texture* img)
    {
        Alien *getAlienoftype;
        if (alientype == "alien1")
        {
            getAlienoftype=new FireBreathers(img);
        }
        else if (alientype == "alien2")
        {
             getAlienoftype=new ThunderBearers(img);
        }
        else if (alientype == "alien3")
        {
            getAlienoftype=new StormCarriers(img);
        }
        else if (alientype == "alien4")
        {
            getAlienoftype=new GeoYielders(img);
        }
        else
        {
            getAlienoftype=NULL;
        }
        return getAlienoftype;
    }