#include "Driver.h"
#include <iostream>
using namespace std;

void Driver::setName(string nameVal){
    name = nameVal;
}

void Driver::setLicense(string licenseVal){
    license_num = licenseVal;
}

void Driver::setDOB(Date dobVal){
    DOB = dobVal;
}

void Driver::setLicenseDate(Date licDateVal){
    licenseDate = licDateVal;
}

void Driver::setAddress(Address addrVal){
    address = addrVal;
}

void Driver::setTicket(Ticket ticketVal){
    ticket = ticketVal;
}

void Driver::setAgeCatg(AgeCatg ageVal){
    age = ageVal;
}

void Driver::setExperienceCatg(ExperienceCatg expVal){
    exp = expVal;
}

void Driver::setWorkCatg(WorkCatg workVal){
    work = workVal;
}

void Driver::setMedicalCond(MedicalCond medVal){
    med = medVal;
}

string Driver::getCounty(){
    return address.getCounty();
}

string Driver::getLicenseNum(){
    return license_num;
}

void Driver::display(){
    cout << "Name: " << name << "\n";
    cout << "License #: " << license_num << "\n";
    cout << "DOB: ";
    DOB.display();
    cout << "License Date: ";
    licenseDate.display();
    cout << "Address: ";
    address.display();
    cout << "\n";
    cout << "Ticket Info:\n";
    ticket.display();
    cout << "Age Category: " << AgeCatgToString(age) << "\n";
    cout << "Experience: " << ExperienceCatgToString(exp) << "\n";
    cout << "Work: " << WorkCatgToString(work) << "\n";
    cout << "Medical: " << MedicalCondToString(med) << "\n";
}

string AgeCatgToString(AgeCatg a){
    switch(a){
        case YOUTH: return "Youth";
        case MIDDLE_AGED: return "Middle-aged";
        case SENIOR: return "Senior";
        default: return "Unknown";
   }
}

string WorkCatgToString(WorkCatg w){
    switch(w){
        case STUDENT: return "Student";
        case GOV_EMPLOYEE: return "Government employee";
        case SELF_EMPLOYED: return "Self-employed";
        case BUSINESS_OWNER: return "Business owner";
        case PRIVATE_EMPLOYEE: return "Private sector employee";
        default: return "Unknown";
   }
}

string ExperienceCatgToString(ExperienceCatg e){
    switch(e){
        case NEW_DRIVER: return "New driver";
        case MODERATE_DRIVER: return "Moderately experienced";
        case HIGHLY_EXPERIENCED: return "Highly experienced";
        default: return "Unknown";
   }
}

string MedicalCondToString(MedicalCond m){
    switch(m){
        case FIT: return "Fit";
        case VISION_IMPAIRED: return "Vision impaired";
        case UPPER_EXTREMITY_IMPAIRMENT: return "Upper extremity impairment";
        case LOCOMOTOR_DISABILITY: return "Locomotor disability";
        default: return "Unknown";
   }
}
