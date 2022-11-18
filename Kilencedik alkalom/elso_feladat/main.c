/*Olvassunk be egy float típusú tömbbe, melynek méretét a felhasználótól kérje be!
Írassa ki a tömböt táblázatosan, majd vizsgálja monotonitás szerint!
Keresse meg a minimum és maximum értékét és helyét!

A függvényeket saját header állományban deklarálja!*/
#include "functions.c"

int main()
{
    unsigned int size;
    readu(&size);
    float arr[size];
    read_arr(arr, size);

    printf("Item:\t\t\tValue:\n");
    print_arr(arr, size);

    is_monotone(arr, size);

    printf("Minimum of the sequence: %u.\n", minarray(arr, size));
    printf("Maximum of the sequence: %u.\n\n", maxarray(arr, size));

    printf("Minimum index of the sequence: %u.\n", minindex(arr, size));
    printf("Maximum index of the sequence: %u.\n", maxindex(arr, size));
    return 0;
}