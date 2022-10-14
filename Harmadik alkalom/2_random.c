#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define SIZE 20

int main()
{
    int array[SIZE];

    srand(time(NULL));

    for (unsigned int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % (1000 - (-999)) + (-1000));    
    }
    
    printf("Index\tItem\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d\t%d\n", i + 1, array[i]);
    }
    
    // Kereses

    bool found = false;
    const unsigned int key = 500;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        if (key == array[i])
        {
            found = true;
            printf("%u was found at index of %u.\n", key, i + 1);
            break;
        }
    }

    if (!found)
    {
       printf("%u was not found in the array!", key);
    }

    return 0;
}