#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    int b;
    int c;

    printf("Give me the three sides of the rectangle = ");
    scanf("%d,%d,%d", &a, &b, &c);

    printf("Sides are = a = %d, b = %d, c = %d", a, b, c);

    printf("\nA = %d\n", 2 * (a * b + a * c + b * c));
    printf("V = %d\n\n", a * b * c);

    int A = 2 * (a * b + a * c + b * c);
    int V = a * b * c;

    printf("A with variable = %d\n", A);
    printf("V with variable = %d", V);

    return 0;
}