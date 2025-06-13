#include<iostream>
#include "LinkedList.hpp"

using namespace std;

Node* SLL::createNode(int element){
    Node* NewNode = new Node(element);
    return NewNode;
}

void SLL::insertAtBeg(int element){
    Node* NewNode = createNode(element);
    if(first==nullptr) {// list i empty
        first = last = NewNode;
    } else {
        NewNode->next = first;
        first = NewNode;
        cout << "ITEM INSERTED SUCCESFULLY!" << endl;
    }
}

void SLL::insertAtEnd(int element){
    if(first == nullptr){
        insertAtBeg(element);
    } else {
        Node* NewNode = createNode(element);
        last->next = NewNode;
        last = NewNode;
        cout << "ITEM INSERTED SUCCESFULLY!" << endl;
    }
}

void SLL::insertAtPos(int element, int pos){
    if(first == nullptr){
        insertAtBeg(element);
    } else {
        Node* NewNode = createNode(element);
        Node* temp = first;
        for(int i=0; i<pos-1; i++){ 
            if(temp == nullptr){
                cout << "POSITION OUT OF BOUNDS" << endl;
                return;
            }
            temp = temp->next;
        }
        
        NewNode->next = temp->next;
        temp->next = NewNode;
        cout << "ITEM INSERTED SUCCESFULLY!" << endl;
    }
}

void SLL::deleteAtBeg(){

    if(first == nullptr){ // list is empty
        cout << "NOTHING TO DELETE, LIST IS EMPTY!" << endl;
    } else if(first == last){ // only one element
        Node* temp = first;
        first = last = nullptr;
        delete temp;
    } else { // multiple elements
        Node* temp = first;
        first = first->next;
        delete temp;
        cout << "DELETED FROM THE BEGINNING SUCCESFULLY!" << endl;
    }
}
void SLL::deleteAtEnd(){
    if(first == nullptr){ // list is empty
        cout << "NOTHING TO DELETE, LIST IS EMPTY!" << endl;
    } else if(first == last){ // only one element
        Node* temp = first;
        first = last = nullptr;
        delete temp;
        cout << "DELETED FROM END SUCCESFULFULLY!" << endl;
    } else { // multiple elements
        Node* temp = first;
        while(temp->next != last){
            temp = temp->next;
        }
        last = temp;
        temp = last->next;
        delete temp;
        last->next = nullptr;
        cout << "DELETED FROM END SUCCESFULFULLY!" << endl;
    }
}
void SLL::deleteAtPos(int pos){

    if(first == nullptr){
        cout << "NOTHING TO DELETE, LIST IS EMPTY!" << endl;
    } else if (pos==1){
        deleteAtBeg();
    } else {
        Node *temp, *tempp;
        temp = first;
        for(int i=0; i<pos-1; i++){
            if(temp==nullptr){
                cout << "INVALID POS!" << endl;
                break;
            }
            temp = temp->next;
        }
        if(temp->next == nullptr){
            deleteAtEnd();
        } else {
            tempp = temp->next;
            temp->next = tempp->next;
            delete tempp;
            cout << "DELETED AT POSITION " << pos << " SUCCESFULLY!" << endl;
        }
    }
}
void SLL::search(int key){
    int flag=0, index=1;
    if(first == nullptr){
       cout << "LIST IS EMPTY!" << endl;
        return;
    }
    
    Node* temp = first;
    while(temp!=nullptr){
        if(temp->data == key){
           cout << "KEY " << key << " FOUND AT INDEX" << index << endl;
            flag = 1;
        }
        temp = temp->next;
        ++index;
    }

    if(!flag){
       cout << "KEY NOT FOUND!" << endl;
    }

}
void SLL::display(){

    if(first == nullptr){
       cout << "LIST IS EMPTY, NOTHING TO DISPLAY" << endl;
        return;
    }

    Node *temp;
    temp = first;
    
    while(temp != nullptr){
       cout << temp->data << " -> ";
        temp = temp->next;
    }
   cout << "nullptr" << endl;
}

SLL::~SLL(){
    Node *temp, *i;
    temp = first;
    while(temp!=nullptr){
        i = temp;
        temp = temp->next;
        delete i;
    }
    first = last = nullptr;
   cout << "FREED LIST COMPLETELY!" << endl;
}
