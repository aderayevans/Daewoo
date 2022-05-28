#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
#include "date.hpp"

Date::Date()
    : day(1), month(1), year(2022)
{
}

Date::Date(int day, int month, int year) 
    : day(day), month(month), year(year)
{
}

bool Date::operator == (Date& A) const
{
    return (day == A.day) && (month == A.month) && (year == A.year);
}

void Date::input()
{
    std::string str;
    std::regex regex_pattern("-?[0-9]+");

    while (true)
    {
        std::cout << "Month: ";
        std::cin >> str;
        if (std::regex_match(str, regex_pattern))
        {
            if (isMonth(std::stod(str)))
            {
                month = std::stod(str);
                break;
            }
        }
    }
    while (true)
    {
        std::cout << "Day: ";
        std::cin >> str;
        if (std::regex_match(str, regex_pattern))
        {
            if (isDay(std::stod(str)))
            {
                day = std::stod(str);
                break;
            }
        }
    }
    while (true)
    {
        std::cout << "Year: ";
        std::cin >> str;
        if (std::regex_match(str, regex_pattern))
        {
            if (isYear(std::stod(str)))
            {
                year = std::stod(str);
                break;
            }
        }
    }
}

bool Date::isDay(int day)
{
    if (day < 1) return false;

    int month_have_31_days[] = {1, 3, 5, 7, 8, 10, 12};

    if (month == 2 && day > 29)
    {
        return false;
    }
    if (std::count(std::begin(month_have_31_days), std::end(month_have_31_days), month) > 0)
    {
        if (day > 31) return false;
    }
    else 
    {
        if (day > 30) return false;
    }
    return true;
}

bool Date::isMonth(int month)
{
    if (month < 1) return false;
    if (month > 12) return false;
    return true;
}

bool Date::isYear(int year)
{
    if (year < 0) return false;
    return true;
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