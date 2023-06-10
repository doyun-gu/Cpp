/*
Write a program that computes the volume of a sphere that prompts the user for the radius. 
Use the formula v = (4/3) πr3 (write the fraction 4/3 as 4.0/3.0). 
(hint: multiply r by itself twice to get r3). 
Use doubles for volume v and radius r, and the following macro definition to represent π:

#define PI 3.141593

Print the output to an accuracy of 2 decimal places. Example output:
Enter a Value for the radius of the sphere: 5
Volume: 523.60
*/

# include <stdio.h>
# define PI 3.141593

int main(void) {
	double volume, radius;

	printf("Enter a Value for the Radius of the sphere: ");
	scanf("%lf", &radius);

	volume = 4 * PI * radius * radius * radius / 3;

	printf("Volume: %.2lf", volume);

	return 0;
}
