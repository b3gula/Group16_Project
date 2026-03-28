#ifndef DATE_H
#define DATE_H
#include <iostream> 
using namespace std; 

class Date {
    public:
        Date();
        Date (int d, int m, int y);
        
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        int getAge() const;
        bool operator<(const Date& other) const; 
        
        void display() const;
        
        
        private: 
        int day;
        int month; 
        int year;
};
#endif