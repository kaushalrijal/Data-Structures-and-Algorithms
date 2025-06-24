#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int l, int r){
    int x=l, y=r;
    int pivot = a[l];
    while(x<y){
        while(a[x]<=pivot && x <= r){
            x++;
        }
        while(a[y] > pivot){
            y--;
        }
        if(x < y){
            swap(&a[x], &a[y]);
        }
    }
    swap(&a[l], &a[y]);
    return y;
}

void QuickSort(int a[], int l, int r){
    if (l<r) {
        int p = partition(a, l, r);
        QuickSort(a, l, p-1);
        QuickSort(a, p+1, r);
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
    QuickSort(a, 0, sizeof(a)/sizeof(a[0])-1);
    printArray(a, sizeof(a)/sizeof(a[0]));

    return 0;
}