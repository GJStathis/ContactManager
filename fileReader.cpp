#include <string>
#include <fstream>
#include "fileReader.h"
#include <iostream>
#include <sstream>

manager::FileManager::FileManager(void){
    std::ifstream ifile;
    ifile.open("./friendList.csv");
    if (ifile)
    {
	std::string line, temp, word;
	while(getline(ifile, line))
	{
	    Friend bufFriend;
	    std::stringstream s(line);
	    std::vector<std::string> buffer;
	    while(getline(s, word, ','))
	    {
	        buffer.push_back(word);	
	    }
	    
	    bufFriend.firstName = buffer[0];
	    bufFriend.lastName = buffer[1];
        bufFriend.birthday = buffer[2];
	    bufFriend.number = buffer[3];
		
	    fileMemory.push_back(bufFriend);
	}
	ifile.close();
	std::cout << "File read into memory" << std::endl;
    }
}

void listFriends(){
    for(int i = 0; i < manager::fileMemory.size(); i++){
	std::cout << manager::fileMemory[i].firstName << "\n";
    }
}

void addFriend(std::string firstName, std::string lastName, std::string birthday, std::string number)
{
    Friend friend;
    friend.firstName = firstName;
    friend.lastName = lastName;
    friend.birthday = birthday;
    friend.number = number;

    fileMemory.push_back(friend);
}
