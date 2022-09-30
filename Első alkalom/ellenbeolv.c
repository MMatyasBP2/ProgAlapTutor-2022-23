#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int main()
{
    int a, b;
    bool ok;
    do
    {
        ok = true;
        printf("Give me two numbers = ");
        if (scanf("%d,%d", &a, &b) != 2)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    printf("Metani kozep = %.2lf\n", sqrt(a * b));
    printf("Szamtani kozep = %.2lf", (a + b) / 2);

    return 0;
}