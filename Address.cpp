#include "Address.h"
#include <iostream>

Address::Address(std::string st, std::string c, std::string stt, std::string cnty, int z) 
    : street(st), city(c), state(stt), county(cnty), zip(z) {}

std::string Address::getCounty() const { return county; }

void Address::display() const {
    std::cout << street << ", " << city << ", " << state << " " << zip << " (" << county << " County)";
}