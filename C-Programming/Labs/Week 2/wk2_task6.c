/*
Merge the two programs a) and b) from Task 5 into one. Make it prompt the user for the mass, height and velocity, 

calculate the kinetic and potential energies and print out the total energy. 

Example output:
Enter a Value for mass: 2.5
Enter a Value for height: 22.5
Enter a Value for velocity: 72.5
Total Energy: 7121.56 J
*/

#include <stdio.h>
#define GRAVITY 9.8
int main(void) {
	double mass, height, velocity, PE, KE, TE;

	printf("Enter a Value for mass:");
	scanf("%lf", &mass);

	printf("Enter a Value for height:");
	scanf("%lf", &height);

	printf("Enter a Value for velocity:");
	scanf("%lf", &velocity);

	KE = mass * velocity * velocity / 2;
	PE = mass * height * GRAVITY;

	TE = KE + PE;

	printf("Total Energy: %.2lf J\n", TE);

	return 0;
}
