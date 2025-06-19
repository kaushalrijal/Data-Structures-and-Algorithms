#include<iostream>

#define ARR_SIZE 10

using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

void BubbleSort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
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
    BubbleSort(a, ARR_SIZE);
    printArray(a, ARR_SIZE);
    
}