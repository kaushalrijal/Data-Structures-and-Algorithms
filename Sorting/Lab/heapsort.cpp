#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>

#define MAX 100000

using namespace std;

void max_heapify(int a[], int i, int n){
    int l = 2*i;
    int r = 2*i + 1;
    int largest = i, temp;
    if(l<=n && a[l] > a[largest]){
        largest = l;
    }
    if(r<=n && a[r] > a[largest]){
        largest = r;
    }

    if(i != largest){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
}

void build_max_heap(int a[], int n){
    int i;
    for(int i=n/2; i>=1; i--){
        max_heapify(a, i, n);
    }
}

void heap_sort(int a[], int n){
    build_max_heap(a, n);
    for(int i=n; i>=2; i--){
        int temp = a[1];
        a[1] = a[n];
        a[n] = temp;
        n = n-1;
        max_heapify(a, 1, n);
    }
}

void display(int a[], int n){
    for(int i=1; i<=n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int i, n, arr[MAX];

    srand(time(NULL));
    time_t t1, t2;
    double d;

    cout << "Enter n: ";
    cin >> n;
    for(i=1; i<=n; i++){
        arr[i] = rand()%1000;
    }
    display(arr, n);
    // t1 = time(NULL);
    heap_sort(arr, n);
    // t2 = time(NULL);
    display(arr, n);

    // d = difftime(t2, t1);

    // printf("Total time taken: %lf seconds.\n", d);

    return 0;
}