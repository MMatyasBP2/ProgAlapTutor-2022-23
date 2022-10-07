#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10

int main()
{
    int i, j, jelolt;
    int lotto[SIZE];
    
    srand(time(0));

    for (i = 0; i < SIZE; )
    {
        jelolt = rand() % 90 + 1;

        for (j = 0; j < i; j++)
        {
            if(lotto[j] == jelolt)
            {   
                break;
            }
        }
            if(j == i)
            {   
                lotto[i] = jelolt;
                i++;
            }
        
        for  (i = 0; i < SIZE; i++)
        {
            printf("\n%d. number: %d\n", i + 1, lotto[i]);
        }
        

    }
    

    return 0;
}