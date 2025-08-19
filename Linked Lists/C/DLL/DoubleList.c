#include<stdio.h>
#include<stdlib.h>

typedef struct DLL{
    int data;
    struct DLL* prev;
    struct DLL* next;
}DLL;



DLL* createNode(int data){
    DLL* node = (DLL*) malloc(sizeof(DLL));
    if(node == NULL){
        perror("Failed to allocate memory");
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insertAtBeg(DLL* list, int data){
    DLL* newNode = createNode(data);
    if(list == NULL){
        list = newNode;
    } else {
        list->prev = newNode;
        newNode->next = list;
        printf("SUCCESFULLY INSERTED %d AT THE BEGINNING!\n", data);
    }
}

void insertAtEnd(DLL* list, int data){
    DLL* newNode = createNode(data);
    if(list == NULL){
        list = newNode;
    } else {
        while(list->next != NULL){
            list = list->next;
        }
        list->next = newNode;
        newNode->prev = list;
        printf("SUCCESFULLY INSERTED %d AT THE END!\n", data);
    }
}

void insertAtPos(DLL* list, int data, int pos){
    DLL* newNode = createNode(data);
    if(list==NULL){
        list = newNode;
    } else {
        DLL* temp = list;
        for(int i=1; i<pos-1; i++){
            if(temp == NULL){
                printf("INVALID POSITION VALUE!\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void traverse(DLL* list){
    while(list->next != NULL){
        printf("%d->", list->data);
        list = list->next;
    }
    printf("%d", list->data);
}

int main(){
    DLL* list=NULL;
    insertAtBeg(list, 1);
    insertAtBeg(list, 2);
    insertAtBeg(list, 3);
    insertAtEnd(list, 4);
    insertAtEnd(list, 5);
    insertAtEnd(list, 6);

    traverse(list);

    return 0;
}