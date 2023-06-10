/*
Write a program that computes the area of an isosceles triangle by asking the user to enter values for its height and base,

and prints out the value returned by calling a function. The prototype of the function is show below:

double area (double height, double base);
*/

#include <stdio.h>

double area(double height, double base);

int main(void) {
	double height, base;

	printf("Enter a Value for Height:");
	scanf("%lf", &height);

	printf("Enter a Value for Base:");
	scanf("%lf", &base);

	printf("The area of the triangle is %g\n", area(height, base));

	return 0;
}

/* Area */
double area(double height, double base) {
	return 0.5 * height * base;
}
