#ifndef TICKET_H
#define TICKET_H

class Ticket
{
public:
    Ticket();
    void set_seat(int seat_index);
    int get_seat();
    void print();
// private:
    int seat_index;
};

std::istream& operator>>(std::istream& is, Ticket& entry);
std::ostream& operator<<(std::ostream& os, const Ticket& entry);
#endif