# include <stdio.h>
int main(void) {

	double resistance, resistivity, length, area, electric_field, current_density;

	printf("Enter a value for a length:");
	scanf("%lf", &length);

	printf("Enter a value for cross-sectional area:");
	scanf("%lf", &area);

	printf("Enter a value for electric_field:");
	scanf("%lf", &electric_field);

	printf("Enter a value for current density:");
	scanf("%lf", &current_density);

	resistivity = electric_field / current_density;

	resistance = (resistivity * length) / area;

	printf("Resistance: %.3lf Ohm\n", resistance);

	return 0;
}
