#include "RecentLicenseTracker.h"
#include <iostream>
using namespace std; 

RecentLicenseTracker::RecentLicenseTracker(){
    head = nullptr;
}
RecentLicenseTracker::~RecentLicenseTracker(){
    while(head!=nullptr){
        Node *temp  = head; 
        head = head->next; 
        delete temp;
    }
}
void RecentLicenseTracker::addLicense(Driver *driver){
    Node *newNode = new Node; 
    newNode->data = driver; 
    newNode->next = nullptr;

    if (head == nullptr){
        head = newNode; 
        return;
    }

    if(head->data->getLicenseDate() < driver->getLicenseDate()){
        newNode->next = head; 
        head = newNode;
        return;
    }

    Node *temp = head; 
    while(temp->next != nullptr && driver->getLicenseDate() < temp->next->data->getLicenseDate()){
        temp = temp->next; 
    }

    newNode->next = temp->next; 
    temp->next = newNode;
    
}

void RecentLicenseTracker::displayRecent(int n) const{
    if (head == nullptr){
        cout << "List is empty" << endl;
        return; 
    }

    int count = 0;
    Node *temp = head;
    while (temp != nullptr && count < n){
        temp->data->display();
        temp = temp->next;
        count+=1;
    }
}