#ifndef ZH_H_INCLUDED
#define ZH_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void fillarray(double *array, const unsigned int size);
void printarray(double *array, const unsigned int size);
unsigned int getnewsize(double *array);
void choose(double *array, double *newarray);
unsigned int minarray(double *array, const unsigned int size);
void readinterval(int *lower, int *upper);
float calcavg(int lower, int upper, double *array, const unsigned int size);

#endif