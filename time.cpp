#include <iostream>
#include "time.h"

Time::Time()
    : hour(0), minute(0)
{
}

Time::Time(int hour, int minute)
    : hour(hour), minute(minute)
{
}

void Time::fix_hour()
{
    if (hour < 0) hour = 0;
    if (hour > 23) hour = 23;
}

void Time::fix_minute()
{
    if (minute < 0) minute = 0;
    if (minute > 59) minute = 59;
}

void Time::print()
{
    std::cout << hour << ":" << minute << std::endl; 
}