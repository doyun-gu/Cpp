/* 
Make a copy of your solution to the 'kinetic energy' problem in Lab 1b Task 1b and modify it to define a constant called PE (meaning potential energy),
such that

total energy = ke + PE
where ke is the kinetic energy, defined before as:
ke = 1/2 x mass x (velocity)2.

Assign to PE a value of your choice, but prompt the user for the velocity.
Print out the total energy. 

Example output:
Enter a value of velocity: 72.5
Total energy = 50470.00
*/

#include <stdio.h>
#define PE 300
int main(void) {
	double kinetic_energy, mass, velocity, total_energy;

	printf("Enter the velocity:");
	scanf("%lf", &velocity);

	printf("Enter the mass:");
	scanf("%lf", &mass);

	kinetic_energy = mass * velocity * velocity / 2;

	total_energy = kinetic_energy + PE;

	printf("The value of kinetic_energy is %.2lf\n", kinetic_energy);
	printf("Therefore, Total Energy is %.2lf", total_energy);

	return 0;
}
