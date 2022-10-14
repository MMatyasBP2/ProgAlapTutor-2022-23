#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    unsigned int array[] = { 11260, 9850, 9125, 6630, 5890, 5385,
                             4650, 3030, 2860, 2665 };

    const unsigned int size = sizeof(array) / sizeof(array[0]);
    const unsigned int key = 4650;

    // Linear search

    bool found = false;
    for (unsigned int i = 0; i < size; i++)
    {
        if (key == array[i])
        {
            found = true;
            printf("%u was found at index %u.\n", key, i);
            break;
        }
    }

    if (!found)
    {
        printf("%u was not found in the array.\n", key);
    }

    // Binary search

    unsigned int first = 0;
    unsigned int last = size - 1;
    unsigned int middle = (first + last) / 2;
    
    while(first <= last)
    {
        if (array[middle] < key)
        {
            last = middle - 1;
        }
        else if(array[middle] == key)
        {
            printf("%u was found at index %u.\n", key, middle);
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
    

    return 0;
}