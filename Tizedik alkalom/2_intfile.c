#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readArray(int *numbers, const unsigned int size);
void printArray(int *numbers, const unsigned int size);
bool isMonotone(int *numbers, const unsigned int size);
void writeInFile(char *filename, int *numbers, const unsigned int size);
void readFromFile(char *filename, int *numbers, const unsigned int size);

int main()
{
    const unsigned int size = 5;
    unsigned int array[size];
    readArray(array, size);
    printArray(array, size);
    if (isMonotone(array, size))
    {
        writeInFile("IntFile.txt", array, size);
        printf("The array read from file:\n");
        readFromFile("IntFile.txt", array, size);
    }
    return 0;
}

void readArray(int *numbers, const unsigned int size)
{
    bool ok;
    for (unsigned int i = 0; i < size; i++)
    {
        do
        {
            ok = true;
            printf("Element %u: ", i + 1);
            if (scanf("%d", &numbers[i]) != 1)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
        } while (!ok);
    }
}

void printArray(int *numbers, const unsigned int size)
{
    printf("Item:\t\tValue:\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d\t\t%d\n", i + 1, numbers[i]);
    }
}

bool isMonotone(int *numbers, const unsigned int size)
{
    for (unsigned int i = 1; i < size; i++)
    {
        if (numbers[i - 1] > numbers[i])
        {
            return false;
        }
    }
    return true;
}

void writeInFile(char *filename, int *numbers, const unsigned int size)
{
    FILE *fp = fopen(filename, "w");
    for (unsigned int i = 0; i < size; i++)
    {
        fprintf(fp, "Element #%u: %d\n", i + 1, numbers[i]);
    }
    fclose(fp);
}

void readFromFile(char *filename, int *numbers, const unsigned int size)
{
    FILE *fp = fopen(filename, "r");
    for (unsigned int i = 0; i < size; i++)
    {
        fscanf(fp, "%d", &numbers[i]);
    }

    for (unsigned int i = 0; i < size; i++)
    {
        printf("Element #%d: %d\n", i + 1, numbers[i]);
    }
    fclose(fp);
}