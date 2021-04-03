#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

struct Friend {
    string firstName;
    string lastName;
    string birthday;
    string number; 
};

namespace manager
{
    class FileManager {
        public:	
            FileManager()
        private:
	    vector<Friend> fileMemory;
    }
}

#endif
