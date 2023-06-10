/* Write a program called vol.c that calculates the volume of a body as follows :
1. declares three int variables height h, length l, and width w
2. assign any values you like to h, land w
3. prints out the values of h, land w
4. uses h, land w to calculate the volume v
5. prints out the volume v

An example of the expected output is shown below :
height = 22, length = 5, width = 2 volume = 220 */

# include <stdio.h>

int main(void) {

	/* declare h, l, w as int */
	int h = 173, l = 100, w = 800, v;

	/* print height, length and width respectively */
	printf("height is %d m\n", h );
	printf("length is %d m\n", l);
	printf("width is %d m\n", w);

	v = h * l * w;

	printf("volume is %d m^3\n", v);

	return 0;
}
