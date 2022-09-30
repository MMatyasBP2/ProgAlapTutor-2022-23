#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int lower, upper;
    bool ok;

    do
    {
        ok = true;
        printf("Give me the lower and the upper number of an interval = ");
        if (scanf("%d,%d", &lower, &upper) != 2)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (upper < lower )
        {
            printf("Wrong input! Upper number must be bigger! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    printf("Interval = [%d, %d]\n", lower, upper);

    return 0;
}