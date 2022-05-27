#ifndef BUS_H
#define BUS_H

#include "seat.h"
#include <vector>
#include <string>
#include <fstream>

class Bus
{
public:
    Bus();

    Bus(int seat_num);

    void init();

    bool is_available();

    bool check_seat(int seat);

    Seat get_seat();

    Seat get_seat(int seat);

    void un_get_seat(int seat);

    void print();

// private:
    int seat_num;
    int non_taken_seat_num;
    std::vector<Seat> seats;
};

std::istream& operator>>(std::istream& is, Bus& entry);
std::ostream& operator<<(std::ostream& os, const Bus& entry);

#endif