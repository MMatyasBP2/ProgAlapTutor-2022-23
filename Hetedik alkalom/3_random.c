#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10

void fillarr(unsigned int lower, unsigned int upper, unsigned int *array, const unsigned int size);
void printarr(unsigned int *array, const unsigned int size);
void printreverse(unsigned int *array, const unsigned int size);

int main()
{
    printf("Let's fill the array with random numbers!\n");
    unsigned int array[SIZE];
    fillarr(1, 10, array, SIZE);
    printf("Item:\t\tValue:\n");
    printarr(array, SIZE);

    printf("Reversed random array:\n");
    printf("Item:\t\tValue:\n");
    printreverse(array, SIZE);
    return 0;
}

void fillarr(unsigned int lower, unsigned int upper, unsigned int *array, const unsigned int size)
{
    srand(time(0));
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = rand() % (upper - lower + 1) + lower;
    }
}

void printarr(unsigned int *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t%u\n", i, array[i]);
    }
}

void printreverse(unsigned int *array, const unsigned int size)
{
    for (int i = size - 1; i > -1; i--)
    {
        printf("%u. item\t\t%u\n", i, array[i]);
    }
}