#include<stdio.h>

#define MAX 100

long table[MAX];

int fibo(int n){
    if(n==0 || n==1)
        return n;
    else{
        if(table[n] == -1){
            table[n] = fibo(n-1) + fibo(n-2);
        }
        return table[n];
    }
}

int main(){
    int n, fib;
    for(int i=0; i<MAX; i++){
        table[i] = -1;
    }
    printf("Term? ");
    scanf("%d", &n);
    fib = fibo(n);
    printf("%dth fibonacci term is %d", n, fib);
    return 0;
}