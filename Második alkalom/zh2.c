#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define ARR_SIZE 6

int main()
{
    unsigned int square_nums[ARR_SIZE];

    printf("index\tnumber\n");
    for (unsigned int i = 0; i < ARR_SIZE; i++)
    {
       square_nums[i] = (unsigned int)pow(i + 1, 2);
       printf("%5u\t%6u\n", i + 1, square_nums[i]);
    }
    
    float avg = 0;
    for (int i = 0; i < ARR_SIZE; i++)
    {
        avg += (float)square_nums[i];
    }
    avg /= (float)ARR_SIZE;

    printf("AVG is: %.2f", avg);
    

    return 0;
}