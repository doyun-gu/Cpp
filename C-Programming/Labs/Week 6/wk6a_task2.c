/*
Write a program that asks the user to enter a value for x and calls a function called poly() to compute the value of the polynomial, 

and prints out the value returned by the function:
3x^5 + 2x^4 -5x^3 -x^2 -7x -6 

The prototype of the function is:
double poly(double x);
*/

# include <stdio.h>

double poly(double x);

int main(void) {
	double x;

	printf("Enter value for x: ");
	scanf("%lf", &x);

	printf("Polynomial value: %g\n", poly(x));

	return 0;
}

double poly(double x) {
	return ((((3 * x + 2) * x - 5) * x - 2) * x + 7)* x - 6;
}
