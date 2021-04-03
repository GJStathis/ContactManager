#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

void switchThroughMenuCommand(int appVal);
void applicationStartMenu();

struct Friend {
    string firstName;
    string lastName;
    string birthday;
    string number; 
};

string removeSpaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int getInputInt(){
    int userInput;
    cin >> userInput;
    while(1){
        if(cin.fail()){
            cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter an int: ";
	    cin >> userInput;
        }

	if(!cin.fail()){
	    break;
	}
    }
    return userInput;
}

string returnDefaultValue(string str){
     if(str.size() > 0)
     {
	return str;
     } else
     {
	string defStr = "None";
	return defStr;
     }
}

void addFriend(){
    ofstream ofs;
    Friend newFriend;
    
    string temp;    
 
    cin.ignore(); 
    cout << "Enter first name of new friend: ";
    getline(cin, temp);
    newFriend.firstName = returnDefaultValue(temp);
    cout << "Enter last name of new friend: ";
    getline(cin, temp); 
    newFriend.lastName = returnDefaultValue(temp);
    cout << "Enter the birthday of your new friend: ";
    getline(cin, temp); 
    newFriend.birthday = returnDefaultValue(temp);
    cout << "Enter the phone number of your new friend: ";
    getline(cin, temp); 
    newFriend.number = returnDefaultValue(temp);
    
    ofs.open("./friendList.csv", ofstream::out | ofstream::app);
    ofs << newFriend.firstName << "," << newFriend.lastName << "," << newFriend.birthday << "," << newFriend.number << "\n"; 
    ofs.close();

    applicationStartMenu();  
}

void listFriends(){
    fstream fin;
    fin.open("./friendList.csv", ios::in);
    
    string line, temp, word;
    cout << "\nFirst name\tLast name\tBirthday\t\tPhone number\n";
    while(getline(fin, line))
    {
	stringstream s(line);
	while(getline(s, word, ','))
	{
	    cout << word << "\t\t";
	} 
	cout << "\n";
    }
    
    fin.close();
    applicationStartMenu();
}

void switchThroughMenuCommand(int appVal){
    switch(appVal){
         case 0:
             cout << "Thank you for using the app" << endl;
             return;
         case 1:
	     addFriend();
             break;
         case 2:
	     listFriends();
             break;
         case 3:
	     cout << "This is where the edit method goes" << endl;
	     break;
         case 4:
             cout << "This is where the delte method goes" << endl;
             break;
         default:
             cout << "This command is not know returning to start screen" << endl;
             applicationStartMenu();
    }
	
} 

void applicationStartMenu(){
    int userInput;

    cout << "\nMain Menu \n";
    cout << "[1] Add a new friend contact \n";
    cout << "[2] List out friend contacts \n";
    cout << "[3] Edit friend contact \n";
    cout << "[4] Delete friend contact \n\n";
    cout << "[0] Exit app" << endl;
    
    cout << "Select an option: ";
    userInput = getInputInt();   

    switchThroughMenuCommand(userInput);
}

int main(){
    cout << "Welcome to the friend contacts manager" << endl;
    cout << "--------------------------------------------" << endl;
    applicationStartMenu();
    return 0;
}
