#ifndef DRIVER_H
#define DRIVER_H 

#include "Date.h"
#include "Address.h"
#include "Ticket.h"
#include <string> 
using namespace std; 

class Driver {
    public:
        Driver(int licNum, string name, Date dob, Address add, Date licDate, int exp);
        ~Driver();

        int getLicenseNum() const; 
        string getName() const; 
        Date getDob() const;
        Address getAdd() const; 
        Date getLicenseDate() const; 
        int getExp() const; 
        string getCounty() const;
        int getAge() const; 

        void setAgeCate();
        void setWorkCate(string work);
        void setExpCate();
        void setMedCate(string med);

        void addTicket(Ticket t);
        bool hasTickets() const; 

        void display() const; 
        
    private: 
        int licenseNum;
        string name;
        Date dob;
        Address address; 
        Date licenseDate; 
        int exp;
        string ageCate; 
        string workCate; 
        string expCate; 
        string medCond; 
        Ticket* tickets; 
        int ticketCount;
        int maxTicket; 
};
#endif