/*
Write a C program taking an odd integer n as parameter and printing an isoscele triangle on the standard output, 
with the triangle's base length being defined by n. 

Example of excutions are:

./triangle 3
*
**
*

./triangle 5
*
**
***
**
*

./triangle 15
*
**
***
****
*****
******
*******
********
*******
******
*****
****
***
**
*
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

    if (argc == 1) {
        printf("Error: Please put any Parameter!\n");
        return -1;
    }

    int n = atoi(argv[1]);

    if (n % 2 == 0) {
        printf("Error: Must put ODD Number!\n");
        return -1;
    }

    int MAX = (n + 1) / 2;

    // First half of the triangle
    for (int row = 1; row <= MAX; row++) {
        for (int column = 1; column <= row; column++) {
            printf("*");
        }
        printf("\n");
    }

    // Second half of the triangle
    for (int row = MAX - 1; row >= 1; row--) {
        for (int column = 1; column <= row; column++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
