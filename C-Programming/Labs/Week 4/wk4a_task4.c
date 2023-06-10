/*
Write a program that uses a for loop to calculate the factorial of an integer number entered by the user.
*/

# include <stdio.h>

int main(void) {
	int x;
	double fractional = 1;

	printf("Enter an integer number: ");
	scanf("%d", &x);

	for (int i = 2; i <= x; i++) {
		fractional *= i;
	}

	printf("\n");
	printf("Fractial of %d = %.0lf\n", x, fractional);

	return 0;
}
