#ifndef TICKET_H
#define TICKET_H

#include "passenger.h"
#include "bus.h"
#include "seat.h"

class Ticket
{
public:
    Ticket();
    void set_bus(Bus *bus);
    void set_passenger(Passenger *passenger);
    void set_seat(Seat seat);
    void print();
private:
    Bus *bus;
    Passenger *passenger;
    Seat seat;
};
#endif