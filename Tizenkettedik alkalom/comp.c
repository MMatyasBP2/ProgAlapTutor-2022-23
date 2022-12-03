#include "comp.h"

void fill_arr(double *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        arr[i] = rand() % (8 - 5) + 5;
    }
}

void printf_arr(double *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%.2lf ", arr[i]);
    }
}

void write_results_in_table(double *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. try\n", i + 1);
        printf("%.2lf\n", arr[i]);
    }
}

void write_results_in_file_1(double *arr, const unsigned int size)
{
    FILE *file = fopen("Results1.txt", "wa");
    for (unsigned int i = 0; i < size; i++)
    {
        fprintf(file, "%u. result: %.2lf\n", i + 1, arr[i]);
    }
    fclose(file);
}

void write_results_in_file_2(double *arr, const unsigned int size)
{
    FILE *file = fopen("Results2.txt", "wa");
    for (unsigned int i = 0; i < size; i++)
    {
        fprintf(file, "%u. result: %.2lf\n", i + 1, arr[i]);
    }
    fclose(file);
}

double max_arr(double *arr, const unsigned int size)
{
    double max = arr[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void who_won(double *num_1, double *num_2)
{
    if (*num_1 > *num_2)
    {
        printf("First number is bigger than the second one.\n");
    } else if (*num_1 == *num_2)
    {
        printf("Both of the numbers are equals.\n");
    }
    else
    {
        printf("Second number is bigger than the first one.\n");
    }
}

void readu(unsigned int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me a number which should be 1 or 2: ");
        if (scanf("%u", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
        } else if (*num < 1)
        {
            printf("Bad input format!\n");
            ok = false;
        } else if (*num > 2)
        {
            printf("Bad input format!\n");
            ok = false;
            while (getchar() != '\n');
        }
    } while (!ok);
}

void max_sort(double *arr, const unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                double tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void segment_of_arrays(double *arr_1, double *arr_2, double *resultarr, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        if (arr_1[i] == arr_2[i])
        {
            resultarr[i] = arr_1[i] = arr_2[i];
        }
    }
}