#pragma once
#include <iostream>
class LinkedList
{ 
std::list<Laser*> herolasers {};
std::list<Laser*> alienlasers {};
std::list<Meteor*> meteors {};
std::list<Fireball*> fireballs {};
std::list<Thunderbolt*> thunderbolts{};
std::list<GeoYielders*> geoalien {};
std::list<ThunderBearers*> electroalien {};
std::list<StormCarriers*> anemoalien {};
std::list<FireBreathers*> pyroalien {};
public:
LinkedList();
void addUnit(Laser *l,std::string type);
void addUnit(Meteor *m);
void addUnit(Fireball *f);
void addUnit(Thunderbolt *t);
void addUnit(GeoYielders *ga);
void addUnit(ThunderBearers *ea);
void addUnit(StormCarriers *aa);
void addUnit(FireBreathers *pa);

void deleteobstacle(SDL_Texture*);
void deletelaser(SDL_Texture*);
void deletealien(SDL_Texture*);
void drawAllaliens(SDL_Renderer*,SDL_Texture*,bool s);
void drawAllobstacles(SDL_Renderer*,bool s);
void drawAlllasers(SDL_Renderer*,bool s);
// void laying(SDL_Texture*);
void check_collision_with_shooter();
void check_collision_with_enemyshooter(PlayerSpaceship* pl);
void check_collision_with_aliens();
void check_collisions_with_obstacles();
bool check_empty_aliens();
// void makeNestMove();
//~LinkedList();
};