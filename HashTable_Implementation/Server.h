#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <string>

using namespace std;

class Server{
private:
    int idNum;
    string name;
    string address;
    
public:
    //CONSTRUCTOR AND DESTRUCTOR
    Server();
    //overloaded constructor for reading from file
    Server(int, string, string);
    ~Server();
    
    //ACCESSORS
    int getIDNum();
    string getName();
    string getAddress();
    
    //MUTATORS
    void changeIDNum(int);
    void changeName(string);
    void changeAddress(string);
    
    //OVERLOADED OPERATOR
    //allows user to use the << operator to output all info for a Server Object
    friend ostream& operator<<(ostream& osObj, Server& curServ){
        osObj << "--->ID: " << curServ.idNum;
        osObj << ", NAME: " << curServ.name;
        osObj << ", ADDRESS: " << curServ.address;
        return osObj;
    }
    
};

#endif
