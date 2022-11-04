#include<stdio.h>
#include<stdlib.h>

#define SIZE 6
#define SEM_CREDIT 30

int main()
{
    int marks[SIZE];
    int credits[SIZE];

    printf("Enter marks:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. mark: ", i + 1);
        scanf("%d", &marks[i]);
    }
    
    printf("\nEnter credits:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. credit: ", i + 1);
        scanf("%d", &credits[i]);
    }
    
    // Kiiratás táblázatos formátumban:

    printf("\nMark:\tCredit:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
       printf("%d\t%d\n", marks[i], credits[i]);
    }
    
    // Súlyozott átlagszámítás

    float sum = 0;
    for (unsigned int i = 0; i < SIZE; i++)
    {
        sum += marks[i] * credits[i];
    }
    
    sum /= SEM_CREDIT;

    printf("Weighted average = %.2f\n", sum);

    // Ösztöndíj kalkulátor


    if (sum < 3.3)
    {
        printf("You haven't earned scholarship.");
    }
    else if(sum < 3.6)
    {
        printf("You've earned 15.500-.Huf scholarship");
    }
    else if(sum < 3.9)
    {
        printf("You've earned 17.500-.Huf scholarship");
    }
    else if(sum < 4.2)
    {
        printf("You've earned 20.500-.Huf scholarship");
    }
    else if(sum < 4.5)
    {
        printf("You've earned 25.500-.Huf scholarship");
    }
    else if(sum < 4.8)
    {
        printf("You've earned 30.500-.Huf scholarship");
    }
    else if(sum < 5.0)
    {
        printf("You've earned 40.000-.Huf scholarship");
    }
    else if(sum == 5.0)
    {
        printf("You've earned 50.000-.Huf scholarship");
    }

    return 0;
}