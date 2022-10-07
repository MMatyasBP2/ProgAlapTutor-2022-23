#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int main()
{
    int array[SIZE];

    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. number: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    printf("\n\tNumbers are:\n");

    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. number: %d\t", i + 1, array[i]);
    }

    // Reverse 

    printf("\n\n");

    for (unsigned int i = SIZE; i >= 0; i--)
    {
        printf("%d. number: %d\t", i + 1, array[i]);
    }
    
    

    return 0;
}