#include<stdio.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(a[j] > a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void printArray(int a[], int size){
    for (int i=0; i<size; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int a[] = {4, 3, 7, 1, 5, 8, 2, 6, 10, 9};

    printArray(a, sizeof(a)/sizeof(a[0]));
    BubbleSort(a, sizeof(a)/sizeof(a[0]));
    printArray(a, sizeof(a)/sizeof(a[0]));

    return 0;
}