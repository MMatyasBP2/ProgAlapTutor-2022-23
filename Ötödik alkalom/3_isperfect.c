#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readi(int *num);
bool ispefect(int num);

int main()
{
    int input;
    readi(&input);
    printf("Input = %d.\n", input);

    printf("Your number (%d) is %s.", input, ispefect(input) ? "perfect" : "non perfect");

    return 0;
}

void readi(int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me a number: ");
        if (scanf("%d", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}

bool ispefect(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }   
    }
}