#ifndef DATE_H
#define DATE_H

struct Date
{
    Date();
    Date(int, int, int);
    void fix_date();
    void fix_month();
    void print();
    

    int date;
    int month;
    int year;
};
#endif