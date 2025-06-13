#include<iostream>

#define SIZE 5

using namespace std;

class Stack{
    int data[SIZE];
    int TOS;

public:
    Stack(){
        TOS = -1;
    };

    int isFull(){
        return TOS == SIZE-1;
    }

    int isEmpty(){
        return TOS == -1;
    };

    void push(int element){
        if(isFull()){
            cout << "STACK OVERFLOW" << endl;
            return;
        }
        data[++TOS] = element;
        cout << "PUSHED " << element << " TO STACK" << endl;
    };
    
    int pop(){
        int element = -1;
        if(isEmpty()){
            cout << "STACK UNDERFLOW" << endl;
            return element;
        }
        element = data[TOS--]; 
        cout << "POPPED " << element << " FROM STACK" << endl;
        return element;
    };

};

int main(){
    Stack s;
    int element, choice;

    do{
        cout << "\n1.PUSH\n2.POP\n3.isFull\n4.isEmpty\n5.Exit\n" << endl;
        cout << "Choice? ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Element? ";
            cin >> element;
            s.push(element);
            break;
        case 2:
            element = s.pop();
            break;
        case 3:
            cout << "STACK " << (s.isFull() ? "IS" : "IS NOT") << " FULL" << endl; 
            break;
        case 4:
            cout << "STACK " << (s.isEmpty() ? "IS" : "IS NOT") << " EMPTY" << endl;
            break;
        case 5:
            break;
        default:
            cout << "INVALID CHOICE!" << endl;
            break;
        }
    } while(choice!=5);

    return 0;
}