#ifndef DRIVER_HASH_TABLE_H
#define DRIVER_HASH_TABLE_H

#include "Driver.h"

class DriverHashTable{
    public:
        DriverHashTable();
        ~DriverHashTable();
        void insert(Driver *driver);
        Driver *search(int ln);
        void remove(int ln);
    private:
        static const int TABLE_SIZE = 101;
        struct HashNode{
            Driver *driver;
            HashNode* next;
        };
        HashNode *table[TABLE_SIZE];
        int hashFunction(int licenseNum) const; 
};
#endif