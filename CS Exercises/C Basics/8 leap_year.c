/*
Write a C program taking a year as command line parameter and printing out on the standard output if this year is leap or not.

To determine if a year is leap, you can use the following algorithm (taken from Wikipedia):

if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)

The output format should be as described in these examples:

./leap 2000
2000 is a leap year
./leap 2100
2100 is not a leap year
*/

# include <stdio.h>
int main (void) {
    printf("Please put Year to check it's leap or not: ");

    /* Declare the 'YEAR' as integer */
    int YEAR;

    /* Get the value of 'YEAR' */
    scanf("%d", &YEAR);

    /* Divisible with 4 AND but not Divisible with 100 OR Divisible with 400 -> Leap Year */
    if ((YEAR % 4 == 0 && YEAR % 100 != 0) || YEAR % 400 == 0) {
        printf("%d is a LEAP year\n", YEAR);
    }

    else {
        printf("%d is not a LEAP year\n", YEAR);
    }


    return 0;
}
