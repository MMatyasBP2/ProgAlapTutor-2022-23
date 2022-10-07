#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SIZE 5

int main()
{
    int lower, upper;
    bool ok;
    do
    {
        ok = true;
        printf("Gimme the lower and the upper: ");
        if (scanf("%d,%d", &lower, &upper) != 2)
        {
            printf("SZAR\n");
            ok = false;
            while((getchar()) != '\n');
        } else if (upper < lower)
        {
            printf("SZAR\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    srand(time(0));

    int array[SIZE];

    for (unsigned int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % (upper - lower + 1) + lower);
        printf("\t%d. number: %d\n", i + 1, array[i]);
    }
    

    return 0;
}