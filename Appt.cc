#include "Appt.h"
#include "defs.h"
#include <iomanip>
using namespace std;

int Appt::nextId = APPT_IDS;

Appt::Appt(Animal* a, Date* d){
  id = nextId++;
  pet = a;
  day = d;
}

Appt::~Appt(){
  delete day;
}

bool Appt::sameDay(Appt* other){
  return day->sameDay(other->getDate());
}

Date& Appt::getDate(){
  return *day;
}

int Appt::getId(){
  return id;
}

ostream& operator<<(ostream& output, Appt& a){
  output<<setfill(' ');
  output<<setw(0);

  output <<a.id<<" "<<*a.day<<" -- "<<setw(10)<<std::left<<a.pet->getName();
  output<<" with parent "<<a.pet->getParent();

  output<<setfill(' ');
  output<<setw(0);

  return output;
}
