/*
 purpose: Connects the view to the logic of the program
*/
#ifndef CONTROL_H
#define CONTROL_H
#include "Schedule.h"
#include "View.h"
#include "List.h"


class Control
{
  public:
    Control(bool=false);
    ~Control();
    void launch();
  private:
    void initSchedule();
    void initAnimals();
    bool addAppt(int, int, int, int, int, int);
    Schedule* schedule;
    List<Animal*> animals;
    View v;
};

#endif
