#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

template <typename E>
SingleLinkedList<E>::SingleLinkedList()
		    :head(NULL) {}

template <typename E>
SingleLinkedList<E>::~SingleLinkedList() {
  while(!IsEmpty()) {
    RemoveNode(1);
  }
}

template <typename E>
bool SingleLinkedList<E>::IsEmpty()  {
  return (head == NULL);
}

template <typename E>
void SingleLinkedList<E>::CreateSLL( E& e) {
  SLLNode<E> *temp = new SLLNode<E>; 
  temp->elem = e;
  if(head == NULL) {
    head = temp;
  }
  else {
    SLLNode<E> *current = head;
    while(current->next!= NULL) {
      current = current->next;
    }
    current->next = temp;
  }
}

template <typename E>
void SingleLinkedList<E>::DisplaySLL() {
  SLLNode<E> *current = head;
  int index =1;
  if(IsEmpty()) {
    cout<<"Linked List is empty";
  }
  else {
    while(current != NULL) {
      cout<<index<<". "<<current->elem<<endl;
      index++;
      current = current->next;
    }
  }
  delete current;
}

template <typename E>
 E& SingleLinkedList<E>::FirstElement() {
  if(head!=NULL) {
    return head->elem;
  }
  else {
    cout<<"Linked List is empty";
  }
}

template <typename E>
 E& SingleLinkedList<E>::LastElement()  {
  E lastElement;
  if(!IsEmpty()) {
    SLLNode<E> *current = head;
    while(current->next != NULL) {
      current = current->next;
    }
    lastElement = current->elem;
    delete current;
    return lastElement;
  }
  else {
    cout<<"Linked List is empty";
  }
}

template <typename E>
int SingleLinkedList<E>::Length() {
  int length;
  if(head == NULL) return 0;
  else {
    SLLNode<E>* current = head;
    while(current!= NULL) {
      length++;
      current = current->next;
    }
    delete current;
    return length;
  }
}

template <typename E>
void SingleLinkedList<E>::InsertNode(E& e, int pos) {
  SLLNode<E>* temp = new SLLNode<E>;
  temp->elem = e;
  temp->next = NULL;
  if(pos > Length()+1) {
    cout<<"Cannot insert beyond last node "<<endl;
    cout<<"Current length of linked list= "<<Length();
    return;
  }
  else if(pos == 1) {
    temp->next = head;
    head = temp;
   }
  else {
    int position=0;
    SLLNode<E> *temp = new SLLNode<E>;
    temp->elem = e; 
    temp->next = NULL;
    SLLNode<E> *current = head;
    SLLNode<E> *previous = current;
    while(current->next!=NULL && position!= pos-1) {
      position++;
      previous = current;
      current = current->next;
    }
    previous->next = temp;
    temp->next = current;
  }
}

template <typename E>
E& SingleLinkedList<E>::RemoveNode(int pos) {
  int element;
  if(IsEmpty()) {
    cout<<"Linked List is empty";
  }
  else if(pos>Length()) {
    cout<<"Index out of bounds";
  }
  else {
    int position = 1;
    SLLNode<E> *current = head;
    if(pos == 1) {
      SLLNode<E> *current = head;
      element = head->elem;
      head = head->next;
      delete current;
      return element;
    }
    else {
      while(current->next!=NULL && position !=pos-1) {
        current= current->next;
        position++;
      }
      SLLNode<E> *remove = current->next;
      current->next = remove->next;
      element = remove->elem;
      delete remove;
      return element;
    }
  }
}

template class SingleLinkedList<int>;
template class SLLNode<int>;

