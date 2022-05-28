#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <vector>

#include "reservation.hpp"
#include "bus.hpp"
#include "passenger.hpp"
#include "handlefile.cpp"

#include "menuchoice.hpp"
#include "menuchoice_modify.hpp"




// function prototypes
void start();
void read_file();
void write_file(WRITER_MODE mode=WRITER_MODE::APPEND);

void __print__();
void __make_blank__();
void make_res();
void modify_res();
void cancel_res();
void searchByName();
void searchByDate();

void process_modify(Reservation &res);
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
                write_file();
                break;
            case menuChoice::print:
                __print__();
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
    passenger.input();
    Reservation reservation = Reservation(passenger);

    std::vector<int> seat_indices;
    for (int i = 0; i < passenger.number_of_tickets; i++)
    {
        Seat seat = bus.get_seat();
        seat_indices.push_back(seat.getIndex());
    }
    reservation.set_tickets(seat_indices);
    reservations.push_back(reservation);

    __print__();
}

void modify_res()
{
    write_file(WRITER_MODE::CLEAR);
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
    write_file(WRITER_MODE::CLEAR);
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

    __print__();
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

void __print__()
{
    bus.print();
    std::cout << "Number of reservation: " << reservations.size() << std::endl;
    for (auto res:reservations)
        res.print();
}

void __make_blank__()
{
    bus = Bus();
    bus.init(10);

    reservations.clear();
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

void modify_passenger(Reservation &res)
{
    res.passenger.input(false);
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

void read_file()
{
    std::cout << "Reading " << BUS_DATABASE << std::endl;
    bus = HandleFile::read_file<Bus>(BUS_DATABASE);
    // bus.init(10);

    std::cout << "Reading " << RES_DATABASE << std::endl;
    reservations = HandleFile::read_file_multiple_obj<Reservation>(RES_DATABASE);

    __print__();
}

void write_file(WRITER_MODE mode)
{
    std::cout << "Writing to " << BUS_DATABASE << std::endl;
    HandleFile::write_file<Bus>(BUS_DATABASE, bus, WRITER_MODE::TRUNCATE);

    std::cout << "Writing to " << RES_DATABASE << std::endl;
    if (reservations.size())
        for (auto res:reservations)
        {
            HandleFile::write_file<Reservation>(RES_DATABASE, res, mode);
        }
    else
        HandleFile::write_file<char>(RES_DATABASE, ' ', WRITER_MODE::CLEAR);
}