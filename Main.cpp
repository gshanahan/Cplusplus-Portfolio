/*
 FileName(s): Main.cpp, Server.cpp, Server.h, HashTable.h, HashEntry.h
 Author: Gabe Shanahan
 Date: April 13, 2020
 Purpose: Implementing Hash Tables and Chaining. Allows user to create a database of "Servers", in this case.
          A Server includes its Key(idNum, Name(name), and IP Address(address).
 
                                                    
                                                ~~~~~~~!!!ATTENTION!!!~~~~~~~~
 This program's DATAFILE.TXT was made on MACOS. This may cause issues on a Windows PC. If there are issues the DATAFILE.TXT file should be copied into a NEW .TXT file on the Windows machine and tried again.
 
 */

#include "HashEntry.h"
#include "HashTable.h"
#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>

void readFile(HashTable<Server*>*);
void manualEntry(HashTable<Server*>*);
void searchHash(HashTable<Server*>*);
void deleteHash(HashTable<Server*>*);

int main(){
    int loopConf = -1;
    ifstream inputStream;
    
    //dynamically creates a new hash table object with an array size of 10
    HashTable<Server*> *myTable = new HashTable<Server*>(10);
    
    //controls main menu, displays menu options to user and allows user input
    //validates user input
    do{
        cout << "\n\n~~SERVER MANAGEMENT SYSTEM (SMS)~~" << endl;
        cout << endl;
        cout << "1. Add servers from file." << endl;
        cout << "2. Add server manually." << endl;
        cout << "3. Search system for a server." << endl;
        cout << "4. Remove a server from the system." << endl;
        cout << "5. Print system Hash Table." << endl;
        cout << "6. Close system." << endl;
        cout << "CHOOSE 1-6: ";
        cin >> loopConf;
        
        if(loopConf == 1){
            readFile(myTable);
        }
        else if(loopConf == 2){
            manualEntry(myTable);
        }
        else if(loopConf == 3){
            searchHash(myTable);
        }
        else if(loopConf == 4){
            deleteHash(myTable);
        }
        else if(loopConf == 5){
            myTable->printHashTable();
        }
        else if(loopConf == 6){
            
        }
        else{
            cout << "Invalid Entry. Please try again: ";
            cin >> loopConf;
        }
    }
    while(loopConf != 6);
    
    
    return 0;
}

//allows user to input objects into the hash table from a file of their choice
void readFile(HashTable<Server*> *myTable){
    ifstream inputStream;
    string fileName;
    int idNum;
    string name, address;
    
    cout << "What is the name of the file you would like to import from? (Ex: file.txt): ";
    cin.ignore();
    getline(cin, fileName);
    
    inputStream.open(fileName);
    if(inputStream.is_open()){
        while(inputStream){
            inputStream >> idNum;
            inputStream.ignore();
            getline(inputStream, name);
            getline(inputStream, address);
            
            //dynamically create Server object
            Server* newServer = new Server(idNum, name, address);
            
            //add Server object to the HashTable
            myTable->putValue(idNum, newServer);
        }
    }
    else{
        cout << "ERROR: " << fileName << " could not be opened." << endl;
    }
    inputStream.close();
    
}

//allows user to create an object and insert the object into the hash table
void manualEntry(HashTable<Server*> *myTable){
    char input = 'y';
    int idNum;
    string name, address;
    
    while(input == 'y' || input =='Y'){
        cout << "Please enter the following server information." << endl;
        cout << "ID Number: ";
        cin >> idNum;
        cin.ignore();
        cout << "Name:      ";
        getline(cin, name);
        cout << "Address:   ";
        getline(cin, address);
        cout << endl;
        
        //adding data to hash table
        Server* newServer = new Server(idNum, name, address);
        
        //add Server object to the HashTable
        myTable->putValue(idNum, newServer);

        cout << "Would you like to add another server? (y/n): ";
        cin >> input;
    }
}

//allows user to search the hash table for a specific object using a hash key(idNum)
void searchHash(HashTable<Server*> *myTable){
    int idNum;
    Server* newServer = new Server;
    
    cout << "Enter the server ID Number: ";
    cin >> idNum;
    newServer = myTable->getValue(idNum);
    if(newServer == NULL){
        cout << "That server does not exist." << endl;
    }
    else{
        cout << "Server Found:" << endl;
        cout << *newServer;
    }
    delete newServer;
}

//allows user to delete an object from the hash table
void deleteHash(HashTable<Server*> *myTable){
    int idNum;
    char input;
    
    cout << "Enter the server ID Number: ";
    cin >> idNum;
    cout << "Are you sure you wish to delete server #" << idNum << "? (y/n): ";
    cin >> input;
    if(input == 'y' || input == 'Y'){
        myTable->removeValue(idNum);
        cout << "Server #" << idNum << " was deleted." << endl;
    }
    else{
        cout << "Deletion cancelled. Returning to menu." << endl;
    }
}
