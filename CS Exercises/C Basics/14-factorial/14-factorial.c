/*
Write a C program taking an integer as command line parameter and displaying the factorial of that integer on the standard output as follows:

./factorial 10
10! = 3628800

./factorial 15
15! = 1307674368000

./factorial 1
1! = 1

We assume that the parameter value can be up to 20, the maximum number which factorial can be stored in a 64 bits unsigned integer.
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

    // Case 1: Wrong no. of Parameters
    if (argc == 1) {
        printf("Error!: Please input Arguments 1 at least! \n");
        return -1;
    }

    // Case 2: No Error
    // Set input array
    int n = atoi(argv[1]);

    // Initialized to 1 because multiplying by 0 will always give 0
    unsigned long long result = 1;

    for (int i = n; i > 1; i--) {
        result *= i;
    }
    
    printf("%d! = %llu\n", n, result);

    return 0;
}
