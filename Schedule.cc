#include "Schedule.h"
#include "defs.h"

#include <iomanip>

Schedule::Schedule(bool b){
  CompareBehaviour<Appt*>* c = new CompareDate<Appt*>(b);
  appoints.setBehaviour(c);
}

Schedule::~Schedule(){
  appoints.cleanupData();
}

bool Schedule::addAppt(Animal* animal, int year, int month, int day, int hours, int mins){
  if(!parameterCheck(year, month, day, hours, mins)){
    return false;
  }

  Date * nDate = new Date(day, month, year, hours, mins);
  Appt* nAppt = new Appt(animal, nDate);

  Appt* arr[MAX_ARR];
  int size;
  appoints.convertToArray(arr, size);

  if(scheduleConflict(arr, size, nAppt, nDate)){
    delete nAppt;
    return false;
  }

  appoints.add(nAppt);
  return true;
}

bool Schedule::scheduleConflict(Appt** arr, int size, Appt* nAppt, Date* nDate){

  Time paramEnd = nDate->getTime();
  paramEnd.add(0, APPT_DURATION);

  for(int i = 0; i < size; ++i){
    if(arr[i]->sameDay(nAppt)){
      if(arr[i]->getDate() == *nDate){
        printError(nAppt, nDate, arr[i]);
        return true;
      }
      Time rsvEnd = arr[i]->getDate().getTime();
      rsvEnd.add(0, APPT_DURATION);

      if(!(nDate->getTime() < arr[i]->getDate().getTime()) && (nDate->getTime() < rsvEnd)){
        printError(nAppt, nDate, arr[i]);
        return true;
      }

      if(!(arr[i]->getDate().getTime() < nDate->getTime()) && (arr[i]->getDate().getTime() < paramEnd)){
        printError(nAppt, nDate, arr[i]);
        return true;
      }
    }
  }
  return false;
}

void Schedule::printError(Appt* nAppt, Date* nDate, Appt* oAppt){
  cout<<"\nERROR: Appointment "<<nAppt->getId()<<" on "<<*nDate<<" conflicts with "
  <<oAppt->getId()<<" on "<<oAppt->getDate()<<endl;
  return;
}

bool Schedule::parameterCheck(int year, int month, int day, int hours, int mins){
  if(year != CURR_YEAR){
    cout<<"\nERROR: Year "<<year<<" is invalid"<<endl;
    return false;
  }
  if(!(Date::validate(year, month, day))){
    cout<<"\nERROR: Date "<<year<<"/"<<month<<"/"<<day<<" is invalid"<<endl;
    return false;
  }
  if(hours < OPEN_HRS || hours > CLOSE_HRS){
    cout<<"\nERROR: Hour "<<hours<<" is invalid"<<endl;
    return false;
  }
  if((mins % 15 != 0) || mins > 59){
    cout<<"\nERROR: minutes "<<mins<<" are invalid"<<endl;
    return false;
  }
  return true;
}

ostream& operator<<(ostream& output, Schedule& a){

  output << a.appoints;
  return output;
}
