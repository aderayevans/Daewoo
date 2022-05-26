#ifndef TIME_H
#define TIME_H

struct Time
{
    Time();
    Time(int, int);
    void fix_hour();
    void fix_minute();
    void print();

    int hour;
    int minute;
};
#endif