#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int N;
    unsigned long long int factor = 1;
    bool ok;

    do
    {
        ok = true;
        printf("Give me a number = ");
        if (scanf("%d", &N) != 1)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);

    switch (N)
    {
        case 20 : factor *= 20;
        case 19 : factor *= 19;
        case 18 : factor *= 18;
        case 17 : factor *= 17;
        case 16 : factor *= 16;
        case 15 : factor *= 15;
        case 14 : factor *= 14;
        case 13 : factor *= 13;
        case 12 : factor *= 12;
        case 11 : factor *= 11;
        case 10 : factor *= 10;
        case 9 : factor *= 9;
        case 8 : factor *= 8;
        case 7 : factor *= 7;
        case 6 : factor *= 6;
        case 5 : factor *= 5;
        case 4 : factor *= 4;
        case 3 : factor *= 3;
        case 2 : factor *= 2;
        case 1 : factor *= 1;
    }

    printf("Factor = %d", factor);

    return 0;
}