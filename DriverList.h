#ifndef DRIVER_LIST_H
#define DRIVER_LIST_H
#include "Driver.h"
using namespace std; 

class DriverList{
    public:
        DriverList();
        ~DriverList(); 
        void addDriver(Driver* driver); 
        void removeDriver(int licenseNum);
        void insertByCounty(Driver* driver, string c);
        void display() const; 
        bool isEmpty() const; 

    private:
        struct Node {
            Driver* data;
            Node* next; 
        };
        Node* head; 
};
#endif