/*
The value of the mathematical constant e can be expressed as an infinite series:
e = 1 + 1/(1!) + 1/(2!) + 1/(3!) + ... + 1/(n!)

Write a program that approximates e by computing the value of the series, where n is an integer entered by the user.
*/

# include <stdio.h>
int main(void) {
	
	long int n, i = 1, fact = 1;
	long double e = 1.0;

	printf("Enter value for n: ");
	scanf("%d", &n);

	while (i <= n) {
		fact *= i;
		e += 1.0 / fact;
		i++;
	}  /* end while loop */

	printf("Approximation of e: %lf\n", e);

	return 0;
}
