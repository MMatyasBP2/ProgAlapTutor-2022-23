#ifndef TTIFUNC_H_INCLUDED
#define TTIFUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define STR_BUF 255

typedef struct TT_details
{
    unsigned int size;
    double *TT;
} TT_details;

void fill_arr(double *arr, const unsigned int size);
void printf_arr(double *arr, const unsigned int size);
void tti(double *height, double *weight, const unsigned int size, double *tti);
void max_sort(const unsigned int size, double *TTI);
void read_str(char *string);
void tti_type(double *tti, const unsigned int size);
TT_details *TT_system(const unsigned int size, double *TTI, char *string);
void file_write(TT_details *TT_all);

#endif