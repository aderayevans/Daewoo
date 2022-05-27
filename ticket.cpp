#include <iostream>
#include "ticket.h"

Ticket::Ticket()
{
}

void Ticket::set_seat(int seat_index)
{
    this->seat_index = seat_index;
}

void Ticket::print()
{
    std::cout << "\t Seat: \t" << this->seat_index + 1 << std::endl;
}

int Ticket::get_seat()
{
    return seat_index;
}

std::istream& operator>>(std::istream& is, Ticket& entry)
{
    is >> entry.seat_index;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Ticket& entry)
{
    os << entry.seat_index;
    os << " ";
    
    return os;
}