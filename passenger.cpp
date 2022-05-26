#include <iostream>
#include "passenger.h"

Passenger::Passenger()
{
}

void Passenger::init()
{
    // std::cout << "Name: ";
    // std::cin >> name;
    // std::cout << "departure_city: ";
    // std::cin >> departure_city;
    // std::cout << "destination_city: ";
    // std::cin >> destination_city;
    // date_of_travel.init();
    // time_of_travel.init();
    // std::cout << "number_of_tickets: ";
    // std::cin >> number_of_tickets;


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