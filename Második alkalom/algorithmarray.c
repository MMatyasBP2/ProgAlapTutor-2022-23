#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define LENGTH 10

int main()
{
    int array[LENGTH], start, end;
    bool ok;
    do
    {
        ok = true;
        printf("Give me the lower and the upper number: ");
        if (scanf("%d,%d", &start, &end) != 2)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        } else if(end < start)
        {
            printf("Wrong input! Please retry!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    for (unsigned int i = 0; i < LENGTH; i++)
    {
        array[i] = (rand() % (end - start + 1) + start);
        printf("\t%d. number: %d\n", i + 1, array[i]);
    }
    
    // Maximum and minimum

    int max_index = 0, min_index = 0;
    for (int i = 1; i < LENGTH; i++)
    {
        if(array[i] < array[min_index])
        {
            min_index = i;
        }
        if (array[i] > array[max_index])
        {
            max_index = i;
        }
    }
    
    printf("Min index = %d\n", min_index);
    printf("Max index = %d\n\n", max_index);

    printf("Min = %d\n", array[min_index]);
    printf("Max = %d\n\n", array[max_index]);

    int input;

    do
    {
        ok = true;
        printf("\nType a number. Count of those smaller than the input is returned. ");
        if (scanf("%d", &input) != 1)
        {
            ok = false;
            printf("BAD INPUT!\n");
            while((getchar()) != '\n');
        }
        
    } while (!ok);

    int count = 0;
    for (int i = 0; i < LENGTH; i++)
    {
        if (input > array[i])
        {
            count++;
        }
        
    }

    printf("Count: %d\n\n", count);
    
    // Count primes

    int prime_count = 0;
    bool is_prime;
    printf("Primes: ");

    for (int number = start <= 1 ? 2 : start; number <= end; number++)
    {
        is_prime = true;
        for (int j = 2; j <= sqrt(number); j++)
        {
            if (number % j == 0)
            {
                is_prime = false;
                break;
            }
            
        }
        if (is_prime)
        {
            prime_count++;
            printf("%d ", number);
        }
    }
    
    printf("\nPrime counted: %d\n", prime_count);
    

    return 0;
}