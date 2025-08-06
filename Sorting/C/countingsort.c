#include<stdio.h>


void countingSort(int arr[], int n, int base){
    int out[n];
    int count[10] = {0};

    for(int j=0; j<n; j++){
        count[(arr[j]/base)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int j=n-1; j>=0; j--){
        int digit = (arr[j]/base)%10;
        out[count[digit]-1] = arr[j];
        count[digit]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = out[i];
    }
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {11, 10, 122, 148, 37, 43, 29, 54, 45, 76};
    countingSort(arr, 10, 1);
    print(arr, 10);

    return 0;
}