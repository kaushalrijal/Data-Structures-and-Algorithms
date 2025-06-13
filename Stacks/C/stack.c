#include <stdio.h>

#define MAX_SIZE 5

#define true 1
#define false 0

typedef struct{
    int TOS;
    int data[MAX_SIZE];
} Stack;

int isFull(Stack *);
int isEmpty(Stack *);
void push(Stack *, int);
int pop(Stack *);

int main(){
    Stack s = {-1};
    int element, choice;

    do
    {
        printf("-------------\n");
        printf("1.PUSH\n2.POP\n3.isFull\n4.isEmpty\n5.Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element? ");
            scanf("%d", &element);
            push(&s, element);
            break;
        case 2:
            element = pop(&s);
            printf("POPPED %d FROM STACK\n", element);
            break;
        case 3:
            printf("STACK %s FULL\n", (isFull(&s) ? "IS" : "IS NOT"));
            break;
        case 4:
            printf("STACK %s EMPTY\n", (isEmpty(&s) ? "IS" : "IS NOT"));
            break;
        case 5:
            break;
        default:
            printf("INVALID CHOICE!");
            break;
        }
    } while (choice !=5);

    return 0;
}

int isFull(Stack* s){
    return s->TOS==MAX_SIZE-1;
}

int isEmpty(Stack* s){
    return s->TOS==-1;
}

void push(Stack* s, int element){
    if(isFull(s)){
        printf("STACK OVERFLOW!\n");
    } else {
        s->data[++(s->TOS)] = element;
    }
}

int pop(Stack* s){
    int element = -1;
    if(isEmpty(s)){
        printf("STACK UNDERFLOW!\n");
    } else {
        element = s->data[s->TOS];
        --(s->TOS);
    }
    return element;
}