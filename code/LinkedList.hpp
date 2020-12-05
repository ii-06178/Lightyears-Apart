#pragma once

//built in headers
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <list>

//Our game headers
#include "sprite.hpp"
#include "alien.hpp"
#include "player_spaceship.hpp"
#include "Laser.hpp"
#include "obstacle.hpp"

class LinkedList
{
    //Creating lists for Aliens, Obstacles and lasers
    std::list<Laser *> herolasers{};
    std::list<Laser *> alienlasers{};
    std::list<Alien *> allaliens{}; 
    std::list<Obstacle* > allobstacles{};

    //int variables to store the aliens killed by the ship
    int killedaliens;

public:
    LinkedList();   //default constructor

    //overloaded addUnit function for adding objects in the list
    void addUnit(Laser *l, std::string type);
    void addUnit(Alien* a);
    void addUnit(Obstacle* o);

    //delete functions for the objects
    void deleteobstacle(SDL_Texture *);
    void deletelaser(SDL_Texture *);
    void deletealien(SDL_Texture *, PlayerSpaceship *);
    void deleteAllLists();

    //draw functions for the objects
    void drawAllaliens(SDL_Renderer *, SDL_Texture *, bool s);
    void drawAllobstacles(SDL_Renderer *, bool s);
    void drawAlllasers(SDL_Renderer *, bool s);

    //functions for checking collisions
    void check_collision_with_shooter(PlayerSpaceship *);
    void check_collision_with_enemyshooter(PlayerSpaceship *pl, Mix_Chunk *);
    void check_collision_with_aliens();
    void check_collisions_with_obstacles(PlayerSpaceship *pl);

    bool check_empty_aliens();  //checking if the alien list is empty
    void check_hit_with_obstacle(PlayerSpaceship *pl, Mix_Chunk *); //checking if the obstacles are hit with laser

    //get and set for the killed aliens
    int getkilledaliens();
    void setkilledaliens(int);
};