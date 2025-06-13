#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node* createNode(int element){
    node* NewNode;
    NewNode = (node*) malloc(sizeof(node));

    if(NewNode == NULL)
        perror("Error allocating memory\n");

    NewNode->data=element;
    NewNode->next=NULL;

    return NewNode;
}

void insertAtBeg(SLL* list, int element){

    node* NewNode = createNode(element);

    if(list->first == NULL){ // list is empty
        list->first = list->last = NewNode;
    } else {
        NewNode->next = list->first;
        list->first = NewNode;
        printf("SUCCESFULLY INSERTED %d AT THE BEGINNING\n", element);
    }
}

void insertAtEnd(SLL* list, int element){

    node* NewNode = createNode(element);

    if(list->first==NULL){// empty list
        list->first = list->last = NewNode;    
    } else {
        list->last->next = NewNode;
        list->last = NewNode;
        printf("SUCCESFULLY INSERTED %d AT THE END\n", element);
    }
}

void insertAtPos(SLL* list, int element, int pos){

    if(list->first == NULL){ // list is empty
        insertAtBeg(list, element);
    } else {
        node* NewNode = createNode(element);
        node* temp = list->first;
        for(int i=1; i<pos-1; ++i){
            if(temp==NULL){
                printf("INVALID POS VALUE!\n");
                return;
            }
            temp = temp->next;
        }
        NewNode->next = temp->next;
        temp->next = NewNode;
    }
}
void deleteAtBeg(SLL* list){

    if(list->first == NULL){ // list is empty
        printf("NOTHING TO DELETE, LIST IS EMPTY!\n");
    } else if(list->first == list->last){ // only one element
        node* temp = list->first;
        list->first = list->last = NULL;
        free(temp);
    } else { // multiple elements
        node* temp = list->first;
        list->first = list->first->next;
        free(temp);
        printf("DELETED FROM THE BEGINNING SUCCESFULLY!\n");
    }
}
void deleteAtEnd(SLL* list){
    if(list->first == NULL){ // list is empty
        printf("NOTHING TO DELETE, LIST IS EMPTY!\n");
    } else if(list->first == list->last){ // only one element
        node* temp = list->first;
        list->first = list->last = NULL;
        free(temp);
        printf("DELETED FROM END SUCCESFULFULLY!\n");
    } else { // multiple elements
        node* temp = list->first;
        while(temp->next != list->last){
            temp = temp->next;
        }
        list->last = temp;
        temp = list->last->next;
        free(temp);
        list->last->next = NULL;
        printf("DELETED FROM END SUCCESFULFULLY!\n");
    }
}
void deleteAtPos(SLL* list,  int pos){

    if(list->first == NULL){
        printf("NOTHING TO DELETE, LIST IS EMPTY!\n");
    } else if (pos==1){
        deleteAtBeg(list);
    } else {
        node *temp, *tempp;
        temp = list->first;
        for(int i=0; i<pos-1; i++){
            if(temp==NULL){
                printf("INVALID POS!\n");
                break;
            }
            temp = temp->next;
        }
        if(temp->next == NULL){
            deleteAtEnd(list);
        } else {
            tempp = temp->next;
            temp->next = tempp->next;
            free(tempp);
            printf("DELETED AT POSITION %d SUCCESFULLY!\n", pos);
        }
    }
}
void search(SLL* list, int key){
    int flag=0, index=1;

    
    if(list->first == NULL){
        printf("LIST IS EMPTY!\n");
        return;
    }
    
    node* temp = list->first;
    while(temp!=NULL){
        if(temp->data == key){
            printf("KEY %d FOUND AT INDEX %d\n", key, index);
            flag = 1;
        }
        temp = temp->next;
        ++index;
    }

    if(!flag){
        printf("KEY NOT FOUND!\n");
    }

}
void display(SLL* list){

    if(list->first == NULL){
        printf("LIST IS EMPTY, NOTHING TO DISPLAY\n");
        return;
    }

    node *temp;
    temp = list->first;
    
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void release(SLL* list){
    node *temp, *i;
    temp = list->first;
    while(temp!=NULL){
        i = temp;
        temp = temp->next;
        free(i);
    }
    list->first = list->last = NULL;
    printf("FREED LIST COMPLETELY!\n");
}