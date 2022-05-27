#ifndef PASSENGER_H
#define PASSENGER_H

 // printer.h code goes here


#include "date.h"
#include "time.h"

class Passenger
{
public:
    Passenger();

    void init(bool change__number_of_tickets=true);

    void print();

    std::string name;
    std::string departure_city;
    std::string destination_city;
    Date date_of_travel;
    Time time_of_travel;
    int number_of_tickets;
};
std::istream& operator>>(std::istream& is, Passenger& entry);
std::ostream& operator<<(std::ostream& os, const Passenger& entry);

#endif