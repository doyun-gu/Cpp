/*
Write a program that takes an integer as parameter and places it in a variable of type int. 

The program then proceeds to print the value as well as the address of the variable as follows:

./pointer3 5
Variable contains 5 and is located @0x7ffcc6d1d7fc

./pointer3 93
Variable contains 93 and is located @0x7fffec3b3dfc
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

    if (argc != 2) {
        printf("Please put one Argument!");
        return -1;
    }

    int var = atoi(argv[1]);

    printf("Variable contains %d and is located @%p", var, &var);

    return 0;
}
