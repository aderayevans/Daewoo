#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include "ticket.hpp"
#include "passenger.hpp"
#include <vector>

class Reservation
{
public:
    Reservation();
    Reservation(Passenger);
    void printMenu();
    void modify();

    void set_tickets(std::vector<int> seat_indices);
    void print();

// private:
    Passenger passenger;
    std::vector<Ticket> tickets;
};

std::istream& operator>>(std::istream& is, Reservation& entry);
std::ostream& operator<<(std::ostream& os, const Reservation& entry);
#endif