#ifndef TIME_HPP
#define TIME_HPP

struct Time
{
    Time();
    Time(int, int);
    void input();
    bool isHour(int);
    bool isMinute(int);
    void print();

    int hour;
    int minute;
};
std::istream& operator>>(std::istream& is, Time& entry);
std::ostream& operator<<(std::ostream& os, const Time& entry);
#endif