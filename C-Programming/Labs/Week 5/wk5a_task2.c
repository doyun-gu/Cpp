/*
Write a program that prints the values returned by sizeof for the following data types: char, short, int, unsigned int, long, unsigned long, float, and double.

Note: use "%lu" in printf, and cast the value returned by short to unsigned long.

Example:
printf("short\t\t%lu\n", (unsigned long) (sizeof (short)));
Expected output:

Type    sizeof
--------------
char     1
short    2
 .       .
 .       .
*/

#include <stdio.h>

int main(void) {

    printf("Type\t      sizeof\n");
    printf("----------------------\n");
    printf("char\t\t%lu\n", (unsigned long)(sizeof(char)));
    printf("short\t\t%lu\n", (unsigned long)(sizeof(short)));
    printf("int\t\t%lu\n", (unsigned long)(sizeof(int)));
    printf("unsigned int\t%lu\n", (unsigned long)(sizeof(unsigned int)));
    printf("long\t\t%lu\n", (unsigned long)(sizeof(long)));
    printf("unsigned long\t%lu\n", (unsigned long)(sizeof(unsigned long)));
    printf("float\t\t%lu\n", (unsigned long)(sizeof(float)));
    printf("double\t\t%lu\n", (unsigned long)(sizeof(double)));

    printf("\nOthers:\n");
    printf("long long\t\t%lu\n", (unsigned long)(sizeof(long long)));
    printf("unsigned long long\t%lu\n", (unsigned long)(sizeof(unsigned long long)));
    printf("long double\t\t%lu\n", (unsigned long)(sizeof(long double)));

    return 0;
}
