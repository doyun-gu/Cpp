/*
Task 1.
Write a program that uses a recursive function called power to compute x^n, 
where x is a double and n is an integer. The function uses the formula x^n = x × x^n–1. 

For example:
Enter x and n: 3 2
x^y = 9

The output should be printed to 2 decimal places.
*/

# include <stdio.h>

double power(double a, int b);

int main(void) {
	double x;
	int n;

	printf("Enter x and then n: ");
	scanf("%lf%d", &x, &n);

	printf("x^y = %.2lf\n", power(x, n));

	return 0;
}

double power(double a, int b) {

	if (b <= 1) {
		return a;
	}

	else {
		return a * power(a, (b - 1));
	}

	return a * power(a, (b - 1));
}
