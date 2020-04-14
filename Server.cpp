#include "HashEntry.h"
#include "HashTable.h"
#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>

Server::Server(){
    this->idNum = 0;
    this->name = "";
    this->address = "";
}
//overloaded constructor for reading from file
Server::Server(int idNum, string name, string address){
    this->idNum = idNum;
    this->name = name;
    this->address = address;
}
Server::~Server(){
}

//ACCESSORS
int Server::getIDNum(){
    return this -> idNum;
}
string Server::getName(){
    return this -> name;
}
string Server::getAddress(){
    return this -> address;
}
   
//MUTATORS
void Server::changeIDNum(int newNum){
    this->idNum = newNum;
}
void Server::changeName(string newName){
    this->name = newName;
}
void Server::changeAddress(string newAddress){
    this->address = newAddress;
}
