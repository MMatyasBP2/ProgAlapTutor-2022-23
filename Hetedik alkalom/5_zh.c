#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define SIZE 10

void fillarr(unsigned int lower, unsigned int upper, double *array, const unsigned int size);
void printarr(double *array, const unsigned int size);
unsigned int minoverlimit(unsigned int num, double *array, const unsigned int size);
void readinterval(int *lower, int *upper);
void printinterval(int lower, int upper);
double avg(int lower, int upper);

int main()
{
    double array[SIZE];
    fillarr(1, 10, array, SIZE);
    printf("Item:\t\tValue:\n");
    printarr(array, SIZE);
    printf("Minimum over 100: %u.\n\n", minoverlimit(100, array, SIZE));

    int lower, upper;
    readinterval(&lower, &upper);
    printinterval(lower, upper);
    printf("\nAvg of interval: %.2lf.", avg(lower, upper));
}

void fillarr(unsigned int lower, unsigned int upper, double *array, const unsigned int size)
{
    srand(time(0));
    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = (double)(rand() % (upper - lower + 1) + lower);
    }
}

void printarr(double *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t%.2lf\n", i, array[i]);
    }
}

unsigned int minoverlimit(unsigned int num, double *array, const unsigned int size)
{
    unsigned int minindex = size;
    for (unsigned int i = 0; i < size; i++)
    {
        if (minindex == size && array[i] > num)
        {
            minindex = i;
        }
        if (array[minindex] < array[i] && array[i] > num)
        {
            minindex = i;
        }
    }
    return minindex;
}

void readinterval(int *lower, int *upper)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me an interval: ");
        if (scanf("%d, %d", lower, upper) != 2)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (*upper < *lower)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
}

void printinterval(int lower, int upper)
{
    printf("Interval: [%d - %d].", lower, upper);
}

double avg(int lower, int upper)
{
    return (lower + upper) / 2;
}