#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

template <typename E>
CircularLinkedList<E>::CircularLinkedList() {
  cursor = NULL;
}

template <typename E>
CircularLinkedList<E>::~CircularLinkedList() {
  while(!IsEmpty()) {
    DeleteNode(1);
  }
  delete cursor;
}

template <typename E>
bool CircularLinkedList<E>::IsEmpty() {
  return (cursor == NULL);
}

template <typename E>
E& CircularLinkedList<E>::FrontElement() {
  if(!IsEmpty()) {
    return (cursor->elem);
  }
}

template <typename E>
E& CircularLinkedList<E>::BackElement() {
  if(!IsEmpty()) {
    return cursor->next->elem;
   }
}

template <typename E>
void CircularLinkedList<E>::CreateCLL(E &e) {
  CLLNode<E>* temp = new CLLNode<E>;
  temp->elem = e;
  temp->next = NULL;
  if(IsEmpty()) {
    cursor = temp;
    cursor->next = cursor;
  }
  else {
    CLLNode<E>* current = cursor;
    while(current->next != cursor) {
      current = current->next;
    }
    current->next = temp;
    temp->next = cursor;
  }
}

template <typename E>
void CircularLinkedList<E>::InsertNode(E &e, int pos) {
  if(pos > Length()+1) {
    cout<<"Cannot add node beyond length of list";
  }
  else {
    CLLNode<E>* temp = new CLLNode<E>;
    temp->elem = e;
    temp->next = NULL;
    CLLNode<E>* current = cursor;
    CLLNode<E>* previous = cursor;
    if(pos == 1) {
      do{
        current = current->next;
        }while(current->next!=cursor);
      current->next = temp;
      temp->next = cursor;
      cursor = temp;
    }
    else {
      int position = 1;
      while(current->next!= cursor && position !=pos) {
        previous = current;
        current = current->next;
        position++;
      }
      previous->next = temp;
      temp->next = current;
    }
  }
}

template <typename E>
E& CircularLinkedList<E>::DeleteNode(int pos) {
  if(pos > Length()) {
    cout<<"Inded Out of Bounds";
  }
  else {
    CLLNode<E>* current = cursor;
    CLLNode<E>* previous = current;
    E element;
    if(pos == 1) {
      while(current->next!=cursor) {
        current = current->next;
      }
      current->next = cursor->next;
      cursor = cursor->next;
      element = previous->elem;
      delete previous;
    }
    else {
      int position = 1;
      while(current->next!=cursor && position != pos) {
        previous = current;
        current = current->next;
        position++;
      }
      previous->next = current->next;
      E element = current->elem;
      delete current;
    }
    return element;
  }
}

template <typename E>
int CircularLinkedList<E>::Length() {
  int length;
  if(!IsEmpty()) {
    length = 1;
    CLLNode<E>* current = cursor->next;
    while(current->next!=cursor) {
      length++;
      current = current->next;
    }
  }
  else {
    length = 0;
  }
  return length;
}

template <typename E>
void CircularLinkedList<E>::DisplayCLL() {
  if(IsEmpty()) {
    cout<<"List is empty"<<endl;
  }
  else {
    CLLNode<E> * current = cursor;
    do {
      cout<<current->elem<<endl;
      current = current->next;
     }while(current!=cursor);        
  }
}

template class CircularLinkedList<int>;
template class CLLNode<int>;
