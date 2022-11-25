#include<stdio.h>
#include<stdlib.h>

#define STR_BUFF (1 << 10)

void reads(char *msg);
void writeInFile(char *msg);
void readFromFile();

int main()
{
    char msg[STR_BUFF];
    reads(&msg);
    puts(msg);
    
    writeInFile(msg);
    readFromFile();
    return 0;
}

void reads(char *msg)
{
    scanf("%[^\n]", msg);
}

void writeInFile(char *msg)
{
    FILE *file = fopen("FileName.txt", "w");
    fputs(msg, file);
    fclose(file);
}

void readFromFile()
{
    char buff[STR_BUFF];
    FILE *fp = fopen("FileName.txt", "r");
    fgets(buff, STR_BUFF, fp);
    printf("Read string: %s.\n", buff);
    fclose(fp);
}