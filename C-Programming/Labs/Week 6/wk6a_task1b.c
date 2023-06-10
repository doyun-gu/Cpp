/*
Write a program that computes the perimeter of an isosceles triangle by asking the user to enter values for its height and base, 
and prints out the value returned by calling a function. 

The prototype of the function is show below:

double perimeter (double height, double base);
*/

# include <stdio.h>
# include <math.h>

double perimeter(double height, double base);

int main(void) {

	double height, base;

	printf("Enter a value for the Height:");
	scanf("%lf", &height);

	printf("Enter a value for the base:");
	scanf("%lf", &base);

	printf("The perimeter is %lf\n", perimeter(height, base));

	return 0;
}

double perimeter(double height, double base) {

	double hypotenuse = sqrt((height * height) + (0.5 * base) * (0.5 * base));

	return base + 2 * hypotenuse;
}
