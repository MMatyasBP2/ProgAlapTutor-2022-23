#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b);

int main()
{
    int a = 5, b = 10;

    printf("Before swap: a = %d, b = %d.\n\n", a, b);

    swap(&a, &b);

    printf("After swap: a = %d, b = %d.\n\n", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}