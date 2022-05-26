#ifndef SEAT_H
#define SEAT_H

class Seat
{
public:
    Seat();

    Seat(int);

    void take();

    bool isTaken();

    int getIndex();
private:
    bool taken;
    int index;
};
#endif