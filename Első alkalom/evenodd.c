#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, b;
    scanf("%d,%d", &a, &b);
    printf("A is %s", a % 2 == 0 ? "even.\n" : "odd.\n");
    printf("B is %s", b % 2 == 0 ? "even.\n" : "odd.\n");
    return 0;
}