#ifndef HASHENTRY_H
#define HASHENTRY_H
#include "Server.h"

//HashEntry template class definition
template <typename T>
class HashEntry {
private:
    int key;
    T value;
    HashEntry* next;
    
public:
    HashEntry(int key, T value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    HashEntry(int key){
        this->key = key;
        this->value = NULL;
        this->next = NULL;
    }
    HashEntry(){
        this->key = -1;
        this->value = NULL;
        this->next = NULL;
    }
    
    //ACCESSORS
    int getKey(){
        return this->key;
    }
    T getValue(){
        return this->value;
    }
    HashEntry* getNext(){
        return this->next;
    }
    
    //MUTATORS
    void setKey(int key){
        this->key = key;
    }
    void setNext(HashEntry* next){
        this->next = next;
    }
    void setValue(T value){
        this->value = value;
    }
    
};

#endif
