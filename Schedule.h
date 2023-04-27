/*
 purpose: Stores and adds to the schedule of a clinic
*/
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>

#include "List.h"
#include "Appt.h"

class Schedule
{
  friend ostream& operator<<(ostream&, Schedule&);

  public:
    Schedule(bool=true);
    ~Schedule();
    bool addAppt(Animal*, int, int, int, int, int);

  private:
    int numAppts;
    bool parameterCheck(int, int, int, int, int);//validates the given parameter
    void printError(Appt*, Date*, Appt*);//prints scheduling error
    bool scheduleConflict(Appt**, int, Appt*, Date*);//checks for scheduling conflict
    List<Appt*> appoints;
};

#endif
