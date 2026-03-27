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
    license_date = licDateVal;
}

void Driver::setAddress(Address addrVal){
    address = addrVal;
}

void Driver::setTicket(Ticket ticketVal){
    ticket = ticketVal;
}

void Driver::setAgeCatg(AgeCatg ageVal){
    age_catg = ageVal;
}

void Driver::setExperienceCatg(ExperienceCatg expVal){
    experience_catg = expVal;
}

void Driver::setWorkCatg(WorkCatg workVal){
    work_catg = workVal;
}

void Driver::setMedicalCond(MedicalCond medVal){
    medical_cond = medVal;
}

void Driver::display(){
    cout << "Name: " << name << "\n";
    cout << "License #: " << license_num << "\n";
    cout << "DOB: " << DOB.Day << "/" << DOB.Month << "/" << DOB.Year << "\n";
    cout << "License Date: " << license_date.Day << "/" << license_date.Month << "/" << license_date.Year << "\n";

    cout << "Address: " << address.Street_address << ", "
         << address.City << ", "
         << address.State << ", "
         << address.County << " "
         << address.Zip_code << "\n";

    cout << "Ticket Date: " << ticket.Ticket_date.Day << "/"
         << ticket.Ticket_date.Month << "/"
         << ticket.Ticket_date.Year << "\n";

    cout << "Age Category: " << AgeCatgToString(age_catg) << "\n";
    cout << "Experience: " << ExperienceCatgToString(experience_catg) << "\n";
    cout << "Work: " << WorkCatgToString(work_catg) << "\n";
    cout << "Medical: " << MedicalCondToString(medical_cond) << "\n";
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