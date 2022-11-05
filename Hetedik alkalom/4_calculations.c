#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readu(unsigned int *num);
unsigned long long int sqr(unsigned int num);
double power(double base, double exponent);

int main()
{
    // Square number calculation
    unsigned int number;
    readu(&number);
    printf("Sqr of number is: %u.\n\n", sqr(number));

    printf("Power of 2^5: %.2lf.\n\n", power(2, 5));

    return 0;
}

void readu(unsigned int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me a number: ");
        if (scanf("%u", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
}

unsigned long long int sqr(unsigned int num)
{
    return num * num;
}

double power(double base, double exponent)
{
    double result = 1;
    while(exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}