#include <iostream>
#include "bus.h"

Bus::Bus()
    : seat_num(100), non_taken_seat_num(100)
{
}

Bus::Bus(int seat_num)
    : seat_num(seat_num), non_taken_seat_num(seat_num)
{
}

void Bus::init()
{
    for (int i = 0; i < seat_num; i++)
    {
        Seat seat = Seat(i);
        seats.push_back(seat);
    }
}

void Bus::load_from_file(std::string filename)
{
    
}

bool Bus::is_available()
{
    return non_taken_seat_num;
}

Seat Bus::get_seat()
{
    for (int i = 0; i < seat_num; i++)
    {
        if (!seats[i].isTaken())
        {
            seats[i].take();
            return seats[i];
        }
    }
    return seats[0];
}

Seat Bus::get_seat(int seat)
{
    seats[seat].take();
    return seats[seat];
}

void Bus::print()
{
    for (auto val:seats)
    {
        std::cout << val.getIndex() + 1 << ": ";
        if (val.isTaken())
            std::cout << "isTaken" << std::endl;
        else
            std::cout << "isNotTaken" << std::endl;
    }
}