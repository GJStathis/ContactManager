#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <vector>

struct Friend {
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string number; 
};


namespace manager
{
    class FileManager {
	std::vector<Friend> fileMemory;
        public:	
            FileManager(void);
	    void listFriends();
    };
}

#endif
