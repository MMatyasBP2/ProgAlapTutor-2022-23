#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ARR_SIZE 6

int main()
{
    int array[ARR_SIZE] = {1, 2, 1, 6, 8, 12};
    int reverse_array[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
    {
        reverse_array[i] = array[ARR_SIZE - 1 - i];
    }

    printf("index\tarray\treverse\n");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%5d\t%5d\t%7d\n", i, array[i], reverse_array[i]);
    }

    // Monotone 
    
    bool is_monotone = true;
    for (unsigned int i = 1; i < ARR_SIZE; i++)
    {
        if (array[i - 1] > array[i])
        {
            is_monotone = false;
            break;
        }
    }

    printf("The array is %s.\n", is_monotone ? "monotone increasing" : "non monotone");

    return 0;
}