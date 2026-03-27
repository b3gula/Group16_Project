#ifndef OLDEST_LICENSE_TRACKER_H
#define OLDEST_LICENSE_TRACKER_H

#include "Driver.h"
using namespace std; 

class OldestLicenseTracker{
    public:
        OldestLicenseTracker();
        ~OldestLicenseTracker();
        void addLicense(Driver *driver);
        void displayOldest(int n) const;
    private:
        struct Node{
            Driver *data; 
            Node *next;
        };
        Node* head; 
};
#endif