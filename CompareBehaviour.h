/*
 purpose: Template class that defines the behaviour of a list of comparables
*/
#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

#include <iostream>
using namespace std;
#include <cstdlib>

template <class T>
class CompareBehaviour{
  protected:
    bool asc;
  public:
    CompareBehaviour(bool);
    virtual ~CompareBehaviour();
    virtual bool compare(T, T) = 0;

};

template <class T>
class CompareAge : public CompareBehaviour<T>{
    public:
      CompareAge(bool);
      virtual ~CompareAge();
      virtual bool compare(T, T);
};

template <class T>
class CompareDate : public CompareBehaviour<T>{
    public:
      CompareDate(bool);
      virtual ~CompareDate();
      virtual bool compare(T, T);
};

template <class T>
CompareBehaviour<T>::CompareBehaviour(bool b)
{
  asc = b;
}

template <class T>
CompareBehaviour<T>::~CompareBehaviour()
{
}

template <class T>
CompareAge<T>::CompareAge(bool b) : CompareBehaviour<T>(b)
{
}

template <class T>
CompareAge<T>::~CompareAge()
{
}

template <class T>
bool CompareAge<T>::compare(T obj1, T obj2){
  if(CompareBehaviour<T>::asc){
    if(obj1->getAge() < obj2->getAge()){
      return true;
    }
  }
  else{
    if(obj1->getAge() > obj2->getAge()){
      return true;
    }
  }
  return false;
}

template <class T>
CompareDate<T>::CompareDate(bool b) : CompareBehaviour<T>(b)
{
}

template <class T>
CompareDate<T>::~CompareDate()
{
}

template <class T>
bool CompareDate<T>::compare(T obj1, T obj2){
  if(CompareBehaviour<T>::asc){
    if(obj1->getDate() < obj2->getDate()){
      return true;
    }
  }
  else{
    if(obj1->getDate() > obj2->getDate()){
      return true;
    }
  }
  return false;
}

#endif
