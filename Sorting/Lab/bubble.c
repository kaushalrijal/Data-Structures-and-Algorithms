#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void display(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int i, a[MAX], n;

    srand(time(NULL));
    time_t t1, t2;
    double d;

    printf("Enter n: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        a[i] = rand()%1000;
    }
    display(a, n);
    t1 = time(NULL);
    bubble_sort(a, n);
    t2 = time(NULL);
    display(a, n);

    d = difftime(t2, t1);

    printf("Total time taken: %lf seconds.\n", d);

    return 0;
}