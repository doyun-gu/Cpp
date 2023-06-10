/*
b) ke = 1/2 x mass x (velocity)2 where ke = kinetic energy.
(Hint: C doesn't have an exponentiation operator so use velocity*velocity for (velocity)2).
*/

# include <stdio.h>
int main(void) {
	int kinetic_energy, mass = 96, velocity = 10;

	kinetic_energy = mass * velocity * velocity / 2;

	printf("Kinetic Energy is mass times velocity power to the 2 and divided by 2\n");
	printf("Therefore, Kinetic Energy can be calculated as %d\n", kinetic_energy);

	return 0;
}
