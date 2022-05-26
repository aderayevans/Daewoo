#include <iostream>
#include "seat.h"

Seat::Seat() : taken(false)
{
}

Seat::Seat(int index) : taken(false), index(index)
{
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