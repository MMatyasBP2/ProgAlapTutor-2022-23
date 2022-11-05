#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printarray(unsigned int *array, const unsigned int size);
float avg(unsigned int *array, const unsigned int size);
unsigned int count(unsigned int number, unsigned int *array, const unsigned int size);
unsigned int sum(unsigned int *array, const unsigned int size);
bool ismonotone(unsigned int *array, const unsigned int size);

int main()
{
    // Az
    unsigned int Az[] = { 234, 245, 255, 260, 261 };
    const unsigned int sizeAz = sizeof(Az) / sizeof(Az[0]);
    printf("Item:\t\tValue:\n");
    printarray(Az, sizeAz);
    printf("Avg of the company Az is %.2f.\n\n", avg(Az, sizeAz));
    printf("Days when number of products were bigger than 250 in 'Az': %u\n\n\n", count(250, Az, sizeAz));

    // Bez

    unsigned int Bez[] = { 202, 213, 222, 205, 207 };
    const unsigned int sizeBez = sizeof(Az) / sizeof(Az[0]);
    printf("Item:\t\tValue:\n");
    printarray(Bez, sizeBez);

    // Comparing

    printf("Sum of products of 'Az': %u.\n", sum(Az, sizeAz));
    printf("Sum of products of 'Bez': %u.\n", sum(Bez, sizeBez));

    if (sum(Az, sizeAz) > sum(Bez, sizeBez))
    {
        printf("Az was produced more then Bez.\n");
    }
    else
    {
        printf("Bez was produced more then Az.\n");
    }

    printf("Az was produced more: %u\n\n", sum(Az, sizeAz) - sum(Bez, sizeBez));
    
    printf("In case of 'Az' having rest found %s.\n", ismonotone(Az, sizeAz) ? "effective" : "not effective");
    printf("In case of 'Bez' having rest found %s.", ismonotone(Bez, sizeBez) ? "effective" : "not effective");

    return 0;
}

void printarray(unsigned int *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t%u\n", i + 1, array[i]);
    }
}

float avg(unsigned int *array, const unsigned int size)
{
    float avg = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        avg += array[i];
    }
    return avg / (float)size;
}

unsigned int count(unsigned int number, unsigned int *array, const unsigned int size)
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        if (array[i] > number)
        {
            count++;
        }
    }
    return count;
}

unsigned int sum(unsigned int *array, const unsigned int size)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

bool ismonotone(unsigned int *array, const unsigned int size)
{
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i - 1] > array[i])
        {
            return false;
        }
    }
    return true;
}