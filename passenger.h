#ifndef PASSENGER_H
#define PASSENGER_H

 // printer.h code goes here


#include "date.h"
#include "time.h"

class Passenger
{
public:
    // Passenger();
    // void print();

    Passenger();

    void init();

    void print();

    std::string name;
    std::string departure_city;
    std::string destination_city;
    Date date_of_travel;
    Time time_of_travel;
    int number_of_tickets;
};

#endif