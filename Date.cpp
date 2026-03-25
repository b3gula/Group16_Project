#include "Date.h"
#include <iostream>
using namespace std; 

Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const{
    return day;
}
int Date::getMonth() const{
    return month;
}
int Date::getYear() const{
    return year;
}

int Date::getAge() const{
    return 2026 - year;
}

bool Date::operator<(const Date& other) const{
    if (year != other.year){
        return year < other.year;
    }
    else if (month != other.month){
        return month < other.month;
    }
    else
        return day < other.day;
}

void Date::display() const{
    cout << day << "/" << month << "/" << year << endl;
}