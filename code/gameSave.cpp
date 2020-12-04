#include "gameSave.hpp"

using namespace std;

gameSave::gameSave(){}

void gameSave::setVals(bool S, Lives L, Score sc){
    
    gamestate = S;
    lives = L.getLives();
    score = sc.getScore();
    aliens = score/10;
}
void gameSave::saveGame(){

    ofstream file;
    file.open("SaveGame.txt", ios::app);    //appending the attributes in the save file
    file << gamestate << ", " << lives << ", " << score << ", " << aliens << endl;
    file.close();   //file closed 

}

std::string gameSave::getLastLine(ifstream &f){
    while(f >> std::ws && std::getline(f, line));
    return line;
}
istream& getline(istream &input, gameSave g){

}
void gameSave::gameLoad(){
    ifstream file;
    file.open("SaveGame.txt");
    line = getLastLine(file);
    cout << line << endl;
    stringstream x(line);

    getline(x, g, ',');
    getline(x, l, ',');
    getline(x, s, ',');
    getline(x, a, ',');

    gamestate = stoi(g);
    lives = stoi(l);
    score = stoi(s);
    aliens = stoi(a);

    file.close();
    //cout << gamestate << ' ' << lives << ' ' <<  score << ' ' << aliens << endl;
}
//do << operator overloading
//make the save and load functions for the game
