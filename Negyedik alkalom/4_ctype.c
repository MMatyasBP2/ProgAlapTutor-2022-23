#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int main()
{
    // isdigit()

    char inputchar;
    scanf("%c", &inputchar);
    printf("Our char (%c) is %s.\n", inputchar, isdigit(inputchar) ? "a digit" : "a char");

    char input;
    bool ok;
    do
    {
        ok = true;
        printf("Gimme a char: ");
        if (scanf("%c", &input) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if(isdigit(input) == 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    printf("Your char = %c\n\n", input);

    // islower(), isupper()

    char input;
    bool ok;
    do
    {
        ok = true;
        printf("Gimme a char: ");
        if (scanf("%c", &input) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        else if(isdigit(input) == 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
        
    } while (!ok);
    
    if (islower(input))
    {
        printf("Your char in uppercase = %c\n", toupper(input));
    }
    else
    {
        printf("Your char in lowercase = %c\n", tolower(input));
    }

    return 0;
}