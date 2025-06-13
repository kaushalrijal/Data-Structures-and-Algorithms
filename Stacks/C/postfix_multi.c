// WAP IN C TO EVALUATE POSTFIX EXPRESSION(more than one characters)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 50

#define true 1
#define false 0

typedef struct{
    int TOS;
    float data[MAX_SIZE];
} Stack;

int isFull(Stack *);
int isEmpty(Stack *);
void push(Stack *, float);
float pop(Stack *);
float operate(char*, float, float);
int eval(char[]);

int main(){
    char expression[MAX_SIZE];
    float result;

    printf("Enter the expression: ");
    fgets(expression, MAX_SIZE, stdin);

    result = eval(expression);

    printf("The output of the expression is %f\n", result);

    return 0;
}

int isFull(Stack* s){
    return s->TOS==MAX_SIZE-1;
}

int isEmpty(Stack* s){
    return s->TOS==-1;
}

void push(Stack* s, float element){
    if(isFull(s)){
        printf("STACK OVERFLOW!\n");
    } else {
        s->data[++(s->TOS)] = element;
    }
}

float pop(Stack* s){
    float element = -1;
    if(isEmpty(s)){
        printf("STACK UNDERFLOW!\n");
    } else {
        element = s->data[s->TOS];
        --(s->TOS);
    }
    return element;
}

float operate(char* token, float op1, float op2){
    switch(token[0]){
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '^' : return pow(op1, op2);
        default: printf("Invalid Operator!"); exit(1);
    }
}

int eval(char expr[]){
    Stack s = {-1};
    float op1, op2, temp, result;

    char *token = strtok(expr, " ");

    while(token != NULL){
        if((isdigit(token[0]))||(token[0] == '-')&&(isdigit(token[1]))){
            push(&s, atof(token));
        } else {
            op1 = pop(&s);
            op2 = pop(&s);
            result = operate(token, op2, op1);
            push(&s, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&s);
}