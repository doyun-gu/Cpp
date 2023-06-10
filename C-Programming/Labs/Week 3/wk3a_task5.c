/*
Write a simple program that tests whether a given integer is between the limits 0 and 100, as follows:

a) Prompts the user to enter a number (an integer), positive or negative; save
the number entered,

b) Tests whether the number entered is between the limits using a single if
statement using the logical and operator
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void) {
	/*
	Declare the read value
	*/
	double read_value;

	printf("Enter any value you want:");
	scanf("%lf", &read_value);

	if (read_value > 0 && read_value < 100)
		printf("the Value you put is in the range: 0 < value < 100\n");
	else
		printf("the Value you put is out of the range: 0 < value < 100\n");

	return 0;
}
