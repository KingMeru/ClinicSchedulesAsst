#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m){
  setTime(h, m);
}


bool Time::operator==(Time& time){
  return ( convertToSecs() == time.convertToSecs() );
}

bool Time::operator<(Time& time){
  return ( convertToSecs() < time.convertToSecs() );
}

ostream& operator<<(ostream& output, Time& t){
  output<<setw(0);
  output<<setfill(' ');

  output <<setw(2)<<setfill('0')<<std::right<< t.hours << ":";
  output <<setw(2)<<setfill('0')<<std::right<< t.minutes;

  output<<setfill(' ');
  output<<setw(0);

  return output;
}


void Time::setTime(int h, int m){
  hours   = ( h >= 0 && h < 24) ? h : 0;
  minutes = ( m >= 0 && m < 60) ? m : 0;
}

int Time::convertToSecs() const
{
  return (hours*60 + minutes);
}

void Time::add(int hours, int minutes){
  int newTime = convertToSecs() + (hours*60) + minutes;
  int h = newTime / 60;
  int t = newTime % 60;
  setTime(h, t);
}
