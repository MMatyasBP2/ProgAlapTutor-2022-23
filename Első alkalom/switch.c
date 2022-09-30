#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int a = 5, b = 10;
    bool bigger = a > b;

    switch (bigger)
    {
    case true: printf("%d is bigger than %d", a, b);
        break;

    case false: printf("%d is bigger than %d", b, a);
        break;
    }
    

    return 0;
}