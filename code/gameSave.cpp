#include <fstream>
#include <iostream>
#include "gameSave.hpp"
using namespace std;
gameSave::gameSave()
{
}
void gameSave::gameLoad()
{
    string l;
    ifstream savingfile("saveFile.txt"); //accessing the file Drivers.txt
    if (savingfile.is_open())
    {
        while (!savingfile.eof()) //while the file does not end,
        {
        }
        savingfile.clear();
        savingfile.close();
    }
}
void gameSave::gameUnload()
{
    fstream savedFile("saveFile.txt", ios::out);

    savedFile.close();
}