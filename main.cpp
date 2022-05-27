#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <vector>

#include "reservation.h"
#include "bus.h"
#include "passenger.h"
#include "handlefile.cpp"

#include "menuchoice.h"
#include "menuchoice_modify.h"


menuChoice hashTheChoice(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return menuChoice::quit;
    if (choice == "-h" || choice == "-help")
        return menuChoice::help;
    if (choice == "-i" || choice == "-init" || choice == "-make")
        return menuChoice::make;
    if (choice == "-m" || choice == "-modify")
        return menuChoice::modify;
    if (choice == "-c" || choice == "-cancel")
        return menuChoice::cancel;
    if (choice == "-s" || choice == "-save")
        return menuChoice::save;
    if (choice == "-b" || choice == "-blank")
        return menuChoice::blank;
    if (choice == "-sm" || choice == "-searchbyname")
        return menuChoice::searchbyname;
    if (choice == "-sd" || choice == "-searchbydate")
        return menuChoice::searchbydate;

    return menuChoice::wrong;
}


menuChoice_modify hashTheChoice_modify(std::string choice)
{
    if (choice == "-q" || choice == "-quit")
        return menuChoice_modify::quit;
    if (choice == "-h" || choice == "-help")
        return menuChoice_modify::help;
    if (choice == "-b" || choice == "-back" || choice == "-make")
        return menuChoice_modify::back;
    if (choice == "-p" || choice == "-passenger")
        return menuChoice_modify::modify_pas;
    if (choice == "-t" || choice == "-ticket")
        return menuChoice_modify::modify_tic;

    return menuChoice_modify::wrong;
}

// function prototypes
void printMenu();
void start();
void read_file();
void write_file();

void __save__();
void __make_blank__();
void make_res();
void modify_res();
void cancel_res();
void searchByName();
void searchByDate();

void process_modify(Reservation &res);
void printMenu_modify();
void modify_passenger(Reservation &res);
void modify_ticket(Reservation &res);


const std::string BUS_DATABASE = "bus_database";
const std::string RES_DATABASE = "res_database";

Bus bus;
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
    [s] or [save] to save
    [b] or [blank] to make blank
    [sm] or [searchbyname] to search reservations by name
    [sd] or [searchbydate] to search reservations by date of travel 
    
)";
}


void start()
{
    std::string menuInput;

    printMenu();

    read_file();


    while (true)
    {
        std::cout << "> ";
        std::cin >> menuInput;

        switch(hashTheChoice(menuInput))
        {
            case menuChoice::quit:
                exit(0);
            case menuChoice::help:
                printMenu();
                break;
            case menuChoice::make:
                make_res();
                break;
            case menuChoice::modify:
                modify_res();
                break;
            case menuChoice::cancel:
                cancel_res();
                break;
            case menuChoice::save:
                __save__();
                break;
            case menuChoice::blank:
                __make_blank__();
                break;
            case menuChoice::searchbyname:
                searchByName();
                break;
            case menuChoice::searchbydate:
                searchByDate();
                break;
            case menuChoice::wrong:
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
    Reservation reservation = Reservation(passenger);

    std::vector<int> seat_indices;
    for (int i = 0; i < passenger.number_of_tickets; i++)
    {
        Seat seat = bus.get_seat();
        seat_indices.push_back(seat.getIndex());
    }
    reservation.set_tickets(seat_indices);
    reservations.push_back(reservation);

    bus.print();
    for (auto res:reservations)
        res.print();
}

void modify_res()
{
    std::string the_name;
    std::cout << "Passenger name? ";
    std::cin >> the_name;

    for (auto i = reservations.begin(); i != reservations.end(); ++i) {
        if ((*i).passenger.name == the_name) {
            process_modify(*i);

            break;
        }
    }
}

void cancel_res()
{
    std::string the_name;
    std::cout << "Passenger name? ";
    std::cin >> the_name;


    for (int i = 0; i < reservations.size(); ++i) {
        if (reservations[i].passenger.name == the_name) {
            for (auto ticket:reservations[i].tickets)
                bus.un_get_seat(ticket.get_seat());
                
            reservations.erase(reservations.begin() + i);
            
            // reservations.erase(std::next(i));
            break;
        }
    }

    bus.print();
    for (auto res:reservations)
        res.print();

}

void searchByName()
{
    std::string the_name;
    std::cout << "Passenger name? ";
    std::cin >> the_name;

    for (auto val:reservations)
    {
        if (val.passenger.name == the_name)
            val.print();
    }
}

void searchByDate()
{
    Date the_date;
    the_date.input();

    for (auto val:reservations)
    {
        if (val.passenger.date_of_travel == the_date)
            val.print();
    }
}

void read_file()
{
    bus = HandleFile::read_file<Bus>(BUS_DATABASE);

    reservations = HandleFile::read_file_multiple_obj<Reservation>(RES_DATABASE);

    bus.print();
    std::cout << reservations.size() << std::endl;
    for (auto res:reservations)
    {
        res.print();
    }
}

void __save__()
{
    write_file();
}

void __make_blank__()
{
    bus = Bus();
    bus.init();

    reservations.clear();

    write_file();
}

void write_file()
{
    HandleFile::write_file<Bus>(BUS_DATABASE, bus);

    for (auto res:reservations)
    {
        HandleFile::write_file<Reservation>(RES_DATABASE, res, true);
    }
}




void process_modify(Reservation &res)
{
    std::string menuInput;

    printMenu_modify();

    while (true)
    {
        std::cout << "> ";
        std::cin >> menuInput;

        switch(hashTheChoice_modify(menuInput))
        {
            case menuChoice_modify::quit:
                exit(0);
            case menuChoice_modify::help:
                printMenu_modify();
                break;
            case menuChoice_modify::back:
                goto goBackPoint;
                break;
            case menuChoice_modify::modify_pas:
                modify_passenger(res);
                break;
            case menuChoice_modify::modify_tic:
                modify_ticket(res);
                break;
            case menuChoice_modify::wrong:
                std::cout << "Syntax Error !!!" << std::endl;
                printMenu_modify();
                break;
        }
        res.print();
    }
    goBackPoint:
    
    printMenu();
}


void printMenu_modify() 
{
    std::cout << R"(
**********               Modification Menu               **********
syntax: -[Function]

[Function]:
    [q] or [quit] to quit the application
    [h] or [help] to print this menu
    [b] or [back] to go back the previous menu
    [p] or [passenger] to modify passenger infomations
    [t] or [ticket] to modify ticket (seat number)
    
)";
}

void modify_passenger(Reservation &res)
{
    res.passenger.init(false);
    std::cout << "Modify passenger succeeded" << std::endl;
}

void modify_ticket(Reservation &res)
{
    for (auto ticket:res.tickets)
        bus.un_get_seat(ticket.get_seat());

    int seat_index;
    std::vector<int> seat_indices;
    for (int i = 0; i < res.passenger.number_of_tickets; i++)
    {
        std::cout << "Seat index: ";
        std::cin >> seat_index;
        
        if (bus.check_seat(seat_index-1))
        {
            Seat seat = bus.get_seat(seat_index-1);
            seat_indices.push_back(seat.getIndex());
        }
        else
        {
            std::cout << "Not available" << std::endl;
        }
    }
    res.set_tickets(seat_indices);

    std::cout << "Modify ticket succeeded" << std::endl;
}