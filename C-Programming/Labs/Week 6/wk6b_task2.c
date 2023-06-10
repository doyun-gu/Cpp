/*
Write a program that uses a function to recursively evaluate (1 + 1/n)^n, 
where n is a positive integer. The output should be printed to 6 decimal places. 
Test the program with values up to n=30000. 
To which number does the output approach as n grows larger?
*/

# include <stdio.h>

double e(double r, int n);

int main(void) {

	int n;
	printf("Enter a value for n: ");
	scanf("%d", &n);

	printf("(1+1/n) = %lf\n", (1 + 1.0 / n));
	printf("e = %lf\n", e((1 + 1.0\n), n));

	return 0;
}

double e(double r, int n) {
	if (n < 1) {
		return 1;
	}

	else {
		return r * e(r, n - 1);
	}


	return r * e(r, n - 1);
}
