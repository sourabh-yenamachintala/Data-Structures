#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

template <typename E> class CircularLinkedList;

template <typename E>
class CLLNode {
  private:
    E elem;
    CLLNode<E> *next;
    friend class CircularLinkedList<E>;
};

template <typename E>
class CircularLinkedList {
  private :
    CLLNode<E>* cursor;
  public:
    CircularLinkedList();
    ~CircularLinkedList();
    bool IsEmpty();
    E& FrontElement();
    E& BackElement();
    void CreateCLL(E &e);
    void InsertNode(E &e, int pos);
    E& DeleteNode(int pos);
    int Length();
    void DisplayCLL();
};

#endif
