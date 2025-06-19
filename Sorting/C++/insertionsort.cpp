#include<iostream>

#define ARR_SIZE 10

using namespace std;


void InsertionSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        int j=i-1;
        int temp = a[i];

        while(j>=0 && temp<a[j]){
            a[j+1] = a[j];
            j = j-1;
        }

        a[j+1] = temp;
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
    InsertionSort(a, ARR_SIZE);
    printArray(a, ARR_SIZE);
    
}