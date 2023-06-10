/*
Write a program using cascaded if statements to determine whether a year is a 'leap year' or not. 
Hint: any year exactly divisible by 4 is a leap year. However, if that same year is exactly divisible by 100 it is not a leap year, 
unless it is also exactly divisible by 400. Use the % operator to test whether the year is 'exactly divisible', or not.

Example output:
Enter a Year of to test: 2000
2000 is a LEAP year
*/

# include <stdio.h>
# define TRUE 1
# define FALSE 0

int main(void) {

	int read_year;

	printf("Eneter a Year of to test: ");
	scanf("%d", &read_year);

    if ((read_year % 4 == 0 && read_year % 100 != 0) || read_year % 400 == 0) {
        printf("%d is a LEAP year\n", read_year);
    }
    else {
        printf("%d is not a LEAP year\n", read_year);
    }

	return 0;
}
