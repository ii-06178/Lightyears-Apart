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
void LinkedList::addUnit(Alien* a)
{
        allaliens.push_front(a);
}
void LinkedList::addUnit(Obstacle* o)
{
        allobstacles.push_front(o);
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
 std::list<Alien *>::iterator itr;
 int i;
    for (i = 0, itr = allaliens.begin(); i < allaliens.size() && itr != allaliens.end(); i++, itr++)
        if (allaliens.size() == 0)
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
                std::cout << a->getStrength() << std::endl;
                alaser->setstrength(a->getStrength());
                addUnit(alaser, "alien");
            }
        }
}

void LinkedList::drawAllobstacles(SDL_Renderer *renderer, bool s)
{ //This function from the Drawallobjects from the game file
    std::list<Obstacle *>::iterator itr;
    int i;
    for (i = 0, itr = allobstacles.begin(); i < allobstacles.size() && itr != allobstacles.end(); i++, itr++)
        if (allobstacles.size() == 0)
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
{ std::list<Alien *>::iterator itr;
int i;
    for (i = 0, itr = allaliens.begin(); i < allaliens.size() && itr != allaliens.end(); i++, itr++)
        if (allaliens.size() == 0)
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
                allaliens.erase(itr);
            }
            //calls the object's draw function
        }
}

void LinkedList::deleteobstacle(SDL_Texture *)
{
    std::list<Obstacle *>::iterator itr;
    int i;
    for (i = 0, itr = allobstacles.begin(); i < allobstacles.size() && itr != allobstacles.end(); i++, itr++)
        if (allobstacles.size() == 0)
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
                allobstacles.erase(itr);
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
            std::list<Alien *>::iterator ltr;

            int l;
            for (l = 0, ltr = allaliens.begin(); l < allaliens.size() && ltr != allaliens.end(); l++, ltr++)
                if (allaliens.size() == 0)
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
        }
}

void LinkedList::check_collisions_with_obstacles(PlayerSpaceship *pl)
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
            std::list<Obstacle *>::iterator jtr;

            int j;
            for (j = 0, jtr = allobstacles.begin(); j < allobstacles.size() && jtr != allobstacles.end(); j++, jtr++)
                if (allobstacles.size() == 0)
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
            std::cout << "im here" << std::endl;
            SDL_Rect ma = a->getmover();
            SDL_Rect mb = pl->getmover();
            if (SDL_HasIntersection(&ma, &mb) == true)
            {
                Mix_PlayChannel(0, mc, 0);
                a->setcontact();
                int fueLeft = *pl - a->getstrength();
                pl->setFuel(fueLeft);
                if (pl->getFuel() <= 0)
                {
                    int clife = pl->getLives() - 1;
                    pl->setLives(clife);
                    pl->setFuel();
                }
            }
            //calls the object's draw function
        }
}
bool LinkedList::check_empty_aliens()
{ if (allaliens.empty()==true)
{
    return true;
}
return false;
}

void LinkedList::check_hit_with_obstacle(PlayerSpaceship *pl, Mix_Chunk *mc)
{   
    std::list<Obstacle *>::iterator itr;
    int i;
    for (i = 0, itr = allobstacles.begin(); i < allobstacles.size() && itr != allobstacles.end(); i++, itr++)
        if (allobstacles.size() == 0)
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
                int fueLeft = *pl - a->getStrength();
                pl->setFuel(fueLeft);
                if (pl->getFuel() <= 0)
                {
                    int clife = pl->getLives() - 1;
                    pl->setLives(clife);
                    pl->setFuel();
                }
                a->setcontact();
                Mix_PlayChannel(0, mc, 0);
            }
        }
}