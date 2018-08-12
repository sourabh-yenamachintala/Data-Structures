#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <typename E> class DoubleLinkedList;

template <typename E>
class DLLNode {
  private:
    E elem;
    DLLNode<E>* next;
    DLLNode<E>* prev;
    friend class DoubleLinkedList<E>;
};

template <typename E>
class DoubleLinkedList {
 private:
   DLLNode<E> *head;
   DLLNode<E> *tail;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    bool IsEmpty();
    E& FirstElement();
    E& LastElement();
    void CreateDLL(E& e);
    void InsertNode(E& e, int pos);
    E& DeleteNode(int pos);
    int Length();
    int GetIndex(E& e);
    void DisplayDLL();
};

#endif
