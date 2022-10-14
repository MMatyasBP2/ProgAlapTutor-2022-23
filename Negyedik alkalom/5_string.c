#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    // strcat()

    char string[10], string2[10];
    printf("Gimme me two strings: ");
    scanf("%s", string);
    scanf("%s", string2);

    printf("The two strings concatted: %s\n\n", strcat(string, string2));

    // strcmp()

    char string3[10] = "alma";
    char string4[10] = "alma";

    if (strcmp(string3, string4) == 1)
    {
        printf("The two string are similar.\n");
    }
    else if(strcmp(string3, string4) == 0)
    {
        printf("The two string are different.\n");
    }

    // strlen()

    int strlength = strlen(string);
    printf("Length of %s is %d.", string, strlength);
    

    return 0;
}