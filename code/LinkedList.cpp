#include "linkedlist.hpp"

LinkedList::LinkedList(){}//default constructor

//add unit overloaded thrice for aliens, obstacles and lasers

void LinkedList::addUnit(Alien* a)  //adding aliens in the aliens' list
{
        allaliens.push_front(a);
}
void LinkedList::addUnit(Obstacle* o) //adding obstacles in the obstacle list
{
        allobstacles.push_front(o);
}
void LinkedList::addUnit(Laser *l, std::string type)
{
    if (type == "hero") //adding into hero laser's list if the laser is shot by the ship
    {
        herolasers.push_front(l);
    }
    if (type == "alien") //adding into alien laser's list if the laser is shot by the aliens
    {
        alienlasers.push_front(l);
    }
}

//draw Functions for the objects; to be used in drawallobjects function
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
            if (prob <= 2)  //drawing lasers with the probability of 2%
            {
                Laser *alaser = new Laser(asst);
                SDL_Rect mof = a->getmover();   //getting position of the alien shooting the laser

                alaser->setPos(mof);
                alaser->setType("alien");
                alaser->setstrength(a->getStrength());

                addUnit(alaser, "alien");   //adding in the alien laser list
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

//delete functions for the objects
void LinkedList::deletealien(SDL_Texture *, PlayerSpaceship *pl)
{ 
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
            if (a->getdestroyed() == true)  //checking if the alien is destroyd
            {
                int scoreinc = pl->getScore() + a->getPoints();
                pl->setScore(scoreinc);
                allaliens.erase(itr);
            }
            else if(a->getmover().y >= 600){    //removing if the aliens moves out of the screen on y axis
                allaliens.erase(itr);
            }
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

            if (a->getdestroyed() == true || a->getcontact() == true)   //checking if the obstacle has been destroyed
            {
                allobstacles.erase(itr);
            }
            else if (a->getmover().y >= 600){   //removing the obstacle when it goes out of the screen
                allobstacles.erase(itr);
            }
        }
}

void LinkedList::deletelaser(SDL_Texture *){

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
            if (a->getcontact() == true)    //removing laser if it collides with any object
            {
                herolasers.erase(itr);
            }
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
                alienlasers.erase(jtr);
            }
        }
}

//functions for checking collisions
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