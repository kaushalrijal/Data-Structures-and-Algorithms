// WAP IN C TO EVALUATE POSTFIX EXPRESSION(one single character at a time)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 6

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
int isOperand(char);
int eval(char[]);
int operate(char, int, int);

int main(){
    char expression[MAX_SIZE] = "23+5*\0";
    int result;

    result = eval(expression);

    printf("The output of the expression is %d", result);

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

int isOperand(char c){
    return c >= 48 && c <=57;
}

int getOperand(char c){
    return c - 48;
}

int operate(char op, int op1, int op2){
    switch(op){
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default:
            printf("INVALID OPERATOR");
            exit(1);
    }
}

int eval(char expr[]){
    Stack s = {-1};
    int i=0, op1, op2, temp, result;
    printf("%s\n", expr);
    while(expr[i] != '\0'){
        if(isOperand(expr[i])){
            push(&s, getOperand(expr[i]));
        } else {
            op1 = pop(&s);
            op2 = pop(&s);
            temp = operate(expr[i], op2, op1);
            push(&s, temp);
        }
        ++i;
    }
    return s.data[s.TOS];
}