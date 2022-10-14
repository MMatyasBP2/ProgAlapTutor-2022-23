#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ARR_SIZE 10

int main()
{
    int array[ARR_SIZE];

    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d. element: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    printf("\nIndex:\t\tValue:\n");
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d. element:\t%d\n", i + 1, array[i]);
    }
    

    int key;
    bool ok;
    do
    {
        ok = true;
        printf("Give me a key to search: ");
        if (scanf("%d", &key) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);

    // Search
    
    unsigned int first = 0;
    unsigned int last = ARR_SIZE - 1;
    unsigned int middle = (first + last) / 2;

    while(first <= last)
    {
        if (array[middle] < key)
        {
            last = middle - 1;
        }
        else if(array[middle] == key)
        {
            printf("%u was found at the index %u.\n", key, middle);
            break;
        }
        else
        {
            first = middle + 1;
        }
        middle = (first + last) / 2;
    }

    if (first > last)
    {
        printf("%u is not in the array.\n", key);
    }
    
    // Minimum, maximum, min_index, max_index

    int min = array[0], max = array[0];

    for (unsigned int i = 1; i < ARR_SIZE; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[max];
        }
    }
    
    int min_index = 0, max_index = 0;

    for (unsigned int i = 1; i < ARR_SIZE; i++)
    {
        if (array[i] < array[min_index])
        {
            min_index = i;
        }
        if (array[i] > array[max_index])
        {
            max_index = i;
        }
    }
    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n\n", max);

    printf("Minimum index: %d\n", min_index);
    printf("Maximum index: %d\n\n", max_index);

    // Monotoning

    bool is_monotone = true;

    for (unsigned int i = 1; i < ARR_SIZE; i++)
    {
        if (array[i - 1] > array[i])
        {
            is_monotone = false;
            break;
        }
    }

    printf("Array is %s.\n", is_monotone ? "monotone" : "non-monotone.");
    

    return 0;
}