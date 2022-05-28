#include <iostream>
#include "seat.hpp"

Seat::Seat() : taken(false)
{
}

Seat::Seat(int index) : taken(false), index(index)
{
}

std::istream& operator>>(std::istream& is, Seat& entry)
{
    is >> entry.index;
    is >> entry.taken;
    // std::cout << entry.index << ">>" << entry.taken << ">>" << std::endl;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Seat& entry)
{
    os << entry.index;
    os << " ";
    os << entry.taken;
    os << " ";
    // std::cout << "<<" << entry.index << "<<" << entry.taken << std::endl;
    return os;
}

void Seat::take()
{
    taken = true;
}

bool Seat::isTaken()
{
    return taken;
}

int Seat::getIndex()
{
    return index;
}

void Seat::setNoneTaken()
{
    taken = false;
}

void Seat::print()
{
    std::cout << "Seat " << index + 1 << ": ";
    if (taken)  std::cout << "is taken" << std::endl;
    else std::cout << "is not taken" << std::endl;
}