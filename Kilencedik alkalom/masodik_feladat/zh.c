#include "zh.h"

#define SIZE 10

void fillarray(double *array, const unsigned int size)
{
    srand(time(0));
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = rand() % (105 - 96) + 95;
    }
}

void printarray(double *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t\t%.2lf\n", i + 1, array[i]);
    }
}

unsigned int getnewsize(double *array)
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < SIZE; i++)
    {
        if (array[i] >= 100)
        {
            count++;
        }
    }

    return count;
}

void choose(double *array, double *newarray)
{
    unsigned int j = 0;
    for (unsigned int i = 0; i < SIZE; i++)
    {
        if (array[i] >= 100)
        {
            newarray[j] = array[i];
            j++;
        }
    }
}

unsigned int minarray(double *array, const unsigned int size)
{
    unsigned int min = array[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[min] < min)
        {
            min = array[i];
        }
    }
    
    return min;
}

void readinterval(int *lower, int *upper)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me an interval: ");
        if (scanf("%d,%d", lower, upper) != 2)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (*lower < 95 || *upper > 105)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (*upper < *lower)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}

float calcavg(int lower, int upper, double *array, const unsigned int size)
{
    float avg = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        if (array[i] > lower && array[i] < upper)
        {
            avg += array[i];
        }
    }
    return avg / size;
}