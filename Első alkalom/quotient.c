#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number1, number2;
    printf("Give me two numbers = ");
    scanf("%d,%d", &number1, &number2);

    double quotient;
    quotient = number1 / number2;
    printf("Quotient is = %lf\n", quotient);
    
    if (quotient > 5)
    {
        printf("My number is bigger than 5.\n");
    }
    else
    {
        printf("My number is bigger than 5.\n");
    }

    printf("My number is %s than 5", quotient >= 5 ? "bigger" : "less");
    

    return 0;
}