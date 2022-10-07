#include<stdio.h>
#include<stdlib.h>
#define SIZE 6

int main()
{
    int array[SIZE] = {0, 1, 2, 3, 4, 5};

    printf("Items of the array:\n");
    for(unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}