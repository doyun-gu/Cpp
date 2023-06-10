/*
If working with a friend, split this task as follows: one person writes the main program which includes prompting the user to enter a number; 
the second writes the swap function; then, merge the code to produce the final function.

Write a program that uses a function called ‘swap’ to reverse and print out the digits of a number between 10 and 100. The function prototype is shown below:
double swap(int x);

Example output:
Enter a number between 10 and 100: 41
The number with digits reversed: 14
*/

# include <stdio.h>
double swap(int x);

int main(void) {
	int x;
	printf("\n Enter a number between 10 and 100: ");
	scanf("%d", &x);

	printf("The number with digits reversed: %g\n", swap(x));

	return 0;
}

double swap(int number) {
	int first_digit = number / 10;
	int second_digit = 10 * (number - first_digit * 10);
	return second_digit + first_digit;
}
