#include<stdio.h>
#include<stdlib.h>

int main()
{
    int array[5] = {2, 4, 6, 8, 10};
    int sum;

    for (unsigned int i = 0; i < 5; i++)
    {
        sum += array[i];
    }
    
    printf("Sum of the array is = %d", sum);

    return 0;
}