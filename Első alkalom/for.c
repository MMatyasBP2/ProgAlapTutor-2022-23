#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("\tSzorzotabla:\n");

    int i, j;
    for (int i = 1; j <= 10 ; j++)
    {
        printf("\n%5d", j);
        for (i = 1; i <= 10; i++)
        {
            printf("%3d", i * j);
        }
        
    }
    
    
    return 0;
}