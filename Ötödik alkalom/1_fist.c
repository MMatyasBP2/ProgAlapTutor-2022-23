#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int readint();
int factorial(int num);

int main()
{
    int num = readint();
    printf("Number = %d.\n", num);
    printf("Factorial of the number (%d) is %d.", num, factorial(num));  
    return 0;
}

int readint()
{
    int num;
    bool ok;
    do
    {
        ok = true;
        printf("Give me a number: ");
        if (scanf("%d", &num) != 1)
        {
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);

    return num;
}

int factorial(int num)
{
    int fact = 1;

    for (int i = 2; i <= num; i++)
    {
        fact *= i;
    }
    
    return fact;
}