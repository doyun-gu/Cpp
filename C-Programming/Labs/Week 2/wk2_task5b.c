/*
Write a program to calculate potential energy PE, using the formula
P.E. = m*g*h
where m is mass in kilograms, g is the acceleration due to gravity (use 9.8 m/s^2) and h is height in meters. 

Prompt the user to enter a value for m and h:

Enter a Value for mass: 2.5
Enter a Value for height: 22.5
Potential Energy: 55.125 J
*/

#include <stdio.h>
#define GRAVITY 9.8
int main(void) {
	double PE, mass, height;

	printf("Enter a Value for mass:");
	scanf("%lf", &mass);

	printf("Enter a Value for height:");
	scanf("%lf", &height);

	PE = mass * GRAVITY * height;

	printf("Potential Energy:%.2lf J\n", PE);

	return 0;
}
