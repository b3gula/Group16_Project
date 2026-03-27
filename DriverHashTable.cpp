#include "DriverHashTable.h"
#include <iostream> 

using namespace std; 

DriverHashTable::DriverHashTable(){
    for (int i=0; i<TABLE_SIZE; i++){
        table[i] = nullptr; 
    }
}

DriverHashTable::~DriverHashTable(){
    for(int i=0; i < TABLE_SIZE; i++){
        while(table[i] != nullptr){
                HashNode* temp = table[i];
                table[i] = table[i]->next; 
                delete temp;
         }
    }
}

int DriverHashTable::hashFunction(int licenseNum) const{
    return licenseNum % TABLE_SIZE;
}

void DriverHashTable::insert(Driver *driver){
    int index = hashFunction(driver->getLicenseNum());

    HashNode *newNode = new HashNode; 
    newNode->driver = driver;
    newNode->next = table[index];
    table[index] = newNode; 
}

Driver *DriverHashTable::search(int ln){
    int index = hashFunction(ln);

    HashNode* current = table[index];
    while (current != nullptr){
        if (current->driver->getLicenseNum() == ln){
            return current->driver; 
        }
        current = current->next; 
    }
    return nullptr;
}

void DriverHashTable::remove(int ln){
    int index = hashFunction(ln);

    if (table[index] == nullptr){
        return;
    }
    
    if(table[index]->driver->getLicenseNum() == ln){
        HashNode *temp = table[index];
        table[index] = table[index]->next; 
        delete temp; 
        return;
    }

    HashNode* current = table[index];
    HashNode* prev = nullptr;
    while(current!= nullptr){
        if(current->driver->getLicenseNum() == ln){
            prev->next = current->next; 
            delete current;
            return;
        }
        prev = current;
        current = current->next; 
    }
    return;
}
