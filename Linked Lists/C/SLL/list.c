#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main(){
    SLL list = {NULL, NULL};
    int ch, elem, pos;

    do{
        system("clear");
        printf("1)Insert at Beginning\n");
        printf("2)Insert at End\n");
        printf("3)Insert at Position\n");
        printf("4)Delete at Beginning\n");
        printf("5)Delete at End\n");
        printf("6)Delete at Position\n");
        printf("7)Search\n");
        printf("8)Display\n");
        printf("9)Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertAtBeg(&list, elem);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                insertAtEnd(&list, elem);
                break;
            case 3:
                printf("Enter the element to insert and the position to insert in: ");
                scanf("%d %d", &elem, &pos);
                insertAtPos(&list, elem, pos);
                break;
            case 4:
                deleteAtBeg(&list);
                break;
            case 5:
                deleteAtEnd(&list);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &pos);
                deleteAtPos(&list, pos);
                break;
            case 7:
                printf("Enter the key to search: ");
                scanf("%d", &elem);
                search(&list, elem);
                break;
            case 8:
                display(&list);
                break;
            case 9:
                break;
            default:
                printf("Invalid choice!");
        }
        printf("Press any key to continue...");
        getchar();
        getchar();
    } while(ch!=9);

    release(&list);
    return 0;
}
