#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void fill_arr(double *arr, const unsigned int size);
void printf_arr(double *arr, const unsigned int size);
void write_results_in_table(double *arr, const unsigned int size);
void write_results_in_file_1(double *arr, const unsigned int size);
void write_results_in_file_2(double *arr, const unsigned int size);
double max_arr(double *arr, const unsigned int size);
void who_won(double *num_1, double *num_2);
void readu(unsigned int *num);
void max_sort(double *arr, const unsigned int size);
void segment_of_arrays(double *arr_1, double *arr_2, double *resultarr, const unsigned int size);

#endif