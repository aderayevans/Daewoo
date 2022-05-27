#include <iostream>
#include "passenger.h"

Passenger::Passenger()
{
}

void Passenger::init(bool change_number_of_tickets)
{
    // std::cout << "Name: ";
    // std::cin >> name;
    // std::cout << "departure_city: ";
    // std::cin >> departure_city;
    // std::cout << "destination_city: ";
    // std::cin >> destination_city;
    // date_of_travel.init();
    // time_of_travel.init();
    if (change_number_of_tickets)
    {
        // std::cout << "number_of_tickets: ";
        // std::cin >> number_of_tickets;
    }


    name = "Test";
    departure_city = "TestDepart";
    destination_city = "TestDestinat";
    date_of_travel = Date(20, 11, 2022);
    time_of_travel = Time(10, 10);
    number_of_tickets = 2;
}

void Passenger::print()
{
    std::cout << "Name:" << name << std::endl;
    std::cout << "Departure_city:" << departure_city << std::endl;
    std::cout << "Destination_city:" << destination_city << std::endl;
    date_of_travel.print();
    time_of_travel.print();
    std::cout << "Number_of_tickets:" << number_of_tickets << std::endl;
}

std::istream& operator>>(std::istream& is, Passenger& entry)
{
    is >> entry.name;
    is >> entry.departure_city;
    is >> entry.destination_city;
    is >> entry.date_of_travel;
    is >> entry.time_of_travel;
    is >> entry.number_of_tickets;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Passenger& entry)
{
    os << entry.name;
    os << " ";
    os << entry.departure_city;
    os << " ";
    os << entry.destination_city;
    os << " ";
    os << entry.date_of_travel;
    os << " ";
    os << entry.time_of_travel;
    os << " ";
    os << entry.number_of_tickets;
    // os << " ";
    
    return os;
}