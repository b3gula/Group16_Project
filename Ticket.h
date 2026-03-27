#ifndef TICKET_H
#define TICKET_H
#include "Date.h"
#include "Address.h"
#include <string>

class Ticket {
private:
    Date ticket_date;
    Address ticket_location;
    std::string infraction_type;
public:
    Ticket();
    Ticket(Date d, Address loc, std::string infraction);
    void display() const;
};

#endif