#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <SDL.h>
#include "player_spaceship.hpp"
class gameSave
{
    std::string line;
    std::string g, l, s, a;

protected:
    
public:
    bool gamestate;
    int score;
    int lives;
    int aliens;

    gameSave();
    //gameSave(bool, Lives, Score);
    void setVals(bool, Lives, Score);
    void saveGame();
    std::string getLastLine(ifstream&);
    friend std::istream& getline(std::istream&, gameSave);

    void gameLoad();
    void gameUnload();
    void gameResume();
};