#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main()
{
    int array[SIZE];
    for (unsigned int i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("\nItem:\t\tValue:\t\tAddress:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("Array[%d],\t %d\t %p\n", i, *(array + i), array + 1);
    }
    
    // Számcsere

    unsigned int a = 5, b = 20;
    printf("\nValues before swap: a = %d, b = %d\n\n", a, b);

    int tmp;
    int *p, *q;
    p = &a;
    q = &b;

    tmp = *p;
    *p = *q;
    *q = tmp;

    printf("Values after swap: a = %d, b = %d", a, b);
    

    return 0;
}