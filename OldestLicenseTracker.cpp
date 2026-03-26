#include "OldestLicenseTracker.h"
#include <iostream>
using namespace std; 

OldestLicenseTracker::OldestLicenseTracker(){
    head = nullptr; 
}
OldestLicenseTracker::~OldestLicenseTracker(){
    while(head != nullptr){
        Node *temp  =head; 
        head = head->next; 
        delete temp; 
    }
}

void OldestLicenseTracker::addLicense(Driver *driver){
    Node *newNode = new Node; 
    newNode->data = driver; 
    newNode->next = nullptr; 

    if(head == nullptr){
        head = newNode; 
        return; 
    }

    if (driver->getLicenseDate() < head->data->getLicenseDate()){
        newNode->next = head;
        head = newNode; 
        return; 
    }

    Node *temp = head; 
    while (temp->next != nullptr && temp->next->data->getLicenseDate() < driver->getLicenseDate()){
        temp = temp->next; 
    }
    newNode->next = temp->next; 
    temp->next = newNode; 
}

void OldestLicenseTracker::displayOldest(int n) const{
    if (head == nullptr){
        cout << "List is empty." << endl;
        return; 
    }

    int count = 0;
    Node *temp = head; 
    while (temp!=nullptr && count < n){
        temp->data->display();
        temp=temp->next; 
        count+=1;
    }
}