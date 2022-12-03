#include "ttifunc.c"

int main()
{
    printf("The program will calculate you the TTI (Testtomeg index - hu. - ).\n");
    const unsigned int size = 5;
    const unsigned int height_size = 5;
    double height[] = {1.05, 1.16, 1.52, 1.18, 1.34};
    printf("Height:\n");
    printf_arr(height, height_size);
    double weight[size];
    fill_arr(weight, size);
    printf("\nWeight:\n");
    printf_arr(weight, size);
    printf("\n\n");
    double tti_arr[size];
    tti(height, weight, size, tti_arr);
    printf("\nTTI types by child:\n");
    tti_type(tti_arr, size);
    printf("\nSorting by maximum item:\n");
    max_sort(size, tti_arr);
    printf_arr(tti_arr, size);
    printf("\n\n");
    char string[STR_BUF];
    read_str(string);
    TT_details *TT_all = TT_system(size, tti_arr, string);
    printf("Children with the TTI, you've given:\n");
    printf_arr(TT_all->TT, TT_all->size);
    file_write(TT_all);
    free(TT_all);
    printf("\n\nThe program has written the TTI's in a file in the program's directory.\n");
    return 0;
}