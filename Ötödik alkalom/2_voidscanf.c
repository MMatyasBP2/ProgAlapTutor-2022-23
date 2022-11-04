#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readint(int *num);
void readinterval(int *lower, int *upper);

int main()
{
    // Number readint
    int number;
    readint(&number);

    printf("Number = %d.\n", number);

    // Read interval

    int lower, upper;
    readinterval(&lower, &upper);

    printf("Interval = [%d, %d].", lower, upper);

    return 0;
}

void readint(int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Gimme a number: ");
        if (scanf("%d", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}

void readinterval(int *lower, int *upper)
{
    bool ok;

    do
    {
        ok = true;
        printf("Give me an interval: ");
        if (scanf("%d,%d", lower, upper) != 2)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if(*upper < *lower)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}