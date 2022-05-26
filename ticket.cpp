#include <iostream>
#include "ticket.h"

Ticket::Ticket()
{
}

void Ticket::set_bus(Bus *bus)
{
    this->bus = bus;
}

void Ticket::set_passenger(Passenger *passenger)
{
    this->passenger = passenger;
}

void Ticket::set_seat(Seat seat)
{
    this->seat = seat;
}

void Ticket::print()
{
    std::cout << "Passenger: " << passenger->name << std::endl;
    std::cout << "\t Seat: \t" << seat.getIndex() << std::endl;
}