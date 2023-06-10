/*
Write a program that prompts the user to enter a value for x (use float) and then
displays the value of the following polynomial: (hint: multiply x by itself to get x2).
y = 3 x^5 + 2x^4 - 5 x^3 – x^2 + 7x – 6
Ensure the output is printed out to an accuracy of two decimal places Test your program for various values of x. 

Example output:
Enter a Value for x: 5
y = 10004.00
*/

# include <stdio.h>
int main(void) {
	double x, y;

	printf("Enter a Value for x:");
	scanf("%lf", &x);

	y = 3 * x * x * x * x * x + 2 * x * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;

	printf("y = %.2lf", y);

	return 0;
}
