/*
Make a copy of your solution to the 'resistance' problem in Lab 1b Task 1a,
and modify it such that the output is printed out using a minimum width of five and three decimal places (i.e. 3 digits after the decimal point). 
Example
output: Resistance = 35.318 Ohms
*/

# include <stdio.h>
int main(void) {
	double resistance, resistivity, length = 200, area = 100, electric_field = 30, current_density = 22;

	resistivity = electric_field / current_density;

	resistance = (resistivity * length) / area;

	printf("Resistance: %.3f\n", resistance);
	return 0;
}
