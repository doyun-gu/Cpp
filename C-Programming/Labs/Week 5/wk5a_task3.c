/*
Write a program that stores the following ten data items in an array:
3.2, 2.4, 6.6, 7.3, 4.2, 9.9, 12.0, -3.2, -4.1, 5.4

and then uses a for loop to calculate their sum and average to 2 decimal places.
*/

# include <stdio.h>
int main(void) {

	double sum = 0;
	double average = 0;
	double data[10] = { 3.2, 2.4, 6.6, 7.3, 4.2, 9.9, 12.0, -3.2, -4.1, 5.4 };
	
	for (int i = 0; i < 10; i++) {
		sum += data[i];
	}

	average = sum / 10;

	printf("sum = %/2lf, average = %.2lf\n", sum, average);

	return 0;
}
