#include "DriverList.h"
using namespace std; 

DriverList::DriverList() {
    head = nullptr; 
}
DriverList::~DriverList() {
    while (head!=nullptr){
        Node* temp = head;
        head = head->next; 
        delete temp;
    }
}

void DriverList::addDriver(Driver* driver){
    if (head == nullptr){
        Node* newNode = new Node; 
        newNode->data =driver; 
        newNode->next = nullptr;
        head = newNode; 
    }
    else{
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next; 
        }
        Node* newNode = new Node; 
        newNode->data = driver; 
        newNode->next = nullptr; 
        
        temp->next = newNode; 
    }
}

void DriverList::removeDriver(int licenseNum){
    if (head == nullptr){
        cout << "Driver list empty" << endl;
        return;
    }
    if(head->data->getLicenseNum() == licenseNum){
        Node *temp = head; 
        head = head->next; 
        delete temp;
        return;
    }
    Node *prev = nullptr; 
    Node *current = head; 
    while(current!=nullptr){
        if(current->data->getLicenseNum() == licenseNum){
            prev->next = current->next; 
            delete current; 
            return;
        }
        prev = current;
        current = current->next;  
    }
}
bool DriverList::isEmpty() const{
    return head == nullptr;
}
void DriverList::insertByCounty(Driver *driver, string c){
    Node *newNode = new Node; 
    newNode->data = driver; 
    newNode->next = nullptr; 

    if (head== nullptr){
        head = newNode; 
        return;
    }

    if(head->data->getCounty() == c){
        Node *temp = head; 
        while (temp->next != nullptr && temp->next->data->getCounty() == c){
            temp = temp->next;
        }
        newNode->next = temp->next; 
        temp->next = newNode; 
        return;
    }

    Node* current = head; 
    while(current->next != nullptr){
        if(current->next->data->getCounty() == c){
            while(current->next != nullptr && current->next->data->getCounty() == c){
                current = current->next; 
            }
            newNode->next = current->next; 
            current->next = newNode; 
            return;
        }
        current = current->next; 
    }

    current->next = newNode; 
}

