#include "functions.h"

void readu(unsigned int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me the size: ");
        if (scanf("%u", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}

void read_arr(float *arr, const unsigned int size)
{
    bool ok;
    for (unsigned int i = 0; i < size; i++)
    {
        do
        {
            ok = true;
            printf("Give me a number: ");
            if (scanf("%f", &arr[i]) != 1)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
        } while (!ok);
    }
}

void print_arr(float *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item \t\t %.2f\n", i + 1, arr[i]);
    }
}

int monotone(const float *arr, const unsigned int size)
{
    bool is_monotone_increasing = true;

    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            is_monotone_increasing = false;
        }
    }
    
    bool is_monotone_decreasing = true;

    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            is_monotone_decreasing = false;
        }
    }

    if (is_monotone_increasing)
    {
        return 1;
    }
    else if (is_monotone_decreasing)
    {
        return 2;
    }

    return 0;
}

void is_monotone(const float *arr, const unsigned int size)
{
    switch (monotone(arr, size))
    {
    case 1: printf("Sequence is monotone increasing.\n");
        break;
    
    case 2: printf("Sequence is monotone decreasing.\n");
        break;

    default: printf("Sequence is non-monotone.\n");
        break;
    }
}

unsigned int minarray(const float *arr, const unsigned int size)
{
    unsigned int min = arr[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[min] < min)
        {
            min = arr[i];
        }
    }
    
    return min;
}

unsigned int maxarray(const float *arr, const unsigned int size)
{
    unsigned int max = arr[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[max] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}

unsigned int minindex(const float *arr, const unsigned int size)
{
    unsigned int minindex = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minindex])
        {
            minindex = i;
        }
    }

    return minindex;
}

unsigned int maxindex(const float *arr, const unsigned int size)
{
    unsigned int maxindex = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] > arr[maxindex])
        {
            maxindex = i;
        }
    }
    
    return maxindex;
}

float avg(const float *arr, const unsigned int size)
{
    float avg = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        avg /= arr[i];
    }
    return avg;
}