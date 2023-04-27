/*
  Purpose: Creates refernces to the time an appointment
*/
#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
  friend ostream& operator<<(ostream&, Time&);


  public:
    Time(int=0, int=0);
    bool operator==(Time&);
    bool operator<(Time&);
    void add(int, int);


  private:
    int hours;
    int minutes;
    int convertToSecs() const;
    void setTime(int, int);
};

#endif
