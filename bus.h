#ifndef BUS_H
#define BUS_H

#include "seat.h"
#include <vector>
#include <string>

class Bus
{
public:
    Bus();

    Bus(int seat_num);

    void init();

    void load_from_file(std::string);

    bool is_available();

    Seat get_seat();

    Seat get_seat(int seat);

    void print();

private:
    int seat_num;
    int non_taken_seat_num;
    std::vector<Seat> seats;
};

#endif