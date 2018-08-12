#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

template <typename E>
DoubleLinkedList<E>::DoubleLinkedList() {
  head = new DLLNode<E>;
  tail = new DLLNode<E>;
  head->next = tail;
  head->prev = NULL;
  tail->prev = head;
  tail->next = NULL;
}

template <typename E>
DoubleLinkedList<E>::~DoubleLinkedList() {
  while(!(IsEmpty())) { 
    DeleteNode(1);
  }
  delete head;
  delete tail;
}

template <typename E> 
bool DoubleLinkedList<E>::IsEmpty() {
  return (head->next == tail);
}

template <typename E>
E& DoubleLinkedList<E>::FirstElement() {
  if(!IsEmpty()) {
    return (head->next->elem);
  }
  else {
    cout <<"Linked List is empty";
  }
}

template <typename E>
E& DoubleLinkedList<E>::LastElement() {
  return (tail->prev->elem);
}

template <typename E>
void DoubleLinkedList<E>::CreateDLL(E &e) {
  DLLNode<E>* temp = new DLLNode<E>;
  temp->elem = e;
  temp->next = NULL;
  temp->prev = NULL;
  DLLNode<E>* current = head;
  while(current->next!=tail) {
    current = current->next;
  }
  temp->next = tail;
  current->next = temp;
  temp->prev = current;
  tail->prev = temp;
}

template <typename E>
void DoubleLinkedList<E>::InsertNode(E &e, int pos) {
  if(pos> Length()+1) {
    cout<<"Cannot insert beyond length of list"; 
  }
  else {
    int position = 1;
    DLLNode<E> *current = head->next;
    DLLNode<E> *previous = head;
    while(current->next!=tail && position!=pos) {
      previous = current;
      current = current->next;
      position++;
    }
    DLLNode<E>* temp = new DLLNode<E>;
    temp->elem = e;
    temp->next = current;
    temp->prev = previous;
    current->prev = temp;
    previous->next = temp;
  }
}

template <typename E>
E& DoubleLinkedList<E>::DeleteNode(int pos) {
  if(IsEmpty()) {
    cout<<"List is empty";
  }
  else if(pos>Length()+1) {
    cout<<"Index out of Bounds";
  }
  else {
    DLLNode<E> *current = head->next;
    DLLNode<E>  *previous = head;
    int position = 1;
    while(current->next!=tail && position!=pos) {
      previous = current;
      current = current->next;
      position++;
    }
    E element = current->elem;
    previous->next = current->next;
    current->next->prev = previous;
    delete current;
    return element;
  }
}

template <typename E>
int DoubleLinkedList<E>::Length() {
  int length = 0;
  DLLNode<E> *current = head->next;
  while(current!= tail) {
    length++;
    current = current->next;
  }
  return length;
}

template <typename E>
int DoubleLinkedList<E>::GetIndex(E &e) {
  int index = 1;
  DLLNode<E> *current = head->next;
  while(current != tail && current->elem !=e) {
    current = current->next;
    index++;
  }
  if(index == Length()+1)
    return 0;
  else
    return index;
}

template <typename E>
void DoubleLinkedList<E>::DisplayDLL() {
  DLLNode<E> *current = head->next;
  while(current!=tail) {
    cout<<current->elem<<endl;
    current = current->next;
  }
}

template class DoubleLinkedList<int>;
template class DLLNode<int>;


