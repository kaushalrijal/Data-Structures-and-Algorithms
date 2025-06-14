#include<stdio.h>

int counter=0;

void TOH(int n, char source, char dest, char temp){
    if(n==1){
        printf("Move %d from %c to %c\n", n, source, dest);
        ++counter;
        return;
    }
    TOH(n-1, source, temp, dest);
    printf("Move %d from %c to %c\n", n, source, dest);
    TOH(n-1, temp, dest, source);
    ++counter;
}

int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 'a', 'c', 'b');
    printf("Total no. of counts: %d\n", counter);
    return 0;
}