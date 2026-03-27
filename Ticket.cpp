#include "Ticket.h"
#include <iostream>

Ticket::Ticket() : infraction_type("None") {}

Ticket::Ticket(Date d, Address loc, std::string infraction) 
    : ticket_date(d), ticket_location(loc), infraction_type(infraction) {}

void Ticket::display() const {
    if (infraction_type != "None") {
        std::cout << "Ticket: " << infraction_type << " on ";
        ticket_date.display();
    } else {
        std::cout << "No tickets.";
    }
}