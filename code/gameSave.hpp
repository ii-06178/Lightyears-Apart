#include <fstream>
#include <iostream>
#include <SDL.h>
#include "player_spaceship.hpp"
class gameSave
{
    bool gamestate;
    int score;
    int lives;
    
    public:
    gameSave();
    //gameSave(bool, Lives, Score);
    void setVals(bool, Lives, Score);
    void saveGame();

    void gameLoad();
    void gameUnload();
    void gameResume();
};