#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <list>
#include "sprite.hpp"
#include "alien.hpp"
#include "player_spaceship.hpp"
#include "alienTypes.hpp"
#include "Laser.hpp"
#include "obstacle.hpp"
#include "obstacleTypes.hpp"
#include "linkedlist.hpp"

LinkedList::LinkedList()
{
}
void LinkedList::addUnit(Meteor *m) //adds pigeon to pigeon lst
{
    meteors.push_front(m);
}
void LinkedList::addUnit(Fireball *f) //adds nest to nest lst
{
    fireballs.push_front(f);
}
void LinkedList::addUnit(Laser *l, std::string type) //adds pigeon to pigeon lst
{
    if (type == "hero")
    {
        herolasers.push_front(l);
    }
    if (type == "alien")
    {
        alienlasers.push_front(l);
    }
}
void LinkedList::addUnit(Thunderbolt *t) //adds nest to nest lst
{
    thunderbolts.push_front(t);
}
void LinkedList::addUnit(GeoYielders *g) //adds pigeon to pigeon lst
{
    geoalien.push_front(g);
}
void LinkedList::addUnit(ThunderBearers *ea) //adds nest to nest lst
{
    electroalien.push_front(ea);
}
void LinkedList::addUnit(StormCarriers *aa) //adds pigeon to pigeon lst
{
    anemoalien.push_front(aa);
}
void LinkedList::addUnit(FireBreathers *pa) //adds nest to nest lst
{
    pyroalien.push_front(pa);
}
void LinkedList::drawAllaliens(SDL_Renderer *renderer, SDL_Texture *asst, bool s)
{ //This function from the Drawallobjects from the game file
    std::list<GeoYielders *>::iterator itr;

    int i;
    for (i = 0, itr = geoalien.begin(); i < geoalien.size() && itr != geoalien.end(); i++, itr++)
        if (geoalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
            int prob;
            prob = rand() % 100;
            if (prob <= 2)
            {
                Laser *alaser = new Laser(asst);
                SDL_Rect mof = a->getmover();
                //std::cout<<"what we are passing"<<mo.x<<","<<mo.y<<std::endl;
                alaser->setPos(mof);
                alaser->setType("alien");
                addUnit(alaser, "alien");
            }
        }
    std::list<ThunderBearers *>::iterator jtr;

    int j;
    for (j = 0, jtr = electroalien.begin(); j < electroalien.size() && jtr != electroalien.end(); j++, jtr++)
        if (electroalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
            int prob;
            prob = rand() % 100;
            if (prob <= 2)
            {
                Laser *alaser = new Laser(asst);
                SDL_Rect mof = a->getmover();
                //std::cout<<"what we are passing"<<mo.x<<","<<mo.y<<std::endl;
                alaser->setPos(mof);
                alaser->setType("alien");
                addUnit(alaser, "alien");
            }
        }
    std::list<StormCarriers *>::iterator ktr;

    int k;
    for (k = 0, ktr = anemoalien.begin(); k < anemoalien.size() && ktr != anemoalien.end(); k++, ktr++)
        if (anemoalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ktr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
            int prob;
            prob = rand() % 100;
            if (prob <= 2)
            {
                Laser *alaser = new Laser(asst);
                SDL_Rect mof = a->getmover();
                //std::cout<<"what we are passing"<<mo.x<<","<<mo.y<<std::endl;
                alaser->setPos(mof);
                alaser->setType("alien");
                addUnit(alaser, "alien");
            }
        }
    std::list<FireBreathers *>::iterator ltr;

    int l;
    for (l = 0, ltr = pyroalien.begin(); l < pyroalien.size() && ltr != pyroalien.end(); l++, ltr++)
        if (pyroalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ltr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
            int prob;
            prob = rand() % 100;
            if (prob <= 2)
            {
                Laser *alaser = new Laser(asst);
                SDL_Rect mof = a->getmover();
                //std::cout<<"what we are passing"<<mo.x<<","<<mo.y<<std::endl;
                alaser->setPos(mof);
                alaser->setType("alien");
                addUnit(alaser, "alien");
            }
        }
}
void LinkedList::drawAllobstacles(SDL_Renderer *renderer, bool s)
{ //This function from the Drawallobjects from the game file
    std::list<Meteor *>::iterator itr;

    int i;
    for (i = 0, itr = meteors.begin(); i < meteors.size() && itr != meteors.end(); i++, itr++)
        if (meteors.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
        }
    std::list<Thunderbolt *>::iterator jtr;

    int j;
    for (j = 0, jtr = thunderbolts.begin(); j < thunderbolts.size() && jtr != thunderbolts.end(); j++, jtr++)
        if (thunderbolts.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
        }
    std::list<Fireball *>::iterator ktr;

    int k;
    for (k = 0, ktr = fireballs.begin(); k < fireballs.size() && ktr != fireballs.end(); k++, ktr++)
        if (fireballs.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ktr;
            a->setstate(s);
            a->drawSprite(renderer); //calls the object's draw function
        }
}
void LinkedList::drawAlllasers(SDL_Renderer *renderer, bool s)
{ //This function from the Drawallobjects from the game file
    std::list<Laser *>::iterator itr;

    int i;
    for (i = 0, itr = herolasers.begin(); i < herolasers.size() && itr != herolasers.end(); i++, itr++)

        if (herolasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            a->setcstate(s);
            a->drawSprite(renderer); //calls the object's draw function
        }
    std::list<Laser *>::iterator jtr;

    int j;
    for (j = 0, jtr = alienlasers.begin(); j < alienlasers.size() && jtr != alienlasers.end(); j++, jtr++)
        if (alienlasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            a->setcstate(s);
            a->drawSprite(renderer); //calls the object's draw function
        }
}

void LinkedList::deletealien(SDL_Texture *, PlayerSpaceship *pl)
{
    std::list<GeoYielders *>::iterator itr;

    int i;
    for (i = 0, itr = geoalien.begin(); i < geoalien.size() && itr != geoalien.end(); i++, itr++)
        if (geoalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            if (a->getdestroyed() == true)
            {
                std::cout << "points " << a->getPoints() << std::endl;
                int scoreinc = pl->getScore() + a->getPoints();
                pl->setScore(scoreinc);
                geoalien.erase(itr);
            }
            //calls the object's draw function
        }
    std::list<ThunderBearers *>::iterator jtr;

    int j;
    for (j = 0, jtr = electroalien.begin(); j < electroalien.size() && jtr != electroalien.end(); j++, jtr++)
        if (electroalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            if (a->getdestroyed() == true)
            {   std::cout << "points " << a->getPoints() << std::endl;
                int scoreinc = pl->getScore() + a->getPoints();
                pl->setScore(scoreinc);
                electroalien.erase(jtr);
            }
        }
    std::list<StormCarriers *>::iterator ktr;

    int k;
    for (k = 0, ktr = anemoalien.begin(); k < anemoalien.size() && ktr != anemoalien.end(); k++, ktr++)
        if (anemoalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ktr;

            if (a->getdestroyed() == true)
            {   std::cout << "points " << a->getPoints() << std::endl;
                int scoreinc = pl->getScore() + a->getPoints();
                pl->setScore(scoreinc);
                anemoalien.erase(ktr);
            }
        }
    std::list<FireBreathers *>::iterator ltr;

    int l;
    for (l = 0, ltr = pyroalien.begin(); l < pyroalien.size() && ltr != pyroalien.end(); l++, ltr++)
        if (pyroalien.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ltr;

            if (a->getdestroyed() == true)
            {   std::cout << "points " << a->getPoints() << std::endl;
                int scoreinc = pl->getScore() + a->getPoints();
                pl->setScore(scoreinc);
                pyroalien.erase(ltr);
            }
        }
}
void LinkedList::deleteobstacle(SDL_Texture *)
{
    std::list<Meteor *>::iterator itr;

    int i;
    for (i = 0, itr = meteors.begin(); i < meteors.size() && itr != meteors.end(); i++, itr++)
        if (meteors.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;

            if (a->getdestroyed() == true || a->getcontact() == true)
            {
                meteors.erase(itr);
            }
        }
    std::list<Thunderbolt *>::iterator jtr;

    int j;
    for (j = 0, jtr = thunderbolts.begin(); j < thunderbolts.size() && jtr != thunderbolts.end(); j++, jtr++)
        if (thunderbolts.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;

            if (a->getdestroyed() == true || a->getcontact() == true)
            {
                thunderbolts.erase(jtr);
            }
        }
    std::list<Fireball *>::iterator ktr;

    int k;
    for (k = 0, ktr = fireballs.begin(); k < fireballs.size() && ktr != fireballs.end(); k++, ktr++)
        if (fireballs.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ktr;

            if (a->getdestroyed() == true || a->getcontact() == true)
            {
                fireballs.erase(ktr);
            }
        }
}
void LinkedList::deletelaser(SDL_Texture *)
{
    std::list<Laser *>::iterator itr;

    int i;
    for (i = 0, itr = herolasers.begin(); i < herolasers.size() && itr != herolasers.end(); i++, itr++)

        if (herolasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            if (a->getcontact() == true)
            {
                herolasers.erase(itr);
            }
            //calls the object's draw function
        }
    std::list<Laser *>::iterator jtr;

    int j;
    for (j = 0, jtr = alienlasers.begin(); j < alienlasers.size() && jtr != alienlasers.end(); j++, jtr++)
        if (alienlasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            if (a->getcontact() == true)
            {
                herolasers.erase(jtr);
            }
            //calls the object's draw function
        }
}
void LinkedList::check_collision_with_shooter(PlayerSpaceship *pl)
{
    std::list<Laser *>::iterator itr;

    int i;
    for (i = 0, itr = herolasers.begin(); i < herolasers.size() && itr != herolasers.end(); i++, itr++)

        if (herolasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            std::list<FireBreathers *>::iterator ltr;

            int l;
            for (l = 0, ltr = pyroalien.begin(); l < pyroalien.size() && ltr != pyroalien.end(); l++, ltr++)
                if (pyroalien.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *ltr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                    //calls the object's draw function
                }
            std::list<ThunderBearers *>::iterator jtr;

            int j;
            for (j = 0, jtr = electroalien.begin(); j < electroalien.size() && jtr != electroalien.end(); j++, jtr++)
                if (electroalien.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *jtr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                }
            std::list<StormCarriers *>::iterator ktr;

            int k;
            for (k = 0, ktr = anemoalien.begin(); k < anemoalien.size() && ktr != anemoalien.end(); k++, ktr++)
                if (anemoalien.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *ktr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                }
            std::list<GeoYielders *>::iterator mtr;

            int m;
            for (m = 0, mtr = geoalien.begin(); m < geoalien.size() && mtr != geoalien.end(); m++, mtr++)
                if (geoalien.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *mtr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                    //calls the object's draw function
                }
        }
}
void LinkedList::check_collisions_with_obstacles()
{
    std::list<Laser *>::iterator itr;

    int i;
    for (i = 0, itr = herolasers.begin(); i < herolasers.size() && itr != herolasers.end(); i++, itr++)

        if (herolasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            auto a = *itr;
            std::list<Thunderbolt *>::iterator jtr;

            int j;
            for (j = 0, jtr = thunderbolts.begin(); j < thunderbolts.size() && jtr != thunderbolts.end(); j++, jtr++)
                if (thunderbolts.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *jtr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                    //calls the object's draw function
                }
            std::list<Fireball *>::iterator ktr;

            int k;
            for (k = 0, ktr = fireballs.begin(); k < fireballs.size() && ktr != fireballs.end(); k++, ktr++)
                if (fireballs.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *ktr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }

                    //calls the object's draw function
                }
            std::list<Meteor *>::iterator ltr;

            int l;
            for (l = 0, ltr = meteors.begin(); l < meteors.size() && ltr != meteors.end(); l++, ltr++)
                if (meteors.size() == 0)
                {
                    // list too short
                    // std::cout<<0;
                }
                else
                {
                    // 'ptr' points to N-th element of list
                    auto b = *ltr;
                    SDL_Rect ma = a->getmover();
                    SDL_Rect mb = b->getmover();
                    if (SDL_HasIntersection(&ma, &mb) == true)
                    {
                        b->hasdestroyed();
                        a->setcontact();
                    }
                }
        }
}
void LinkedList::check_collision_with_enemyshooter(PlayerSpaceship *pl, Mix_Chunk *mc)
{
    std::list<Laser *>::iterator itr;

    int i;
    for (i = 0, itr = alienlasers.begin(); i < alienlasers.size() && itr != alienlasers.end(); i++, itr++)

        if (alienlasers.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;

            SDL_Rect ma = a->getmover();
            SDL_Rect mb = pl->getmover();
            if (SDL_HasIntersection(&ma, &mb) == true)
            {
                Mix_PlayChannel(0, mc, 0);
                a->setcontact();
                pl->setFuel(0);
                if (pl->getFuel()==0)
                {   int clife=pl->getLives()-1;
                    pl->setLives(clife);
                }
            }
            //calls the object's draw function
        }
}
bool LinkedList::check_empty_aliens()
{
    if (pyroalien.empty() == true)
    {
        if (anemoalien.empty() == true)
        {
            if (geoalien.empty() == true)
            {
                if (electroalien.empty() == true)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// void LinkedList::check_collision_with_aliens()
// {

void LinkedList::check_hit_with_obstacle(PlayerSpaceship *pl, Mix_Chunk *mc)
{
    std::list<Meteor *>::iterator itr;

    int i;
    for (i = 0, itr = meteors.begin(); i < meteors.size() && itr != meteors.end(); i++, itr++)
        if (meteors.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *itr;
            SDL_Rect ma = a->getmover();
            SDL_Rect mb = pl->getmover();
            if (SDL_HasIntersection(&ma, &mb) == true)
            {
                a->setcontact();
                Mix_PlayChannel(0, mc, 0);
            }
        }
    std::list<Thunderbolt *>::iterator jtr;

    int j;
    for (j = 0, jtr = thunderbolts.begin(); j < thunderbolts.size() && jtr != thunderbolts.end(); j++, jtr++)
        if (thunderbolts.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *jtr;
            SDL_Rect ma = a->getmover();
            SDL_Rect mb = pl->getmover();
            if (SDL_HasIntersection(&ma, &mb) == true)
            {
                a->setcontact();
                Mix_PlayChannel(0, mc, 0);
            }
            //calls the object's draw function
        }
    std::list<Fireball *>::iterator ktr;

    int k;
    for (k = 0, ktr = fireballs.begin(); k < fireballs.size() && ktr != fireballs.end(); k++, ktr++)
        if (fireballs.size() == 0)
        {
            // list too short
            // std::cout<<0;
        }
        else
        {
            // 'ptr' points to N-th element of list
            auto a = *ktr;
            SDL_Rect ma = a->getmover();
            SDL_Rect mb = pl->getmover();
            if (SDL_HasIntersection(&ma, &mb) == true)
            {
                a->setcontact();
                Mix_PlayChannel(0, mc, 0);
            }
            //calls the object's draw function
        }
}