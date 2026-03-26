#ifndef DRIVER_DATABASE_H
#define DRIVER_DATABASE_H

#include "Driver.h"
#include "DriverList.h"
#include "DriverHashTable.h"
#include "RecentLicenseTracker.h"
#include "OldestLicenseTracker.h"

#include <iostream>
#include <string> 
using namespace std;

class DriverDatabase{
    public:
        DriverDatabase();
        ~DriverDatabase();
        void addDriver(Driver* driver);
        Driver* search(int ln);
        void displayRecent(int n);
        void displayOldest(int n);
        void moveToInactive(int ln);
        void loadData(string filename);


    private: 
        DriverList activeDrivers;
        DriverList inactiveDrivers; 
        RecentLicenseTracker recentTracker; 
        OldestLicenseTracker oldestTracker; 
        DriverHashTable hashTable;
};
#endif