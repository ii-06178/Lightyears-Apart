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

void deleteobstacle();
void deletealien(SDL_Texture*);
void drawAllaliens(SDL_Renderer*,SDL_Texture*);
void drawAllobstacles(SDL_Renderer*);
void drawAlllasers(SDL_Renderer*);
// void laying(SDL_Texture*);
void check_collision_with_shooter();
void check_collision_with_aliens();
void check_collisions_with_obstacles();
// void makeNestMove();
//~LinkedList();
};