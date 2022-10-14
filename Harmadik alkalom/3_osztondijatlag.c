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

    printf("Enter credits:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d. crdit: ", i + 1);
        scanf("%d", &credits[i]);
    }
    

    printf("\nMark:\tCredits:\n");
    for (unsigned int i = 0; i < SIZE; i++)
    {
        printf("%d\t%d\n", marks[i], credits[i]);
    }

    // Sulyozott

    float sum = 0;
    for (unsigned int i = 0; i < SIZE; i++)
    {
        sum += marks[i] * credits[i];
    }
    
    sum /= SEM_CREDIT;

    printf("Weighted avarage = %.2lf", sum);

    // Osztondij kalkulator

    if (sum < 3.3)
    {
        printf("You've not earned scholarship.");
    }
    else if(sum < 3.6)
    {
        printf("You've earned 15.500-. HUF scholarship.");
    }
    else if(sum < 3.9)
    {
        printf("You've earned 17.500-. HUF scholarship.");
    }
    else if(sum < 4.2)
    {
        printf("You've earned 20.500-. HUF scholarship.");
    }
    else if(sum < 4.5)
    {
        printf("You've earned 25.500-. HUF scholarship.");
    }
    else if(sum < 4.8)
    {
        printf("You've earned 30.000-. HUF scholarship.");
    }
    else if(sum < 5.0)
    {
        printf("You've earned 40.000-. HUF scholarship.");
    }
    else if(sum == 5.0)
    {
        printf("You've earned 45.500-. HUF scholarship.");
    }
    

    return 0;
}