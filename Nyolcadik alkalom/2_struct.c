#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STR_BUFF (1 << 10) // 2 a 10-en

typedef struct date
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
} Date;

typedef struct employee
{
    unsigned int id;
    char name[STR_BUFF];
    Date birth_date;
    double salary;
    unsigned int hours;
} Employee;

unsigned int readu(const char *msg);
double readd(const char *msg);
Employee read_emp(const char *msg);
void reads(const char *msg, char *string);
void print_date(const Date date);
void print_emp(const Employee emp);
double calc_hourly_rate(const Employee emp);
unsigned int max_hourly_rate(const Employee *emps, const unsigned int size);
void doubled_salary(Employee *emp);

int main()
{
    const unsigned int emp_size = readu("How many employees do you have?");
    Employee emps[emp_size];
    for (unsigned int i = 0; i < emp_size; i++)
    {
        emps[i] = read_emp("Employees:");
        doubled_salary(&emps[i]);
    }
    for (unsigned int i = 0; i < emp_size; i++)
    {
        print_emp(emps[i]);
    }

    printf("\n\nEmployee with the highest hourly rate:\n");
    print_emp(emps[max_hourly_rate(emps, emp_size)]);
    return 0;
}

unsigned int readu(const char *msg)
{
    unsigned int num;
    bool ok;
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

void reads(const char *msg, char *string)
{
    puts(msg);
    scanf(" %[^\n]", string);
}

Date read_date(const char *msg)
{
    Date date;
    puts(msg);
    date.year = readu("Give me the year: ");
    date.month = readu("Give me the month: ");
    date.day = readu("Give me the day: ");
    return date;
}

Employee read_emp(const char *msg)
{
    Employee emp;
    puts(msg);
    emp.id = readu("Give me the id!");
    reads("Give me the name!", emp.name);
    emp.birth_date = read_date("Give me the date!");
    emp.salary = readd("Give me the salary!");
    emp.hours = readu("Give me the hours!");
    return emp;
}

void print_date(const Date date)
{
    printf("%u. %u. %u.", date.year, date.month, date.day);
}

void print_emp(const Employee emp)
{
    printf("\n\tId:\n\t%u\n", emp.id);
    printf("\tName:\n\t%s\n", emp.name);
    printf("\tBirth date:\n\t");
    print_date(emp.birth_date);
    printf("\n\tSalary:\n\t%.1lf-HUF\n", emp.salary);
    printf("\tWeekly hours:\n\t%u\n", emp.hours);
    printf("\tHourly rate:\n\t%.2lf", calc_hourly_rate(emp));
}

double calc_hourly_rate(const Employee emp)
{
    return emp.salary / (double)emp.hours;
}

unsigned int max_hourly_rate(const Employee *emps, const unsigned int size)
{
    unsigned int maxindex = 0;
    for (unsigned int i = 1; i < size; i++)
    {
        if (calc_hourly_rate(emps[maxindex]) < calc_hourly_rate(emps[i]))
        {
            maxindex = i;
        }
    }
    return maxindex;
}

void doubled_salary(Employee *emp)
{
    emp->salary *= 2;
}