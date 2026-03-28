#include "Ticket.h"
#include <iostream>
Ticket::Ticket() : ticket_location("None"), infraction_type("None") {}
Ticket::Ticket(Date d, std::string loc, std::string infraction) 
    : ticket_date(d), ticket_location(loc), infraction_type(infraction) {}
void Ticket::display() const {
    if (infraction_type != "None") {
        std::cout << "Ticket: " << infraction_type << " on ";
        ticket_date.display();
        std::cout << " at " << ticket_location << std::endl;
    } else {
        std::cout << "No tickets.";
    }
}