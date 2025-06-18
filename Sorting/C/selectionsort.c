#include<stdio.h>

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int smallest = a[i];
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < smallest){
                smallest = a[j];
                pos = j;
            }
        }
        if(i != pos){
            swap(&a[i], &a[pos]);
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
    SelectionSort(a, sizeof(a)/sizeof(a[0]));
    printArray(a, sizeof(a)/sizeof(a[0]));

    return 0;
}