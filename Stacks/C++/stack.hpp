#ifndef STACK
#define STACK

class Stack{
    int data[10];
    int TOS;
public:
    Stack();
    int isFull();
    int isEmpty();
    void push(int);
    int pop();
};

#endif 