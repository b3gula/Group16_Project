#ifndef DRIVER_H
#define DRIVER_H
#include "Address.h"
#include "Date.h"
#include "Ticket.h"
#include <string>
using namespace std;

enum AgeCatg { YOUTH, MIDDLE_AGED, SENIOR};
enum WorkCatg { STUDENT, GOV_EMPLOYEE, SELF_EMPLOYED, BUSINESS_OWNER, PRIVATE_EMPLOYEE};
enum ExperienceCatg { NEW_DRIVER, MODERATE_DRIVER, HIGHLY_EXPERIENCED};
enum MedicalCond { FIT, VISION_IMPAIRED, UPPER_EXTREMITY_IMPAIRMENT, LOCOMOTOR_DISABILITY};

class Driver {
public:
    void setName(string nameVal);
    void setLicense(string licenseVal);
    void setDOB(Date dobVal);
    void setLicenseDate(Date licDateVal);
    void setAddress(Address addrVal);
    void setTicket(Ticket ticketVal);

    void setAgeCatg(AgeCatg ageVal);
    void setExperienceCatg(ExperienceCatg expVal);
    void setWorkCatg(WorkCatg workVal);
    void setMedicalCond(MedicalCond medVal);

    string getCounty();
    string getLicenseNum();

    void display();

private:
    string name;       
    string license_num;
    Ticket ticket;
    AgeCatg age;
    ExperienceCatg exp;
    WorkCatg work;
    MedicalCond med;

    Address address;

    Date DOB;
    Date licenseDate;
};

string AgeCatgToString(AgeCatg ageVal);
string WorkCatgToString(WorkCatg workVal);
string ExperienceCatgToString(ExperienceCatg expVal);
string MedicalCondToString(MedicalCond medVal);

#endif
