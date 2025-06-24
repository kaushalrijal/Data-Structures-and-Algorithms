#include<iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int partition(int a[], int l, int r){
    int x=l, y=r;
    int pivot = a[x];

    while(x < y){
        while(a[x] <= pivot && x <= r){
            x++;
        }
        while(a[y] > pivot){
            y--;
        }

        if(x < y){
            swap(a[x], a[y]);
        }
    }

    swap(a[l], a[y]);
    return y;
}

void QuickSort(int a[], int l, int r){
    if(l<r){
        int p = partition(a, l, r);
        QuickSort(a, l, p-1);
        QuickSort(a, p+1, r);
    }
}

void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int a[] = {12, 17, 2, -1, 0, 1, 15, 100, 8, 19};

    int size = sizeof(a)/sizeof(a[0]);

    printArray(a, size);
    QuickSort(a, 0, size-1);
    printArray(a, size);
    
}