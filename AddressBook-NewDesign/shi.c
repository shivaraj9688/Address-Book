#include<stdio.h>
int main(){
    int n1;
    volatile int n2=1;
    n1=++n2 + n2++ + n2++ + n2++;
    printf("%d",n1);
    return 0;
}