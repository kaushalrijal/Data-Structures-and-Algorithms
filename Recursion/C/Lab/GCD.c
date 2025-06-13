#include<stdio.h>

int GCD(int a, int b){
    if(b==a)
        return a;
    else if (a>b){
        return GCD(a-b, b);
    } else {
        return GCD(a, b-a);
    }
}

int main(){
    int a, b, hcf;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    hcf = GCD(a, b);
    printf("GCD: %d\n", hcf);
    return 0;
}