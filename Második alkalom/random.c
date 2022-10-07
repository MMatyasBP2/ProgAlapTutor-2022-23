#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int main()
{
    int lower, upper;
    bool ok;

    do
    {
        ok = true;
        printf("Give me the lower and the upper number: ");
        if (scanf("%d,%d", &lower, &upper) != 2)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        } else if(upper < lower)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    printf("[%d, %d]\n", lower, upper);

    srand(time(0));

    int random = (rand() % (upper - lower + 1) + lower);

    printf("My random is: %d", random);

    return 0;
}