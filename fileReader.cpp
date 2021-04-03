#include <string>
#include <fstream>
#include "fileReader.h"

FileManager::FileManager(){
    ifstream ifile;
    ifile.open("./friendList.csv")
    if (ifile)
    {
	cout << "File exists so we are going to read it in" << endl;
    } else
    {
	fileMemory = [];
    }

}
