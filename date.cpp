#include <iostream>
#include <algorithm>
#include "date.h"

Date::Date()
    : day(1), month(1), year(2022)
{
}

Date::Date(int day, int month, int year) 
    : day(day), month(month), year(year)
{
    fix_month();
    fix_day();
}

bool Date::operator == (Date& A) const
{
    return (day == A.day) && (month == A.month) && (year == A.year);
}

void Date::fix_day()
{
    if (day < 1) day = 1;

    int month_have_31_days[] = {1, 3, 5, 7, 8, 10, 12};

    if (month == 2 && day > 29)
    {
        day = 29;
    }
    if (std::count(std::begin(month_have_31_days), std::end(month_have_31_days), month) > 0)
    {
        if (day > 31) day = 31;
    }
    else 
    {
        if (day > 30) day = 30;
    }
}

void Date::fix_month()
{
    if (month < 1) month = 1;
    if (month > 12) month = 12;
}

void Date::input()
{
    std::cout << "Day: "; std::cin >> day;
    std::cout << "Month: "; std::cin >> month;
    std::cout << "Year: "; std::cin >> year;
}

void Date::print()
{
    std::cout << day << "/" << month << "/" << year << std::endl; 
}

std::istream& operator>>(std::istream& is, Date& entry)
{
    is >> entry.day;
    is >> entry.month;
    is >> entry.year;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& entry)
{
    os << entry.day;
    os << " ";
    os << entry.month;
    os << " ";
    os << entry.year;
    // os << " ";
    
    return os;
}