#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y, int hrs, int min): time(hrs, min) {
  setDate(d, m, y);
}

Date::~Date(){

}
bool Date::validate(int year, int month, int day){
  return (year > 0) && ( month > 0 && month <= 12) && ( day > 0 && day <= lastMonthDay(month, year));

}

Time& Date::getTime(){
  return time;
}

bool Date::sameDay(Date& date){
  if(year == date.year && month == date.month && day == date.day){
    return true;
  }
  return false;
}

bool Date::operator==(Date& date){
  if(sameDay(date) && time == date.getTime()){
    return true;
  }
  return false;
}

bool Date::operator<(Date& date){
  if(year < date.year){
    return true;
  }
  if(year == date.year){
    if(month < date.month){
      return true;
    }
    else if(month == date.month){
      if(day < date.day){
        return true;
      }
      else if(day == date.day){
        if(time < date.getTime()){
          return true;
        }
      }
    }
  }
  return false;
}
bool Date::operator>(Date& date){
  if(*this == date || *this < date){
    return false;
  }
  return true;
}

int Date::lastMonthDay(int month, int year)
{
  switch(month)
  {
    case 2:
      if (isLeapYear(year))
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}
bool Date::isLeapYear(int year)
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}

void Date::setDate(int d,int m,int y)
{
  year  = ( ( y > 0) ? y : 0 );
  month = ( ( m > 0 && m <= 12) ? m : 0 );
  day   = ( ( d > 0 && d <= lastDayInMonth() ) ? d : 0 );
}

ostream& operator<<(ostream& output, Date& d){
  output<<setw(0);
  output<<setfill(' ');

  output<<d.year<<"-"<<setw(2)<<setfill('0')<<std::right<<d.month
  <<"-"<<setw(2)<<setfill('0')<<std::right<<d.day<<" @ ";
  output<<setw(0)<<setfill(' ')<<d.getTime();

  output<<setfill(' ');
  output<<setw(0);

  return output;
}

int Date::lastDayInMonth()
{
  switch(month)
  {
    case 2:
      if (leapYear())
        return 29;
      else
        return 28;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    default:
      return 30;
  }
}

bool Date::leapYear()
{
  if ( year%400 == 0 ||
       (year%4 == 0 && year%100 != 0) )
    return true;
  else
    return false;
}
