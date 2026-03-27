#include "DriverDatabase.h"
#include <iostream>
using namespace std; 

void displayMenu(){
    cout << "Driver Database System" << endl;
    cout << "1. Load data from file" << endl;
    cout << "2. Add new driver" << endl;
    cout << "3. Search driver" << endl;
    cout << "4. Move driver to inactive" << endl;
    cout << "5. Display recent driver" << endl;
    cout << "6. Display oldest driver" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter choice: "; 
}

int main(){
    DriverDatabase database; 
    int choice; 
    
    do {
        displayMenu();
        cin >> choice; 
        switch (choice){
            case 1:{
                cin.ignore();
                string filename; 
                cout << "Enter file name (with .txt or .csv, etc.): ";
                cin >> filename; 
                database.loadData(filename);
                break;
            }
            case 2:{
                cin.ignore();
                string name; 
                cout << "Driver's name: ";
                getline(cin, name);

                int licenseNum;
                cout << "License number: ";
                cin >> licenseNum;

                int dobDay, dobMonth, dobYear;
                cout << "Date Of Birth (day month year): ";
                cin >> dobDay >> dobMonth >> dobYear;
                
                string street, city, county, zip;
                cout << "Enter street: ";
                cin.ignore();
                getline(cin, street);

                cout << "Enter city: ";
                getline(cin, city);
                
                cout << "Enter county: ";
                getline(cin, county);

                cout << "Enter zipcode: ";
                getline(cin, zip);

                int issueDay, issueMonth, issueYear;
                cout << "Day of issue (day month year): ";
                cin >> issueDay >> issueMonth >> issueYear;

                int exp; 
                cout << "Years of experience: ";
                cin >> exp;

                string work, med;
                int c, m;
                cout << "Choose work type: " << endl;
                cout << "1. Student" << endl;
                cout << "2. Government employee" << endl;
                cout << "3. Self-employed" << endl;
                cout << "4. Business owner" << endl;
                cout << "5. Private sector employee" << endl;
                cout << "Enter choice (1-5): ";
                cin >> c; 
                if (c == 1){
                    work = "Student";
                }
                else if(c==2){
                    work = "Government employee";
                }
                else if(c==3){
                    work = "Self-employed";
                }
                else if(c==4){
                    work = "Business owner";
                }
                else if (c==5){
                    work = "Private sector employee";
                }

                cout << "Choose medical condition: " << endl;
                cout << "1. Fit" << endl;
                cout << "2. Vision impaired" << endl;
                cout << "3. Upper extremity impairment" << endl;
                cout << "4. Locomotor disability" << endl;
                cout << "Enter choice (1-4): ";
                cin >> m;
                if (m == 1){
                    med = "Fit";
                }
                else if(m==2){
                    med = "Vision impaired";
                }
                else if(m==3){
                    med = "Upper extremity impairment";
                }
                else if(m==4){
                   med = "Locomotor disability";
                }

                Date dob(dobDay, dobMonth, dobYear);
                Date issueDate(issueDay, issueMonth, issueYear);
                Address address(street, city, county, zip);

                Driver *driver = new Driver(licenseNum, name, dob, address, issueDate, exp);
                driver->setWorkCate(work);
                driver->setMedCate(med);

                database.addDriver(driver);
                break;
            }
            case 3:{
                int licenseNum;
                cout << "Enter license number to search: ";
                cin >> licenseNum; 

                Driver* driver = database.search(licenseNum);
                if (driver != nullptr){
                    driver->display();
                } 
                else{
                    cout << "Driver not found!" << endl;
                }
                break;
            }
            case 4: {
                int licenseNum;
                cout << "Enter license number to remove from active list: ";
                cin >> licenseNum; 

                database.moveToInactive(licenseNum);
                break;
            }
            case 5:{
                int n;
                cout << "Enter number of driver to display: ";
                cin >> n;

                database.displayRecent(n);
                break; 
            }
            case 6:{
                int n;
                cout << "Enter number of driver to display: ";
                cin >> n;

                database.displayOldest(n);
                break; 
            }
            case 7:{
                cout << "Exiting program!" << endl;
                break;
            }
            default:
                cout << "Invalid choice, only accept 1-7" << endl;
                break;
        }
    }while (choice!=7);
}