    /*
        1. Adottak egy egyetemi hallgató eredményei 6 félévre vonatkozóan (féléves tanulmányi átlagok időrendben)
        Keresse meg, hogy melyik félévben volt a tanulmányi eredmény 4.5 fölött.
    */
   /*
        2. 1990 és 2022 között hanyadik év volt az első szökőév?
   */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void readarray(float *array, const unsigned int size);
void printarray(float *array, const unsigned int size);
void searchmark(float number, float *array, const unsigned int size);
void readyear(unsigned int *year);
bool isleapyear(unsigned int year);

int main()
{
    // 1.
    const unsigned int semesters = 6;
    float result[semesters];
    readarray(result, semesters);
    printf("Item:\t\tValue:\n");
    printarray(result, semesters);
    searchmark(4.5, result, semesters);

    // 2.
    unsigned int year;
    readyear(&year);
    printf("Our year is %s.\n", isleapyear(year) ? "a leap year" : "not a leap year");

    return 0;
}

void readarray(float *array, const unsigned int size)
{
    bool ok;
    for (unsigned int i = 0; i < size; i++)
    {
        do
        {
            ok = true;
            printf("Element %u: ", i + 1);
            if (scanf("%f", &array[i]) != 1)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
            else if(array[i] > 5.0)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
        } while (!ok);
    }
}

void printarray(float *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t%.2f\n", i + 1, array[i]);
    }
}

void searchmark(float number, float *array, const unsigned int size)
{
    bool found = false;
    for (unsigned int i = 0; i < size; i++)
    {
        if (array[i] > number)
        {
            found = true;
            printf("Upper (%.2f) was found at the index of %u.\n", number, i + 1);
            break;
        }
    }

    if (!found)
    {
        printf("Upper (%.2f) was not found.", number);
    }
}

void readyear(unsigned int *year)
{
    bool ok;
    do
    {
        ok = true;
        printf("Give me a year: ");
        if (scanf("%u", year) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (*year < 1990)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if (*year > 2022)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);   
}

bool isleapyear(unsigned int year)
{
    return (year % 4 == 0 && year % 100 != 00) || year % 400 == 0;
}