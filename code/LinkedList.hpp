#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <list>
#include "sprite.hpp"
#include "alien.hpp"
#include "player_spaceship.hpp"
#include "Laser.hpp"
#include "obstacle.hpp"

class LinkedList
{
    std::list<Laser *> herolasers{};
    std::list<Laser *> alienlasers{};
    std::list<Alien *> allaliens{}; 
    std::list<Obstacle* > allobstacles{};

public:
    LinkedList();
    void addUnit(Laser *l, std::string type);
    void addUnit(Alien* a);
    void addUnit(Obstacle* o);

    void deleteobstacle(SDL_Texture *);
    void deletelaser(SDL_Texture *);
    void deletealien(SDL_Texture *, PlayerSpaceship *);
    void drawAllaliens(SDL_Renderer *, SDL_Texture *, bool s);
    void drawAllobstacles(SDL_Renderer *, bool s);
    void drawAlllasers(SDL_Renderer *, bool s);
    void check_collision_with_shooter(PlayerSpaceship *);
    void check_collision_with_enemyshooter(PlayerSpaceship *pl, Mix_Chunk *);
    void check_collision_with_aliens();
    void check_collisions_with_obstacles(PlayerSpaceship *pl);
    bool check_empty_aliens();
    void check_hit_with_obstacle(PlayerSpaceship *pl, Mix_Chunk *);
};