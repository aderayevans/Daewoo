#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <vector>

#include "reservation.h"
#include "bus.h"
#include "passenger.h"

const std::string FILENAME = "database";

enum menuChoice
{
    quit,
    help,
    make,
    modify,
    cancel,
    searchbyname,
    searchbydate,

    wrong
};

menuChoice hashTheChoice(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return quit;
    if (choice == "-h" || choice == "-help")
        return help;
    if (choice == "-i" || choice == "-init" || choice == "-make")
        return make;
    if (choice == "-m" || choice == "-modify")
        return modify;
    if (choice == "-c" || choice == "-cancel")
        return cancel;
    if (choice == "-sm" || choice == "-searchbyname")
        return searchbyname;
    if (choice == "-sd" || choice == "-searchbydate")
        return searchbydate;

    return wrong;
}

// function prototypes
void printMenu();
void start();

void make_res();
void modify_res();
void cancel_res();
void searchByName();
void searchByDate();

std::vector<Reservation> reservations;

int main()
{
    std::cout << R"(
                Welcome to Daewoo application
**********                                              **********
)";
    start();

    return 0;
}

void printMenu()
{
    std::cout << R"(
**********                                              **********
syntax: -[Function]

[Function]:
    [q] or [quit] to quit the application
    [h] or [help] to print this menu
    [i] or [init] or [make] to make a reservation
    [m] or [modify] to modify a reservation
    [c] or [cancel] to cancel a reservation
    [sm] or [searchbyname] to search reservations by name
    [sd] or [searchbydate] to search reservations by date of travel 
    
)";
}


void start()
{
    std::string menuInput;

    printMenu();

    while (true)
    {
        std::cout << "> ";
        std::cin >> menuInput;

        switch(hashTheChoice(menuInput))
        {
            case quit:
                exit(0);
            case help:
                printMenu();
                break;
            case make:
                make_res();
                break;
            case modify:
                modify_res();
                break;
            case cancel:
                cancel_res();
                break;
            case searchbyname:
                searchByName();
                break;
            case searchbydate:
                searchByDate();
                break;
            case wrong:
                std::cout << "Syntax Error !!!" << std::endl;
                printMenu();
                break;
        }
    }
}

void make_res()
{
    Passenger passenger = Passenger();
    passenger.init();
    Bus bus = Bus();
    bus.init();
    bus.load_from_file("database_bus");
    Reservation reservation = Reservation(&bus, &passenger);
    reservations.push_back(reservation);
}

void modify_res()
{
    std::cout << "donothing";
}

void cancel_res()
{
    std::cout << "donothing";
}

void searchByName()
{
    std::cout << "donothing";
    return ;
}

void searchByDate()
{
    std::cout << "donothing";
    return ;
}