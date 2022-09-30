#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number = -45;
    float myfloat = 3.5;
    double mydouble = 100.3333;
    char mychar = 'M';

    printf("My number is = %d\n", number);
    printf("My float is = %.2f\n", myfloat);
    printf("My double is = %.2lf\n", mydouble);
    printf("My char is = %c\n\t", mychar);
    printf("My name is = %s\n", "Martinak Matyas");

    printf("\nMy number with double value = %.3lf", (double)number);

    return 0;
}