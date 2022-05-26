#include <iostream>
#include "reservation.h"

Reservation::Reservation()
{
}

Reservation::Reservation(Bus *bus, Passenger *passenger)
    // : bus(bus), passenger(passenger)
{
    this->bus = bus;
    this->passenger = passenger;
    // this->bus.print();
    // this->passenger.print();
    reserve_ticket();
}

void Reservation::reserve_ticket()
{
    Ticket ticket;
    for (int i = 0; i < passenger->number_of_tickets; i++)
    {
        ticket = Ticket();
        ticket.set_bus(bus);
        ticket.set_passenger(passenger);
        ticket.set_seat(bus->get_seat());

        tickets.push_back(ticket);
    }
}

void Reservation::print()
{
    for (int i = 0; i < tickets.size(); i++)
    {
        std::cout << "Ticket " << i + 1 << ": " << std::endl;
        tickets[i].print();
    }
}