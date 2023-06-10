/*
See how many of the following programs you can write in the time available.
Use double for each of the variables, choosing appropriate values with which to
test each program, printing out the results each time.


a) resistance = (resistivity x length)/area.
*/

# include <stdio.h>
int main(void)
{
	double resistance, resistivity = 300, length = 200, area = 100;

	resistance = (resistivity * length) / area;

	printf("Resistance is Resisvitiy times length over area\n");
	printf("Therefore, Resistance is %f Ohms\n", resistance);

	return 0;
}
