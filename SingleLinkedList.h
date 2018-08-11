#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

template <typename E> class SingleLinkedList;

template <typename E>
class SLLNode {
  private:
    E elem;
    SLLNode<E>* next;
    friend class SingleLinkedList<E>;
};

template <typename E>
class SingleLinkedList {
  private:
    SLLNode<E> *head;
  public:
    SingleLinkedList(); 
    ~SingleLinkedList();
    bool IsEmpty();   //Is Linked list empty?
    E& FirstElement();
    E& LastElement();
    void CreateSLL(E& e);
    void InsertNode(E& e, int pos);  //Insert node at  pos
    E&  RemoveNode(int pos);          //Remove node at pos
    int Length();
    void DisplaySLL();
};

#endif
