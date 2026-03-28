#include "DriverLinkedList.h"
#include <iostream>
using namespace std;

DriverLinkedList::DriverLinkedList(){
    head = nullptr;
    size = 0;
}

DriverLinkedList::~DriverLinkedList(){
    DriverNode* traverse = head;
    while(traverse){
        DriverNode* next = traverse->next;
        delete traverse;
        traverse = next;
    }
    head = nullptr;
    size = 0;
}

void DriverLinkedList::InsertFront(DriverNode *drivernodeVal){
    drivernodeVal->next = head;
    head = drivernodeVal;
    size++;
}

void DriverLinkedList::InsertBack(DriverNode *drivernodeVal){
    if(head == nullptr){
        head = drivernodeVal;
    }
    else{
        DriverNode *temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = drivernodeVal;
    }
    size++;
}

void DriverLinkedList::InsertAfter(string county, DriverNode *drivernodeVal){
    if(head == nullptr){
        head = drivernodeVal;
    }
    DriverNode *traverse = head;
    while(traverse!=nullptr){
        if(traverse->data.getCounty() == county){
            drivernodeVal->next = traverse->next;
            traverse->next = drivernodeVal;
            size++;
            return;
        }
        traverse = traverse->next;
    }
    InsertBack(drivernodeVal);
}

void DriverLinkedList::Remove(string license_numVal){
    if (head == nullptr){
        return;
    }

    if(head->data.getLicenseNum() == license_numVal){
        DriverNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }
    
    DriverNode* traverse = head;
    while(traverse->next != nullptr){
        if(traverse->next->data.getLicenseNum() == license_numVal){
            DriverNode* temp = traverse->next;
            traverse->next = temp->next;
            delete temp;
            size--;
            return;
        }
        traverse = traverse->next;
    }
}



bool DriverLinkedList::empty(){
    return head == nullptr;
}
