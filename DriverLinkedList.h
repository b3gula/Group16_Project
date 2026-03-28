#ifndef DRIVER_LL_H
#define DRIVER_LL_H
#include "Driver.h"
#include <string>
using namespace std;

class DriverNode{
    public:
        DriverNode *next;
        Driver data;

        DriverNode(){
            next = nullptr;
        }

        DriverNode(Driver *driverVal){
            data = *driverVal;
            next = nullptr;
        }
};

class DriverLinkedList{
    private:
        DriverNode *head;
        int size;

    public:
        DriverLinkedList();
        ~DriverLinkedList();
        void InsertFront(DriverNode *drivernodeVal);
        void InsertBack(DriverNode *drivernodeVal);
        void InsertAfter(string county, DriverNode *drivernodeVal);
        void Remove(string license_numVal);
        bool empty();
};

#endif