/*
 purpose: Represents animals that are patients in a clinic
*/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
#include "defs.h"
using namespace std;



class Animal {

  friend ostream& operator<<(ostream&, Animal&);

  public:
    Animal(SpeciesType, string, string, int, int, string);
    ~Animal();
    int getId();
    string getName();
    string getParent();
    int getAge();




  private:
    static int nextId;
    int id;
    SpeciesType species;
    string name;
    string gender;
    int age;
    string parent;
};

#endif
