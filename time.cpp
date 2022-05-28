#include <iostream>
#include <string>
#include <regex>

#include "time.hpp"

Time::Time()
    : hour(0), minute(0)
{
}

Time::Time(int hour, int minute)
    : hour(hour), minute(minute)
{
}

void Time::input()
{
    std::string str;
    std::regex regex_pattern("-?[0-9]+");
    while (true)
    {
        std::cout << "Hour: ";
        std::cin >> str;
        if (std::regex_match(str, regex_pattern))
        {
            if (isHour(std::stod(str)))
            {
                hour = std::stod(str);
                break;
            }
        }
    }
    while (true)
    {
        std::cout << "Minute: ";
        std::cin >> str;
        if (std::regex_match(str, regex_pattern))
        {
            if (isMinute(std::stod(str)))
            {
                minute = std::stod(str);
                break;
            }
        }
    }
}

bool Time::isHour(int hour)
{
    if (hour < 0) return false;
    if (hour > 23) return false;
    if (hour > 23) return false;
    return true;
}

bool Time::isMinute(int minute)
{
    if (minute < 0) return false;
    if (minute > 59) return false;
    return true;
}

void Time::print()
{
    std::cout << hour << ":" << minute << std::endl; 
}

std::istream& operator>>(std::istream& is, Time& entry)
{
    is >> entry.hour;
    is >> entry.minute;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Time& entry)
{
    os << entry.hour;
    os << " ";
    os << entry.minute;
    // os << " ";
    
    return os;
}