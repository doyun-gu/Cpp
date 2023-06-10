/*
Write program that stores the square roots of numbers 1-100 in an array, and then
prints them out in descending order to three decimal places of accuracy:
square root of 100 = 10.000
square root of 99 = 9.950
…
…
square root of 2 = 1.414
square root of 1 = 1.000
Hint: use '#include <math.h>' so you can use the sqrt function. To use sqrt see the
following example:
double d = sqrt(12); /* d now contains the square root of 12 */
*/

#include <stdio.h>
#include <math.h>

int main(void) {

    double square_roots[100];        /* declare an array of type double called 'square_roots' */
    for (int i = 1; i <= 100; i++) {
        square_roots[i] = sqrt(i);     /* store the square root of each number */
    }

    for (int i = 100; i > 0; i--) {       /* using a second for loop to print out the data */
        printf("square root of %d =\t%.3lf\n", i, square_roots[i]);
    }

    return 0;
}
