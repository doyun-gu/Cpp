/*
Write a simple program as follows:

1) Declare three structure variables, c1, c2 and c3, each having members real and imaginary each of type double. 
Ensure that c1's members have the values 0.0 and 1.0, while c2's members are 1.0 and 0.0 initially (c3 is not initialized).
2) Write statements that copy the members of c2 into c1.
3) Write statements that add the corresponding members of c1 and c2, and store the result in c3.
*/

/* Lab 9a Task2 Solution */

#include <stdio.h>

int main(void)  {

    struct {
        double real, imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

    c1 = c2;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("c3 = %5.2f + %5.2fi\n", c3.real, c3.imaginary);

    return 0;
}
