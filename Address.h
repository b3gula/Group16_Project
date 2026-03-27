#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string county;
    int zip;
public:
    Address(std::string st = "", std::string c = "", std::string stt = "", std::string cnty = "", int z = 0);
    std::string getCounty() const;
    void display() const;
};

#endif