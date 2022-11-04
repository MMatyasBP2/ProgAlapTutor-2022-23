#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void read_farray(float *array, const size_t size);
void print_farray(const float *array, const size_t size);
bool is_monotone(const float *array, const size_t size);
float avg(const float *array, const size_t size);
void print_avg_diff(const float *array, const size_t size, const float avg);
size_t minindex(const float *array, const size_t size);
size_t maxindex(const float *array, const size_t size);

int main()
{
    const size_t array_size = 12;
    float array[array_size];
    read_farray(array, array_size);
    print_farray(array, array_size);
    if (is_monotone(array, array_size))
    {
        printf("The array is monotone increasing.");
    }
    else
    {
        printf("The array is non-monotone.");
    }
    float avgf = avg(array, array_size);
    printf("\n\nAvarage of the array is %2.f.\n", avgf);

    print_avg_diff(array, array_size, avgf);

    printf("Minimum index = %lu.\n", minindex(array, array_size));
    printf("Maximum index = %lu.", maxindex(array, array_size));

    return 0;
}

void read_farray(float *array, const size_t size)
{
    bool ok;

    for (size_t i = 0; i < size; i++)
    {
        do
        {
            ok = true;
            printf("Element %lu: ", i + 1);
            if (scanf("%f", &array[i]) != 1)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
        } while (!ok);
    }
}

void print_farray(const float *array, const size_t size)
{
    printf("The array:\n");
    for (size_t i = 0; i < size; i++)
    {
        printf("%2.f ", array[i]);
    }
    putchar('\n');
}

bool is_monotone(const float *array, const size_t size)
{
    if (size <= 1)
    {
        return true;
    }

    for (size_t i = 1; i < size; i++)
    {
        if (array[i - 1] > array[i])
        {
            return false;
        }
    }

    return true;
}

float avg(const float *array, const size_t size)
{
    float avg = 0;

    for (size_t i = 0; i < size; i++)
    {
        avg += array[i];
    }
    
    return avg / (float)size;
}

void print_avg_diff(const float *array, const size_t size, const float avg)
{
    printf("Difference from the avarage (%2.f):\n", avg);
    printf("%6s%12s%12s\n", "index", "value", "difference");
    for (size_t i = 0; i < size; i++)
    {
        printf("%6lu%12.2f%12.2f\n", i, array[i], array[i] - avg);
    }
}

size_t minindex(const float *array, const size_t size)
{
    size_t minindex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < array[minindex])
        {
            minindex = i;
        }
    }

    return minindex;
}

size_t maxindex(const float *array, const size_t size)
{
    size_t maxindex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > array[maxindex])
        {
            maxindex = i;
        }
    }

    return maxindex;
}