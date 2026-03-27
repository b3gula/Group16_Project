#include "DriverLinkedList.h"
#include <iostream>

DriverLinkedList::DriverLinkedList() {
    head = nullptr;
    size = 0;
}

void DriverLinkedList::InsertFront(DriverNode* drivernodeVal) {
    drivernodeVal->next = head; // direct access
    head = drivernodeVal;
    size++;
}

void DriverLinkedList::InsertBack(DriverNode* drivernodeVal) {
    if (!head) {
        head = drivernodeVal;
    } else {
        DriverNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = drivernodeVal;
    }
    size++;
}

void DriverLinkedList::InsertAfter(string county, DriverNode* drivernodeVal) {
    DriverNode* temp = head;
    while (temp != nullptr) {
        if (temp->data.getCounty() == county) {
            drivernodeVal->next = temp->next;
            temp->next = drivernodeVal;
            size++;
            return;
        }
        temp = temp->next;
    }
    InsertBack(drivernodeVal);
}

DriverNode* DriverLinkedList::Search(string license_idVal) {
    DriverNode* temp = head;
    while (temp != nullptr) {
        if (temp->data.getLicenseID() == license_idVal) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}