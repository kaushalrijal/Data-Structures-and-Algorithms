#ifndef SLL_H
#define SLL_H

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct SLL {
    struct node* first;
    struct node* last;
} SLL;

// metohds
node* createNode(int element);
void insertAtBeg(SLL* list, int element);
void insertAtEnd(SLL* list, int element);
void insertAtPos(SLL* list, int element, int pos);
void deleteAtBeg(SLL* list);
void deleteAtEnd(SLL* list);
void deleteAtPos(SLL* list, int pos);
void search(SLL* list, int key);
void display(SLL* list);
void release(SLL* list);

#endif