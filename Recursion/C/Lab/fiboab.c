#include<stdio.h>

#define MAX 100

// long table[MAX];

int fibo(int n){
    if(n==0 || n==1)
        return n;
    else{
        
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    int n, fib;
    printf("Term? ");
    scanf("%d", &n);
    fib = fibo(n);
    printf("%dth fibonacci term is %d", n, fib);
    return 0;
}