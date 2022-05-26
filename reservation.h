#ifndef RESERVATION_H
#define RESERVATION_H

#include "ticket.h"
#include "bus.h"
#include "passenger.h"

class Reservation
{
public:
    Reservation();

    Reservation(Bus*, Passenger*);

    void reserve_ticket();

    void print();

private:
    Bus *bus;
    Passenger *passenger;
    std::vector<Ticket> tickets;
};
#endif