#include "gameSave.hpp"

using namespace std;

gameSave::gameSave(){}

void gameSave::setVals(bool S, Lives L, Score sc){
    
    gamestate = S;
    lives = L.getLives();
    score = sc.getScore();
}
void gameSave::saveGame(){
    ofstream file;
    file.open("SaveGame.txt", ios::app);
    file << gamestate << ", " << lives << ", " << score << endl;
    file.close();
}
//do << operator overloading
//make the save and load functions for the game
