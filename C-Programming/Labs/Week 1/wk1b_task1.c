/* For floating-point numbers, an alternative to the type float is the type double. 
Here's an example declaration:
double length;

For assignments of double variables you don't have to append the letter "f" to 
assignments. 

For example
length = 5.2;

As usual the declaration and assignment can be combined:
double length = 5.2;

As with float variables, printing double variables with printf requires the "%f" formatter, for example
printf ("Length = %f\n", length); 
use %f for both float and double variables the output of which is
Length = 5.200000

We'll see how to specify that the output is displayed in a restricted number of 
decimal places(e.g. 5.2), in the next lab.

Finally, note that floating - point numbers can also be specified in exponential
notation using the character 'E' (or 'e').

For example double planck = 6.62606957E-34 */

# include <stdio.h>

int main(void) {
	double length = 5.2;

	printf("Length = %f", length);


	return 0;
}
