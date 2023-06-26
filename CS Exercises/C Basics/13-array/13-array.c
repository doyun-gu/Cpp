/*
Write a program that takes up to 10 integers as command line parameters. 
These parameters are converted to integer types into an array of int named array. 

Then, the program iterates over the array and outputs if each number is even or odd as follows:

./array2 1 2 3 4 5 6 
1 is odd 
2 is even 
3 is odd 
4 is even 
5 is odd 
6 is even

./array2 5 5 120
5 is odd
5 is odd
120 is even
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char**argv) {

    if (argc == 1) {
        printf("No Argument!\n");
        return -1;
    }

    int n = argc-1;
    int *array = malloc (n*sizeof(int));

    for (int i=0; i<n; i++) {

        array[i]=atoi(argv[i+1]);
    }

    for (int i=0; i<n; i++) {
        if (array[i]%2==0) {
            printf("%d is even\n", array[i]);
        }
        
        else {
            printf("%d is odd\n", array[i]);
        }
    }

    free (array);
    return 0;
}
