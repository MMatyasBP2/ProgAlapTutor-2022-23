#include "comp.c"

int main()
{
    const unsigned int size = 3;
    double competitor_1[size];
    double competitor_2[size];
    srand(time(0));
    fill_arr(competitor_1, size);
    fill_arr(competitor_2, size);
    printf("Competitor 1:\n");
    printf_arr(competitor_1, size);
    printf("\nCompetitor 2:\n");
    printf_arr(competitor_2, size);
    printf("\n\n");
    printf("Results in a table: First competitor:\n");
    write_results_in_table(competitor_1, size);
    printf("\n");
    printf("Results in a table: Second competitor:\n");
    write_results_in_table(competitor_2, size);
    printf("\n\nThe program will write the two results in two several files. (Result1.txt and Result2.txt)\n");
    printf("You found it in the directory of this program.\n\n");
    write_results_in_file_1(competitor_1, size);
    write_results_in_file_2(competitor_2, size);
    printf("The program will sort the best result:\n");
    printf("First competitor best result: %.2lf", max_arr(competitor_1, size));
    printf("\n");
    printf("Second competitor best result: %.2lf", max_arr(competitor_2, size));
    printf("\n\n");
    printf("Let's see who won:\n");
    double num_1 = max_arr(competitor_1, size);
    double num_2 = max_arr(competitor_2, size);
    who_won(&num_1, &num_2);
    printf("\n");
    unsigned int number;
    readu(&number);
    if (number <= 1)
    {
        printf("Sorting the first competitor result's by max item:\n");
        max_sort(competitor_1, size);
        printf_arr(competitor_1, size);
    } else if (number >= 2)
    {
        printf("Sorting the second competitor result's by max item:\n");
        max_sort(competitor_2, size);
        printf_arr(competitor_2, size);
    }
    printf("\n");
    printf("Let's see the segment of the two array:\n");
    double results[size];
    segment_of_arrays(competitor_1, competitor_2, results, size);
    printf_arr(results, size);
    return 0;
}