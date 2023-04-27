#include "Animal.h"
#include <iomanip>

int Animal::nextId = ANIMAL_IDS;

Animal::Animal(SpeciesType s, string n, string g, int y, int m, string p){
  name = n;
  gender = g;
  age = (y * 12) + m;
  species = s;
  parent = p;
  id = nextId++;
}

Animal::~Animal(){}

int Animal::getId(){
  return id;
}
string Animal::getName(){
  return name;
}
string Animal::getParent(){
  return parent;
}
int Animal::getAge(){
  return age;
}


ostream& operator<<(ostream& output, Animal& a){
  string type;
  if(a.species == C_DOG){
    type = "Dog";
  }
  else if(a.species == C_CAT){
    type = "Cat";
  }
  else{
    type = "Other";
  }

  output<<setfill(' ');
  output<<setw(0);

  output<<a.id<<": "<<std::left<<setw(12)<<a.name<<" : "<<setw(5)<<type<<": Age: "
        <<setw(2)<<a.age/12<<" yrs, "<<a.age%12<<" mths: Parent: "
        <<a.parent;

  output<<setfill(' ');
  output<<setw(0);

  return output;
}
