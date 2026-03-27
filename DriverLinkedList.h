#ifndef DRIVER_LL_H
#define DRIVER_LL_H
#include "Driver.h"
#include <string>
using namespace std;

class DriverNode{
    private:
        DriverNode *next;
        DriverNode *prev;
        Driver data;

    public:
        DriverNode(){
            next = nullptr;
            prev = nullptr;
        }
        DriverNode(Driver driverVal){
            data = driverVal;
            next = nullptr;
            prev = nullptr;
        }
};

class DriverLinkedList{
    private:
        DriverNode *head;
        int size = 0;
    public:
        DriverLinkedList();
        void InsertFront(DriverNode* drivernodeVal);
        void InsertBack(DriverNode* drivernodeVal);
        void InsertAfter(string county, DriverNode* drivernodeVal);
        void addDriver(Driver* driverVal);
        DriverNode* Search(string license_idVal);
};

#endif