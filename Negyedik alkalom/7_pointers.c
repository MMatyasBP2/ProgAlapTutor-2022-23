#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a = 'X';
    char b = 'Y';
    char c = 'Z';
    double d = 1;

    printf("%d bytes\n\n", sizeof(d));

    // Memóriacímek

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n\n", &c);
    printf("%p\n", &d);

    // Tömbbel:

    char e[3];
    printf("%d bytes\n", sizeof(e));
    printf("%p\n\n", &e);

    // Pointerek:

    int age = 20;
    int *p = &age;

    printf("Address of age: %p\n", &age);
    printf("Value of p: %p\n\n", p);

    printf("Value of age: %d\n", age);
    printf("Value of age on the other way: %d", *p);

    // *, a változó értéke, amire mutatunk
    // p, a változó memóriacíme, amire mutatunk

    return 0;
}