#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <SDL.h>
#include "player_spaceship.hpp"
class gameSave
{
    //string variables to store the input from the file in load game
    std::string line;
    std::string g, l, s, ka, t, ca, f;
 
public:
    bool gamestate;
    int score, lives, k_aliens, c_aliens, time, fuel; //integers for storing score, lives, aliens and time

    gameSave(); //default constructor to build gameSave object
    void setVals(bool, Lives, Score, Uint32, int, int, int);   //set value function for storing the values from the game
    void saveGame();    //save game function to write the variables in the save file
    std::string getLastLine(ifstream&); //function to get the last line of the file, so the last played game can be loaded
    void gameLoad();    //load game function to load the saved game
};