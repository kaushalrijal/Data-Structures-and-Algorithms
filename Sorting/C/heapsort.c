#include<stdio.h>
#include<math.h>

#define left(x) (2*(x))
#define right(x) (2*(x) + 1)

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MAX_HEAPIFY(int a[], int i, int n){
    int l = left(i);
    int r = right(i);

    int largest = i;

    if(l<=n && a[l] > a[largest]){
        largest = l;
    }
    if(r<=n && a[r] > a[largest]){
        largest = r;
    }

    if(largest!=i){
        swap(&a[i], &a[largest]);
        MAX_HEAPIFY(a, largest, n);
    }
}

void BUILD_HEAP(int a[], int n){
    int k = floor((float)n/2);
    for(int i=k; i>=1; i--){
        MAX_HEAPIFY(a, i, n);
    }
}

void HEAP_SORT(int a[], int n){
    BUILD_HEAP(a, n);
    for(int i=n; i>=2; i--){
        swap(&a[1], &a[n]);
        n--;
        MAX_HEAPIFY(a, i, n);
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

    int size = sizeof(a)/sizeof(a[0]);

    printArray(a, size);
    HEAP_SORT(a, size-1);
    printArray(a, size);

    return 0;
}