/*
Write a C program taking an integer n as command line parameter, allocating an array of integer of size n, 
and filling that array with random integers -- each between 0 and 100. 

Next, a second array of size n is created and the content of the first array is copied into the second one with a single call to memcpy. 
FInally, both arrays are printed. 

Example output:

./memcpy 10
array1: 32 32 54 12 52 56 8 30 44 94
array2: 32 32 54 12 52 56 8 30 44 94

./memcpy 15
array1: 32 32 54 12 52 56 8 30 44 94 44 39 65 19 51
array2: 32 32 54 12 52 56 8 30 44 94 44 39 65 19 51
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {

    if (argc != 2) {

        printf("Error!: Only one Argument!");

        return -1;
    }

    // Declare Array
    int *array1, *array2;

    // Set Array 1
    int n = atoi(argv[1]);

    array1 = malloc(n * sizeof(int));

    // fill random number (0-100)
    for (int i=0; i<n; i++) {

        // set random number between 0 to 100
        array1[i]=rand()%101;

    }

    array2 = malloc(n * sizeof(int));

    // copy array1 to array2
    memcpy(array2, array1, n * sizeof(int));

    // print array1
    printf("array1: ");

    for (int i=0; i<n; i++) {
        printf("%d ", array1[i]);
    }

    printf("\n");

    // print array2
    printf("array2: ");

    for (int i=0; i<n; i++) {
        printf("%d ", array2[i]);
    }

    printf("\n");

    free(array1);
    free(array2);

    return 0;
}
