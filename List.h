/*
 purpose: Template class that stores comparable objects in  a linked list
*/
#ifndef LIST_H
#define LIST_H

#include "CompareBehaviour.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstddef>

template <typename U>
class List;

template <class T>
class Node{
  template <class W>
  friend ostream& operator<<(ostream&, const Node<W>&);
  template <typename U> friend class List;

  private:
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <class T>
class List{
  template <class U>
  friend ostream& operator<<(ostream&, const List<U>&);

  public:
    List();
    virtual~List();
    bool add(T);
    virtual bool find(int, T*);
    void convertToArray(T* arr, int& size);
    void cleanupData();
    void setBehaviour(CompareBehaviour<T>*);

  private:
    Node<T>* head;
    CompareBehaviour<T>* behaviour;
};

template <class T>
List<T>::List() : head(NULL), behaviour(NULL){

}

template <class T>
List<T>::~List(){
  Node<T>* currNode = head;
  Node<T>* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }

  if(behaviour != NULL) delete behaviour;
}

template <class T>
ostream& operator<<(ostream& output, const List<T>& arr){
  output << *(arr.head);
  return output;
}

template <class T>
ostream& operator<<(ostream& output, const Node<T>& arr){
  const Node<T>* currNode = &arr;
  const Node<T>* backNode = NULL;
  output<<"--FORWARD"<<"\n";
  while (currNode != NULL) {
    output << *(currNode->data) <<endl;
    currNode = currNode->next;
    if(currNode != NULL){
      backNode = currNode;
    }
  }
  output<<"--BACKWARD"<<"\n";

  while(backNode != NULL){
    output << *(backNode->data)<<endl;
    backNode = backNode->prev;
  }

  return output;
}
template <class T>
void List<T>::setBehaviour(CompareBehaviour<T>* b){

  if(behaviour != NULL) delete behaviour;
  behaviour = b;
}

template <class T>
bool List<T>::add(T obj){
  Node<T>* tmpNode;
  Node<T>* currNode;
  Node<T>* prevNode;

  tmpNode = new Node<T>;
  tmpNode->data = obj;
  tmpNode->next = NULL;
  tmpNode->prev = NULL;

  prevNode = NULL;
  currNode = head;
  while (currNode != NULL) {
    if (behaviour->compare(tmpNode->data, currNode->data)) {
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = tmpNode;
  }
  else {
    prevNode->next = tmpNode;
    tmpNode->prev = prevNode;
  }

  if(currNode != NULL){
    currNode->prev = tmpNode;
  }

  tmpNode->next  = currNode;

  return true;
  }




template <class T>
bool List<T>::find(int id, T* foundObj){
  Node<T>* currNode = head;

  while (currNode != NULL) {
    if(currNode->data->getId() == id){
      *foundObj = currNode->data;
      return true;
    }
    currNode = currNode->next;
  }
  return false;
}
template <class T>
void List<T>::convertToArray(T* arr, int& size){
  int s = 0;
  Node<T>* currNode = head;

  while (currNode != NULL) {
    arr[s++] = currNode->data;
    currNode = currNode->next;
  }
  size = s;
}
template <class T>
void List<T>::cleanupData(){
  Node<T>* currNode = head;
  while (currNode != NULL) {
    delete currNode->data;
    currNode = currNode->next;
  }

}

#endif
