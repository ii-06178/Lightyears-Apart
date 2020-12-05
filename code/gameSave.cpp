#include "gameSave.hpp"

using namespace std;

gameSave::gameSave(){}  //default constructor

void gameSave::setVals(bool S, Lives L, Score sc, Uint32 T, int CA, int KA){
    //setting values from the running game to store in the save file
    gamestate = S;
    lives = L.getLives();
    score = sc.getScore();
    c_aliens = CA;  //alien count
    k_aliens = KA;  //killed aliens count
    time = T;
}
void gameSave::saveGame(){
    //saving game
    ofstream file;
    file.open("SaveGame.txt", ios::app);    //appending the attributes in the save file
    file << gamestate << ", " << lives << ", " << score << ", " << c_aliens << ", " << k_aliens << ", " << time << endl;
    file.close();   //file closed 

}

std::string gameSave::getLastLine(ifstream &f){
    while(f >> std::ws && std::getline(f, line));   //getting the last line
    return line;
}

void gameSave::gameLoad(){
    ifstream file;
    file.open("SaveGame.txt");
    line = getLastLine(file);   //getting the last line
    stringstream x(line);   //using string stream to break the string

    //setting the read values in the class variables
    getline(x, g, ',');
    getline(x, l, ',');
    getline(x, s, ',');
    getline(x, ca, ',');
    getline(x, ka, ',');
    getline(x, t, ',');

    //converting and storing the string values in int variables for the game
    gamestate = stoi(g);
    lives = stoi(l);
    score = stoi(s);
    c_aliens = stoi(ca);
    k_aliens = stoi(ka);
    time = stoi(t);
    if (time > 0) time = -time;

    file.close();   //close file
}
