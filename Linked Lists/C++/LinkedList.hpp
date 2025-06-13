#ifndef LinkedList_H
#define LinkedList_H

class Node{
public:
    int data;
    Node* next;
    Node(int element): data(element), next(nullptr){};
};

class SLL{
    Node *first, *last;
public:
    SLL(): first(nullptr), last(nullptr){};
    Node* createNode(int element);
    void insertAtBeg(int element);
    void insertAtEnd(int element);
    void insertAtPos(int element, int pos);
    void deleteAtBeg();
    void deleteAtEnd();
    void deleteAtPos(int pos);
    void search(int key);
    void display();
    void release();
    ~SLL();
};

#endif