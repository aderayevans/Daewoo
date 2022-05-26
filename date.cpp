#include <iostream>
#include <algorithm>
#include "date.h"

Date::Date()
    : date(1), month(1), year(2022)
{
}

Date::Date(int date, int month, int year) 
    : date(date), month(month), year(year)
{
    fix_month();
    fix_date();
}

void Date::fix_date()
{
    if (date < 1) date = 1;

    int month_have_31_days[] = {1, 3, 5, 7, 8, 10, 12};

    if (month == 2 && date > 29)
    {
        date = 29;
    }
    if (std::count(std::begin(month_have_31_days), std::end(month_have_31_days), month) > 0)
    {
        if (date > 31) date = 31;
    }
    else 
    {
        if (date > 30) date = 30;
    }
}

void Date::fix_month()
{
    if (month < 1) month = 1;
    if (month > 12) month = 12;
}

void Date::print()
{
    std::cout << date << "/" << month << "/" << year << std::endl; 
}