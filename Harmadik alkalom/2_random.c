/*-1000 és 1000 közé eső véletlenszámokkal töltsön fel egy 20 elemű integer tömböt, majd végezze el
az alábbi feladatokat:*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define SIZE 20

int main()
{
    int array[SIZE];

    for (unsigned int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % (1000 - (-999)) + (-1000));
    }

    // Tömbök kiiratása

    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. item: %d\n", i + 1, array[i]);
    }

    /*Keresse meg az 500-at a tömbben, ha benne van!*/

    bool found = false;
    int search = 500;

    for (unsigned int i = 0; i < SIZE; i++)
    {
        if (search == array[i])
        {
            found = true;
            printf("%u was found at index %u.\n", search, i);
            break;
        }
    }
    if (!found)
    {
        printf("%u is not in the array.\n", search);
    }

    return 0;
}