#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readrc(int *row, int *column);

int main() 
{
    int a[10][10], transpose[10][10], r, c;
    readrc(&r, &c);

    // asssigning elements to the matrix
    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    // printing the matrix a[][]
    printf("\nEntered matrix: \n");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            printf("%d  ", a[i][j]);
            if (j == c - 1)
                printf("\n");
        }

    // computing the transpose
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
        {
            transpose[j][i] = a[i][j];
        }

    // printing the transpose
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < r; ++j)
        {
            printf("%d  ", transpose[i][j]);
            if (j == r - 1)
                printf("\n");
        }
        
  return 0;
}

void readrc(int *row, int *column)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me the row and the column: ");
        if (scanf("%d, %d", row, column) != 2)
        {
            printf("Wrong input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}