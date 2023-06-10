# include <stdio.h>
int main(void) {

	double sum = 0;
	double average = 0;
	double data[10] = { 3.2, 2.4, 6.6, 7.3, 4.2, 9.9, 12.0, -3.2, -4.1, 5.4 };
	int i = 0;

		while (i < 10) {

			sum += data[i];
			i++;

		}


	average = sum / 10;

	printf("sum = %/2lf, average = %.2lf\n", sum, average);

	return 0;
}
