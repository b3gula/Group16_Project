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
        DriverNode *tail;
        int size = 0;
        int capacity = 100;
    public:
        DriverLinkedList();
        void InsertFront(DriverNode *drivernodeVal);
        void InsertBack(DriverNode *drivernodeVal);
        void InsertAfter(string criteria, DriverNode *drivernodeVal);
        DriverNode* Search(string license_idVal);
};

#endif