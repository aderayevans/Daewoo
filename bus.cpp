#include <iostream>
#include "bus.h"

Bus::Bus()
    : seat_num(10), non_taken_seat_num(10)
{
}

Bus::Bus(int seat_num)
    : seat_num(seat_num), non_taken_seat_num(seat_num)
{   
}

std::istream& operator>>(std::istream& is, Bus& entry)
{
    is >> entry.seat_num;
    is >> entry.non_taken_seat_num;

    // std::cout << entry.seat_num << ">>" << entry.non_taken_seat_num << "\n";

    entry.seats.resize(entry.seat_num);
    
    for (int i = 0; i < entry.seat_num; i++)
    {
        is >> entry.seats[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Bus& entry)
{
    os << entry.seat_num;
    os << " ";
    os << entry.non_taken_seat_num;
    os << " ";

    // std::cout << "<<" << entry.seat_num << "<<" << entry.non_taken_seat_num << std::endl;
    // std::cout << "<<" << entry.seats.size() << std::endl;

    for (std::vector<Seat>::const_iterator it = entry.seats.cbegin();
        it != entry.seats.cend(); ++it)
    {
        os << *it;
        os << " ";
    }

    return os;
}


void Bus::init()
{
    for (int i = 0; i < seat_num; i++)
    {
        Seat seat = Seat(i);
        seats.push_back(seat);
    }
}

bool Bus::is_available()
{
    return non_taken_seat_num;
}

bool Bus::check_seat(int seat)
{
    return !seats[seat].isTaken();
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

void Bus::un_get_seat(int seat)
{
    seats[seat].setNoneTaken();
}

void Bus::print()
{
    for (auto val:seats)
    {
        val.print();
    }
}