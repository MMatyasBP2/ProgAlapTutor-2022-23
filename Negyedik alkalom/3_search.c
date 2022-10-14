#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

int main()
{
    char abc[] = { 'a', 'b', 'c', 'd', 'e', 'f',
                    'g', 'h', 'i', 'j', 'k', 'l',
                    'm', 'n', 'o', 'p', 'q', 'r',
                    's', 't', 'u', 'v', 'w', 'x',
                    'y', 'z' };

    char key;
    bool ok, found = false;

    do
    {
        ok = true;
        printf("Give me a character to search: ");
        if (scanf("%c", &key) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
    
    // Searching

    for (unsigned int i = 0; i < sizeof(abc) / sizeof(abc[0]); i++)
    {
        if (abc[i] == key || abc[i] == tolower(key))
        {
            printf("Your char (%c) is %u. in the ABC.\n", key, i + 1);
            found = true;
            break;
        }
    }

    if (!found)
    {
        printf("Your char is not in the array.\n");
    }
    
    

    return 0;
}