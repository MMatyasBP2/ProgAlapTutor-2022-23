#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define STR_BUF (1 << 8) // 2 a 8. hatványon

void read_string(char *string);
void copy_reverse(const char *string, char *reverse);
void copy_capitalize(const char *string, char *capital);
unsigned int count_letter(const char *string, const char letter);

int main()
{
    char string[STR_BUF];
    read_string(string);
    printf("String = %s.\n", string);

    // Reverse
    char reverse[STR_BUF];
    copy_reverse(string, reverse);
    puts("Your string backwards: ");
    puts(reverse);

    //Capitalize
    char capitalize[STR_BUF];
    copy_capitalize(string, capitalize);
    puts("Your string capitalited:");
    puts(capitalize);

    //Count letters function
    printf("Number of '%c' in your string: %u.", 'e', count_letter(string, 'e'));

    return 0;
}

void read_string(char *string)
{
    printf("Give me a string: ");
    scanf("%[^\n]", string);
}

void copy_reverse(const char *string, char *reverse)
{
    const size_t size = strlen(string);
    for (size_t i = 0; i < size; i++)
    {
        reverse[i] = string[size - i - 1];
    }
    reverse[size] = '\0';
}

void copy_capitalize(const char *string, char *capital)
{
    const size_t size = strlen(string);

    for (size_t i = 0; i < size; i++)
    {
        capital[i] = (char)toupper(string[i]);
    }
}

unsigned int count_letter(const char *string, const char letter)
{
    unsigned int count = 0;

    for (size_t i = 0; i < strlen(string); i++)
    {
        if (tolower(string[i]) == tolower(letter))
        {
            count++;
        }
    }

    return count;
}