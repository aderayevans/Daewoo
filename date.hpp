#ifndef DATE_HPP
#define DATE_HPP

struct Date
{
    Date();
    Date(int, int, int);
    bool operator == (Date& A) const;
    void input();
    bool isDay(int);
    bool isMonth(int);
    bool isYear(int);
    void print();
    

    int day;
    int month;
    int year;
};
std::istream& operator>>(std::istream& is, Date& entry);
std::ostream& operator<<(std::ostream& os, const Date& entry);
#endif