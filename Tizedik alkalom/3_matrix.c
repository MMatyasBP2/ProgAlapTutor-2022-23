#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fillMatrices(int *mx, int row, int col);
void printMatrix(int *mx, int row, int col);
int *sumMatrices(int *mx1, int *mx2, int row, int col);
int *multiMatrices(int *a, int m, int n, int *b, int p, int q);

int main()
{
    int matrix1[3][2];
    int matrix2[3][2];
    int matrix3[2][4];

    srand(time(0));
    fillMatrices((int*)matrix1, 3, 2);
    fillMatrices((int*)matrix2, 3, 2);
    printf("First matrix:\n");
    printMatrix((int*)matrix1, 3, 2);
    printf("Second matrix:\n");
    printMatrix((int*)matrix2, 3, 2);

    // Sum of matrices

    int *res;
    res = sumMatrices((int*)matrix1, (int*)matrix2, 3, 2);
    printf("Sum of matrices:\n");
    printMatrix((int*)res, 3, 2);

    // Multi of matrices
    fillMatrices((int*)matrix3, 2, 4);
    res = multiMatrices((int*)matrix2, 3, 2, (int*)matrix3, 2, 4);
    printf("Multi of matrices:\n");
    printMatrix((int*)res, 3, 4);

    free((int*)res);
    return 0;
}

void fillMatrices(int *mx, int row, int col)
{
    for (unsigned int i = 0; i < row; i++)
    {
        for (unsigned int j = 0; j < col; j++)
            mx[i * col + j] = (rand() % 100) / 10 + 1;
    }
}

void printMatrix(int *mx, int row, int col)
{
    for (unsigned int i = 0; i < row; i++)
    {
        for (unsigned int j = 0; j < col; j++)
            printf("%3d ", mx[i * col + j]);
        printf("\n");
    }
    printf("\n");
}

int *sumMatrices(int *mx1, int *mx2, int row, int col)
{
    int *e = (int*)calloc(row * col, sizeof(int));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                e[i * col + j] = mx1[i * col + j] + mx2[i * col + j];
    return e;       
}

int *multiMatrices(int *a, int m, int n, int *b, int p, int q)
{
    if (n != p)
    {
        printf("Cannot multi the matrices!");
        return NULL;
    }

    int *e = (int*)calloc(m * q, sizeof(int));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int sum = 0;
            for (int k = 0; k < p; k++)
            {
                sum += a[i * n + k] * b[k * q + j];
            }
            e[i * q + j] = sum;
        }
    }
    return e;
}