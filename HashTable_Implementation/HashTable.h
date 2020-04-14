#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "HashEntry.h"

//HashTable template class definition
template <typename T>
class HashTable {
private:
    int size;
    HashEntry<T>* hashArray[10];
    
public:
    //CONSTRUCTOR AND DESTRUCTOR
    HashTable(int size){
        this->size = size;
    }
    ~HashTable(){
        delete[] hashArray;
    }
    
    //ACCESSORS
    //prints all values in the hash table
    void printHashTable(){
        cout << "~~~~~~~~~~";
        for(int i = 0; i < 10; i++){
            if(hashArray[i] == NULL){
                cout << endl;
                cout << "BUCKET " << i << " NULL";
            }
            else{
                HashEntry<T>* currentHash;
                Server* currServ;
                cout << endl;
                cout << "BUCKET " << i << " ";
                currentHash = hashArray[i];
                while(currentHash->getNext() != NULL){
                    cout << *currentHash->getValue();
                    currentHash = currentHash->getNext();
                }
                cout << *currentHash->getValue();
            }
        }
        cout << endl;
        cout << "~~~~~~~~~~" << endl;
        //delete currentHash;
    }
    
    //returns value of an object stored in hash table
    T getValue(int currKey){
        int bucket = currKey % size;
        HashEntry<T>* currentHash = new HashEntry<T>(currKey);
        currentHash = hashArray[bucket];
        
        if(currentHash->getKey() == currKey){
            return currentHash->getValue();
        }
        else{
            while(currentHash->getKey() != currKey && currentHash != NULL){
                currentHash = currentHash->getNext();
            }
            if(currentHash != NULL){
                return currentHash->getValue();
            }
            else{
                return NULL;
            }
        }
        delete currentHash;
    }
    
    //MUTATORS
    //adds value into hash table
    void putValue(int currKey, T currValue){
        int bucket = currKey % size;
        HashEntry<T>* currentHash = new HashEntry<T>(currKey, currValue);
        HashEntry<T>* tempHash = new HashEntry<T>;
        tempHash = hashArray[bucket];
        
        if(hashArray[bucket] == NULL){
            hashArray[bucket] = currentHash;
        }
        else{
            while(tempHash->getNext() != NULL){
                tempHash = tempHash->getNext();
            }
            if(tempHash->getKey() == currKey){
                tempHash->setValue(currValue);
            }
            else{
                tempHash->setNext(new HashEntry<T>(currKey, currValue));
            }
        }
    }
    
    //removes value from hash table
    void removeValue(int currKey){
        int bucket = currKey % size;
        //HashEntry<T>* currentHash = new HashEntry<T>(currKey);
        HashEntry<T>* currentHash;
        HashEntry<T>* prevHash;
        HashEntry<T>* nextHash;
        currentHash = hashArray[bucket];
        
        if(currentHash->getKey() == currKey){
            nextHash = currentHash->getNext();
            delete currentHash;
            hashArray[bucket] = nextHash;
        }
        else{
            while(currentHash->getKey() != currKey && currentHash->getNext() != NULL){
                prevHash = currentHash;
                currentHash = currentHash->getNext();
            }
            if(currentHash == NULL){
                cout << "That server could not be found." << endl;
            }
            else{
                nextHash = currentHash->getNext();
                delete currentHash;
                prevHash->setNext(nextHash);
            }
        }
    }
};

#endif
