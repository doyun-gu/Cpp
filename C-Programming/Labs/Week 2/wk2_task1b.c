/*
Write a program to calculate a material's resistivity, which is given by the formula
ρ=E/J
where ρ is the resistivity of the material in ohm metres, Ω⋅m, E is the magnitude of the electric field V⋅m-1, 
and J is the magnitude of the current density A⋅m-2. 
Ignoring minimum width, print the result to three decimal places. 

Make up suitable values to test the program with. Example output:
Resistivity = 0.014 Ohm-metres
*/

# include <stdio.h>
int main(void) {
	double resistivity, electric_field = 30, current_density = 22;

	resistivity = electric_field / current_density;

	printf("resistivity = %f Ohm-metres\n", resistivity);

	return 0;
}
