#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct employee
{

    unsigned int id;
    double salary;
    unsigned int hours;

} Employee;

Employee read_emp(const char *msg);
unsigned int readu(const char *msg);
double readd(const char *msg);
void print_emp(const Employee emp);

int main()
{
    Employee emp = read_emp("Please give me the details of your employee!");
    print_emp(emp);
    return 0;
}

Employee read_emp(const char *msg)
{
    Employee emp;
    puts(msg);
    emp.id = readu("Give me an unsigned integer: ");
    emp.salary = readd("Give me the double: ");
    emp.hours = readu("Give me an unsigned integer: ");
    return emp;
}

unsigned int readu(const char *msg)
{
    bool ok;
    unsigned int num;
    do
    {
        ok = true;
        puts(msg);
        if (scanf("%u", &num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
    return num;
}

double readd(const char *msg)
{
    bool ok;
    double num;
    do
    {
        ok = true;
        puts(msg);
        if (scanf("%lf", &num) != 1)
        {
            printf("Bad input format!\n");
            ok = false;
            while((getchar()) != '\n');
        }
    } while (!ok);
    return num;
}

void print_emp(const Employee emp)
{
    printf("\nId: %u\nSalary: %.2lf\nHours: %u.", emp.id, emp.salary, emp.hours);
}