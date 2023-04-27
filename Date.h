/*
 purpose: creates references to dates to allow proper documentation of appointments
*/
#ifndef DATE_H
#define DATE_H

#include "Time.h"
#include <iostream>

class Date
{
  friend ostream& operator<<(ostream&, Date&);

  public:
    Date(int=0, int=0, int=2000, int=0, int=0);
    ~Date();
    static bool validate(int, int, int);
    bool operator==(Date&);
    bool operator<(Date&);
    bool operator>(Date&);
    bool sameDay(Date&);
    Time& getTime();


  private:
    int day;
    int month;
    int year;
    Time time;
    void setDate(int, int, int);
    int lastDayInMonth();
    bool leapYear();
    static int lastMonthDay(int, int);
    static bool isLeapYear(int);
};

#endif
