#ifndef DATE_H
#define DATE_H

struct Date
{
    Date();
    Date(int, int, int);
    bool operator == (Date& A) const;
    void input();
    void fix_day();
    void fix_month();
    void print();
    

    int day;
    int month;
    int year;
};
std::istream& operator>>(std::istream& is, Date& entry);
std::ostream& operator<<(std::ostream& os, const Date& entry);
#endif