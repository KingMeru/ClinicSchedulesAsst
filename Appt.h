/*
 purpose: Represents appointments of a clinic
*/
#ifndef APPT_H
#define APPT_H
#include <iostream>
#include "Animal.h"
#include "Date.h"

class Appt
{
  friend ostream& operator<<(ostream&, Appt&);

  public:
    Appt(Animal*, Date*);
    ~Appt();
    bool sameDay(Appt*);
    int getId();
    Date& getDate();

  private:
    static int nextId;
    int id;
    Animal* pet;
    Date* day;
};

#endif
