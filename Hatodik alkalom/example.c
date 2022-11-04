/*
    Írjon programot az alábbi feladatokból:
    1. Olvasson be ellenőrzötten egy integer tömbbe, majd írassa is ki azt!
    2. Rendezze először növekvő, majd csökkenő sorrendben a bekért tömböt!
    3. Döntse el milyen monoton a sor (monoton növekvő, monoton csökkenő vagy nem monoton)!
    4. Kérjen be egy számot az inputról és döntse el, hogy prím e!
    5. Vizsgálja meg bináris kereséssel, hogy a bekért szám benne van e a tömbben!
    6. A prím vizsgáló függvénnyel keresse meg előről majd hátulról a legelső prímszámot, ha van ilyen!
    7. Keresse meg a tömb legkisebb, legnagyobb elemeit, majd írassa ki a helyüket!
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

void readarray(unsigned int *array, const unsigned int size);
void printarray(unsigned int *array, const unsigned int size);
void minsort(unsigned int *array, const unsigned int size);
void maxsort(unsigned int *array, const unsigned int size);
unsigned int monotoning(unsigned int *array, const unsigned int size);
void how_monotone(unsigned int *array, const unsigned int size);
void readu(unsigned int *num);
bool is_prime(unsigned int num);
void searchnumber(unsigned int input, unsigned int *array, const unsigned int size);
bool search_prime_from_beginning(unsigned int *array, const unsigned int size);
bool search_prime_from_end(unsigned int *array, const unsigned int size);
unsigned int min_arr(unsigned int *array, const unsigned int size);
unsigned int max_arr(unsigned int *array, const unsigned int size);
unsigned int min_index_arr(unsigned int *array, const unsigned int size);
unsigned int max_index_arr(unsigned int *array, const unsigned int size);

int main()
{
    // 1.
    const unsigned int size = 10;
    unsigned int array[size];
    readarray(array, size);
    printf("\n");
    printarray(array, size);

    // 2.
    printf("\nSorting by ASC:\n");
    minsort(array, size);
    printarray(array, size);

    printf("\nSorting by DESC:\n");
    maxsort(array, size);
    printarray(array, size);

    // 3.
    printf("\nLet's analyse how monotone is our array:\n");
    how_monotone(array, size);
    printf("\n");

    // 4.
    printf("Please give me a number and the program will analyse you if its prime:\n");
    unsigned int num;
    readu(&num);
    printf("The number is %s.\n", is_prime(num) ? "prime" : "not prime");

    // 5.
    searchnumber(num, array, size);

    // 6.
    printf("\nNow let's see that which is the first prime in the array:\n");
    search_prime_from_beginning(array, size);

    printf("\nNow let's see that which is the last prime in the array:\n");
    search_prime_from_end(array, size);

    // 7.
    printf("Let's see the minimum, maximum\nmin_index, max_index of the array:\n");
    printf("The minimum is %u.\n", min_arr(array, size));
    printf("The maximum is %u.\n", max_arr(array, size));
    printf("The minimum index is %u.\n", min_index_arr(array, size));
    printf("The maximum index is %u.\n", max_index_arr(array, size));

    return 0;
}

void readarray(unsigned int *array, const unsigned int size)
{
    bool ok;
    for (unsigned int i = 0; i < size; i++)
    {
        do
        {  
            ok = true;
            printf("Element %u: ", i);
            if (scanf("%u", &array[i]) != 1)
            {
                printf("Bad input format!\n");
                ok = false;
                while((getchar()) != '\n');
            }
        } while (!ok);
    }
}

void printarray(unsigned int *array, const unsigned int size)
{
    printf("Element:\tValue:\n");
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%u. item\t\t%u\n", i, array[i]);
    }
}

void minsort(unsigned int *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                unsigned int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void maxsort(unsigned int *array, const unsigned int size)
{
    for (unsigned int i = 0; i < size - 1; i++)
    {
        for (unsigned int j = i + 1; j < size; j++)
        {
            if (array[i] < array[j])
            {
                unsigned int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

unsigned int monotoning(unsigned int *array, const unsigned int size)
{
    bool is_monotone_increasing = true;
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i - 1] > array[i])
        {
            is_monotone_increasing = false;
        }
    }

    bool is_monotone_decreasing = true;
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i - 1] < array[i])
        {
            is_monotone_decreasing = false;
        }
    }
    
    if (is_monotone_increasing)
    {
        return 1;
    } else if(is_monotone_decreasing)
    {
        return 2;
    }
    return 0;
}

void how_monotone(unsigned int *array, const unsigned int size)
{
    switch (monotoning(array, size))
    {
    case 1: printf("Sequence is monotone increasing.\n");
        break;
    
    case 2: printf("Sequence is monotone decreasing.\n");
        break;

    default: printf("Sequence is non-monotone.\n");
    }
}

void readu(unsigned int *num)
{
    bool ok;
    do
    {
        ok = true;
        printf("Gimme a number: ");
        if (scanf("%u", num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
}

bool is_prime(unsigned int num)
{
    unsigned int prime = 2;

    while(prime <= sqrt(num) && num % prime != 0)
    {
        prime++;
    }

    if(prime > sqrt(num))
    {
        return true;
    }
    
    return false;
}

void searchnumber(unsigned int input, unsigned int *array, const unsigned int size)
{
    unsigned int first = 0;
    unsigned int last = size - 1;
    unsigned int middle = (first + last) / 2;

    while(first <= last)
    {
        if (array[middle] < input)
        {
            last = middle - 1;
        }
        else if(array[middle] == input)
        {
            printf("Input (%d) was found at the index of (%u) in the array.\n", input, middle);
            break;
        }
        else
        {
            first = middle + 1;
        }
        middle = (first + last) / 2;
    }

    if (first > last)
    {
        printf("Input (%u) was not found in the array.\n", input);
    }
}

bool search_prime_from_beginning(unsigned int *array, const unsigned int size)
{
    bool found = false;
    for (unsigned int i = 0; i < size; i++)
    {
        if (is_prime(array[i]))
        {
            found = true;
        }

        if (found)
        {
            printf("Prime in the sequence is: %u\n", array[i]);
            break;
        }
    }
    
    if (!found)
    {
        printf("There's no prime in the sequence.\n");
    }
    
    return found;
}

bool search_prime_from_end(unsigned int *array, const unsigned int size)
{
bool found = false;
    for (int i = size - 1; i > -1; i--)
    {
        if (is_prime(array[i]))
        {
            found = true;
        }

        if (found)
        {
            printf("Prime in the sequence is: %u\n", array[i]);
            break;
        }
    }
    
    if (!found)
    {
        printf("There's no prime in the sequence.\n");
    }
    
    return found;
}

unsigned int min_arr(unsigned int *array, const unsigned int size)
{
    unsigned int min = array[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}

unsigned int max_arr(unsigned int *array, const unsigned int size)
{
    unsigned int max = array[0];
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

unsigned int min_index_arr(unsigned int *array, const unsigned int size)
{
    unsigned int minindex = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i] < array[minindex])
        {
            minindex = i;
        }
    }
    
    return minindex;
}

unsigned int max_index_arr(unsigned int *array, const unsigned int size)
{
    unsigned int maxindex = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (array[i] > array[maxindex])
        {
            maxindex = i;
        }
    }
    
    return maxindex;
}