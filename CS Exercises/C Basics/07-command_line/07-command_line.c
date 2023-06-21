/*
Write a C program that takes 3 floating point numbers as command line parameters and displays on the standard boutput the value of the multiplication of these 3 numbers. Examples of execution:

./cmdline 1.0 2.0 3.0
6.000000

./cmdline 1.45 2.78 3.25
13.100750

Warning

Use the type double rather than float to hold these values in order to pass the checks.
*/

# include <stdio.h>

int main (void) {
    float a, b, c;

    scanf ("%f %f %f", &a, &b, &c);
    printf("%f", a * b * c);

    return 0;
}
