/*
a) Merge the two programs a) and b) from Task 1 into one program. Example output:
Resistivity = 0.014 Ohm-metres.
Resistance = 35.318 Ohms.
*/

# include <stdio.h>
int main(void) {

	double resistance, resistivity, length = 200, area = 100, electric_field = 30, current_density = 22;

	resistivity = electric_field / current_density;

	resistance = (resistivity * length) / area;

	printf("Resistance: %.3f Ohm\n", resistance);

	return 0;
}
