#ifndef SEAT_HPP
#define SEAT_HPP

#include <fstream>

class Seat
{
public:
    Seat();

    Seat(int);

    void take();

    void setNoneTaken();

    bool isTaken();

    int getIndex();

    void print();
// private:
    bool taken;
    int index;
};
std::istream& operator>>(std::istream& is, Seat& entry);
std::ostream& operator<<(std::ostream& os, const Seat& entry);

#endif