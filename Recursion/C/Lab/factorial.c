#include<stdio.h>

long int tailFact(int n, long int a){
    if(n == 0){
        return a;
    } else {
        return tailFact(n-1, a*n);
    }
}

int main(){
    int n;
    printf("Number? ");
    scanf("%d", &n);
    printf("Factorial = %ld\n", tailFact(n, 1));

    return 0;
}