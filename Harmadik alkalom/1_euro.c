#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define LIMIT 300.0

int main()
{
    double euros[] = { 289.5, 292.6, 290.2, 295.5, 300.4, 302.3, 302.5, 303.3, 303.5, 299.9 };
    int size = sizeof(euros) / sizeof(double);

    // Count

    int count = 0;
    printf("\nHUF/EURO arfolyamok:\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d. ertek: %.2lf\n", i + 1, euros[i]);
        if (euros[i] < LIMIT)
        {
            count++;
        }
    }
    
    printf("\nAz arfolyam erteke %d-szor volt %.2lf alatt.\n", count, LIMIT);
    
    // Monotone

    bool is_monotone = true;
    for (unsigned int i = 1; i < size; i++)
    {
        if (euros[i - 1] > euros[i])
        {
            is_monotone = false;
            break;
        }
    }
    
    printf("A sor %s.\n\n", is_monotone ? "monoton novekvo" : "nem monoton");

    // Minimum, maximum

    int min = euros[0], max = euros[0];

    for (unsigned int i = 1; i < size; i++)
    {
        if (euros[i] < min)
        {
            min = euros[i];
        }
        if (euros[i] > max)
        {
            max = euros[i];
        }
    }

    printf("Minimum ertek = %d\n", min);
    printf("Maximum ertek = %d\n\n", max);
    
    // Minimum ertek, maximum ertek

    int min_index = 0, max_index = 0;

    for (unsigned int i = 1; i < size; i++)
    {
        if (euros[i] < euros[min_index])
        {
            min_index = i;
        }
        if (euros[i] > euros[max_index])
        {
            max_index = i;
        }
    }
    
    printf("Minimum hely ertek = %d\n", min_index);
    printf("Maximum hely ertek = %d\n\n", max_index);

    // Átlag

    float avg = 0;
    for (unsigned int i = 0; i < size; i++)
    {
        avg += euros[i];
    }
    avg /= size;
    printf("Atlag kerekitve = %f\n\n", ceil(avg));

    // Átlagtól való eltérés

    printf("Sorszam\tAtlag\tAtlagtol valo elteres\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d.\t%.2f\t%.2f\n", i + 1, euros[i], euros[i] - avg);
    }

    return 0;
}