#include<stdio.h>
#include<stdlib.h>

int main()
{
    char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

    int size = sizeof(vowels);
    printf("Size = %d", size);

    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d. item = %c\n", i + 1, vowels[i]);
    }
    
    return 0;
}