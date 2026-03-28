#include "Driver.h"
#include <iostream>
#include <string>
using namespace std; 

Driver::Driver (int licNum, string name, Date dob, Address add, Date licDate, int exp)
: licenseNum(licNum), name(name), dob(dob), address(add), licenseDate(licDate), exp(exp)
{
    ageCate = "";
    workCate = "";
    expCate = "";
    medCond = "";

    maxTicket = 10;
    tickets = new Ticket[maxTicket];
    ticketCount =0;
}

Driver::~Driver(){
    delete[] tickets;
}

int Driver::getLicenseNum() const{
    return licenseNum;
}
string Driver::getName() const{
    return name;
}
Date Driver::getDob() const{
    return dob;
}
Address Driver::getAdd() const{
    return address; 
}
Date Driver::getLicenseDate() const{
    return licenseDate;
}
int Driver::getExp() const{
    return exp;
}
string Driver::getCounty() const{
    return address.getCounty();
}
int Driver::getAge() const{
    return dob.getAge();
}

void Driver::setAgeCate() {
    int age = dob.getAge(); 

    if (age >= 16 && age <= 28){
        ageCate = "Youth";
    }
    else if (age <= 50){
        ageCate = "Middle-aged";
    }
    else {
        ageCate = "Senior";
    }
}
void Driver::setExpCate(){
    if (exp <= 5){
        expCate = "New drivers";
    }
    else if (exp <= 15){
        expCate = "Moderately experienced drivers";
    }
    else {
        expCate = "Highly experienced drivers";
    }
}
void Driver::setWorkCate(string work){
    workCate = work;
}
void Driver::setMedCate(string med){
    medCond = med; 
}

void Driver::addTicket(Ticket t){
    if (ticketCount < maxTicket){
        tickets[ticketCount] = t; 
        ticketCount++;
    }
}

bool Driver::hasTickets() const{
    return ticketCount > 0;
}

void Driver::display() const{
    cout << "License number: " << licenseNum << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << dob.getAge() << " (" << ageCate << ")" << endl;
    cout << "Work type: " << workCate << endl;
    cout << "Experience: " << exp << " (" << expCate << ")" << endl;
    cout << "Address: ";
    cout << endl;
    address.display();
    cout << endl;
    cout << "License issue Date: ";
    licenseDate.display();
    cout << endl;
     
    cout << "Ticket count: " << ticketCount << endl;

    if (ticketCount > 0){
        for (int i=0; i<ticketCount; i++){
            cout << "Ticket: " << i+1 << ":" << endl;
            tickets[i].display();
            cout << endl;
        }
    }
}