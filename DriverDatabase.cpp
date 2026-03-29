#include "DriverDatabase.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 

DriverDatabase::DriverDatabase(){}
DriverDatabase::~DriverDatabase(){}
void DriverDatabase::addDriver(Driver* driver){
    driver->setAgeCate();
    driver->setExpCate();

    hashTable.insert(driver);
    activeDrivers.insertByCounty(driver, driver ->getCounty());
    recentTracker.addLicense(driver);
    oldestTracker.addLicense(driver);
}

Driver* DriverDatabase::search(int ln){
    return hashTable.search(ln);
}
void DriverDatabase::displayRecent(int n){
    recentTracker.displayRecent(n);
}
void DriverDatabase::displayOldest(int n){
    oldestTracker.displayOldest(n);
}
void DriverDatabase::moveToInactive(int ln){
    Driver* driver = search(ln);
    if(driver == nullptr){
        cout << "Driver not found" << endl;
        return; 
    }

    activeDrivers.removeDriver(ln);
    hashTable.remove(ln);
    inactiveDrivers.addDriver(driver);

    cout << "Driver moved to inactive" << endl;
}
void DriverDatabase::loadData(string filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "Cannot open file" << endl;
        return; 
    }

    string line; 
    getline(file, line);


    int count = 0;
    while (getline(file, line)){
        stringstream ss(line);
        string token;
        string tokens[26];
        
        int i =0;
        while (getline(ss, token, ',') && i<26){
            tokens[i++] = token;
        }

        int license = stoi(tokens[0]);
        string name = tokens[1];
        int dobDay = stoi(tokens[2]);
        int dobMonth = stoi(tokens[3]);
        int dobYear = stoi(tokens[4]);
        string street = tokens [5]; 
        string city = tokens[6];
        string county = tokens[7];
        string zip = tokens[8];
        int issueDay = stoi(tokens[9]);
        int issueMonth = stoi(tokens[10]);
        int issueYear = stoi(tokens[11]);
        int yearsExp = stoi(tokens[12]);
        string workType = tokens[13];
        string medicalCond = tokens[14];

        Date dob(dobDay, dobMonth, dobYear);
        Address address(street, city, county, zip);
        Date issueDate(issueDay, issueMonth, issueYear);
        
        Driver *driver = new Driver(license, name, dob, address, issueDate, yearsExp);
        driver->setWorkCate(workType);
        driver->setMedCate(medicalCond);

        int TicketNum = stoi(tokens[15]);
        for(int t =0; t < TicketNum; t++){
            int index = 16 + (t*5); 
            
            if(!tokens[index].empty()){
                int tDay = stoi(tokens[index]);
                int tMonth = stoi(tokens[index+1]);
                int tYear = stoi(tokens[index+2]);
                string Loca = tokens[index+3];
                string violation = tokens[index+4];

                Date ticketDate(tDay, tMonth, tYear);
                Ticket ticket(ticketDate, Loca, violation);
                driver->addTicket(ticket);
            }
        }

        addDriver(driver);
        count++;
    }
    file.close();
    cout << count << " drivers loaded from file." << endl;
}