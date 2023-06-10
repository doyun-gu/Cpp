/*
Using the same data in Task 3, write a program that uses a for loop to print out the
maximum value.
*/

# include <stdio.h>
int main(void) {
	double data[10] = { 3.2, 2.4, 6.6, 7.3, 4.2, 9.9, 12.0,-3.2,-4.1,5.4 };
	double max = data[0];

	for (int i = 1; i < 10; i++) {
		if (max < data[i]) {
			max = data[i];
		}
	}
	printf("the maximum value = %.2lf\n", max);

	return 0;
}
