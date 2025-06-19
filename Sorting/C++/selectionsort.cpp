#include<iostream>

#define ARR_SIZE 10

using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

void SelectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int smallest = a[i];
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < smallest){
                smallest = a[j];
                pos=j;
            }
        }
        if(pos != i){
            swap(a[i], a[pos]);
        }
    }
}


void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int a[ARR_SIZE] = {12, 17, 2, -1, 0, 1, 15, 100, 8, 19};

    printArray(a, ARR_SIZE);
    SelectionSort(a, ARR_SIZE);
    printArray(a, ARR_SIZE);
    
}