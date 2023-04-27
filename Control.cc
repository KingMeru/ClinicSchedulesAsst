#include "Control.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

Control::Control(bool b){
  CompareBehaviour<Animal*>* c = new CompareAge<Animal*>(b);
  animals.setBehaviour(c);
  schedule = new Schedule();
}

Control::~Control(){
  delete schedule;
  animals.cleanupData();
}

bool Control::addAppt(int animalId, int year, int month, int day, int hours, int mins){
  Animal* a;
  if(animals.find(animalId, &a)){
    return schedule->addAppt(a, year, month, day, hours, mins);
  }
  cout<<"\nERROR: Animal ID "<<animalId<<" was not found"<<endl;
  return false;
}

void Control::launch(){
  initAnimals();
  initSchedule();

  int year, month, day, hour, minute, id;
  int choice = 0;

  v.showMenu(choice);

  if(choice == 0){
    return;
  }

  while (choice != 0) {
    if (choice == 1){
      
      cout << *(schedule);
    }
    else if (choice == 2){
      v.printStr("Enter the animal ID: ");
      v.readInt(id);

      v.printStr("Enter the year: ");
      v.readInt(year);

      v.printStr("Enter the month: ");
      v.readInt(month);

      v.printStr("Enter the day: ");
      v.readInt(day);

      v.printStr("Enter the hour: ");
      v.readInt(hour);

      v.printStr("Enter the minutes: ");
      v.readInt(minute);

      if(addAppt(id, year, month, day, hour, minute)){
        v.printStr("\nSTATUS: Appointment was added");
      }
      else{
        v.printStr("STATUS: Appointment could not be added");
      }
    }
    else if (choice == 3){
      cout << animals;
    }
    v.showMenu(choice);
  }
  return;
}

void Control::initAnimals()
{
  animals.add(new Animal(C_DOG, "Lily", "F", 1, 6, "Sonja"));
  animals.add(new Animal(C_DOG, "Betsy", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_DOG, "Killer", "F", 3, 5, "Lee"));
  animals.add(new Animal(C_DOG, "Fluffy", "M", 2, 7, "NONE"));
  animals.add(new Animal(C_CAT, "Lady", "F", 11, 0, "Laura"));
  animals.add(new Animal(C_SPEC_OTHER, "Pecorino", "M", 0, 3, "Kara"));
  animals.add(new Animal(C_DOG, "Leon", "M", 4, 0, "Sonja"));
  animals.add(new Animal(C_SPEC_OTHER, "Quasar", "M", 1, 4, "Sharon"));
  animals.add(new Animal(C_CAT, "Shadow", "M", 5, 2, "Bill"));
  animals.add(new Animal(C_CAT, "Luka", "M", 7, 0, "Bill"));
  animals.add(new Animal(C_CAT, "Fiona", "F", 8, 0, "NONE"));
  animals.add(new Animal(C_CAT, "Ruby", "F", 5, 0, "NONE"));
  animals.add(new Animal(C_SPEC_OTHER, "Ziggy", "F", 3, 8, "Laura"));
  animals.add(new Animal(C_SPEC_OTHER, "Quark", "M", 9, 0, "Sharon"));
  animals.add(new Animal(C_SPEC_OTHER, "Gruyere", "M", 0, 3, "Kara"));
  animals.add(new Animal(C_SPEC_OTHER, "Limburger", "M", 0, 3, "Kara"));
}

void Control::initSchedule()
{
  addAppt(1002, 2023, 5, 10, 11, 15);
  addAppt(1005, 2023, 5, 10, 11, 30);	// conflict
  addAppt(1005, 2023, 5, 10, 11, 45);
  addAppt(1012, 2023, 5, 10, 11, 45);	// conflict
  addAppt(1012, 2023, 5, 10, 12, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1015, 2023, 5, 10, 11, 0);	// conflict
  addAppt(1013, 2023, 6, 8, 10, 0);
  addAppt(1007, 2023, 6, 8, 9, 45);	// conflict
  addAppt(1007, 2023, 6, 8, 9, 30);
  addAppt(1010, 2023, 5, 9, 11, 15);

  addAppt(1035, 2023, 6, 8, 11, 15);	// error
  addAppt(1006, 2018, 5, 8, 11, 45);	// error
  addAppt(1006, 2023, 14, 1, 11, 45);	// error
  addAppt(1006, 2023, 5, 41, 11, 45);	// error
  addAppt(1006, 2023, 5, 8, 1, 45);	// error
  addAppt(1006, 2023, 5, 8, 11, 25);	// error
}
