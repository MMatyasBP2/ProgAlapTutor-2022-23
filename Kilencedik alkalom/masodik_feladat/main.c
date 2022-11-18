#include "zh.c"

int main()
{
    double array[SIZE];
    fillarray(array, SIZE);

    printf("Item:\t\t\tValue:\n");
    printarray(array, SIZE);

    printf("\n\n");

    unsigned int newsize = getnewsize(array);
    double newarray[newsize];
    choose(array, newarray);
    printf("Newarray\nItem:\t\t\tValue:\n");
    printarray(newarray, newsize);
    printf("Minimum of the new array = %u.\n", minarray(newarray, newsize));

    int lower, upper;
    readinterval(&lower, &upper);
    printf("Avarage between %d and %d: %.2f", lower, upper, calcavg(lower, upper, array, SIZE));

    return 0;
}