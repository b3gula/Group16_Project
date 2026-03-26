#ifndef RECENT_LICENSE_TRACKER_H
#define RECENT_LICENSE_TRACKER_H 

#include "Driver.h"

using namespace std; 

class RecentLicenseTracker{
    public:
        RecentLicenseTracker();
        ~RecentLicenseTracker();
        void addLicense(Driver *driver);
        void displayRecent(int n) const;
    private: 
        struct Node {
            Driver *data; 
            Node *next; 
        };
        Node* head; 

};
#endif