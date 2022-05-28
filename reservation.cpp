#include <iostream>
#include "reservation.hpp"

Reservation::Reservation()
{
}

Reservation::Reservation(Passenger passenger)
    : passenger(passenger)
{
}

void Reservation::set_tickets(std::vector<int> seat_indices)
{
    tickets.clear();
    for (int i = 0; i < seat_indices.size(); i++)
    {
        Ticket ticket;
        ticket.set_seat(seat_indices[i]);
        tickets.push_back(ticket);
    }
}

void Reservation::print()
{
    std::cout << "Passenger " << passenger.name << std::endl;
    for (int i = 0; i < tickets.size(); i++)
    {
        std::cout << "Ticket " << i + 1 << ": " << std::endl;
        tickets[i].print();
    }
}

std::istream& operator>>(std::istream& is, Reservation& entry)
{
    is >> entry.passenger;

    entry.tickets.resize(entry.passenger.number_of_tickets);

    for (int i = 0; i < entry.passenger.number_of_tickets; i++)
    {
        is >> entry.tickets[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Reservation& entry)
{
    os << entry.passenger;
    os << " ";


    for (std::vector<Ticket>::const_iterator it = entry.tickets.cbegin();
        it != entry.tickets.cend(); ++it)
    {
        os << *it;
        os << " ";
    }
    // os << "\n";
    
    return os;
}