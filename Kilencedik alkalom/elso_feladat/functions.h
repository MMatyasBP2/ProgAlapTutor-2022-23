#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readu(unsigned int *num);
void read_arr(float *arr, const unsigned int size);
void print_arr(float *arr, const unsigned int size);
int monotone(const float *arr, const unsigned int size);
void is_monotone(const float *arr, const unsigned int size);
unsigned int minarray(const float *arr, const unsigned int size);
unsigned int maxarray(const float *arr, const unsigned int size);
unsigned int minindex(const float *arr, const unsigned int size);
unsigned int maxindex(const float *arr, const unsigned int size);
float avg(const float *arr, const unsigned int size);

#endif