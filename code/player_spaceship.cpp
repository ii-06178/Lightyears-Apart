#include "player_spaceship.hpp"
#include <SDL.h>
using namespace std;

PlayerSpaceship::PlayerSpaceship()
{
    score = 0;
    life = 3;
    fuel = 100; //percent
}

PlayerSpaceship::~PlayerSpaceship()
{

}
void PlayerSpaceship::updateScore(int s)
{
    score = score + s;
}
void PlayerSpaceship::updateLives(int l)
{
    lives = lives + l; //need -ve l to decrease lives
}
void PlayerSpaceship::updateFuel(int f)
{
    fuel = fuel + f;
}
int PlayerSpaceship::getScore()
{
    return score;
}
int PlayerSpaceship::getLives()
{
    return lives;
}
int PlayerSpaceship::getFuel()
{
    return fuel;
}

void PlayerSpaceship::shoot()
{
    
}

