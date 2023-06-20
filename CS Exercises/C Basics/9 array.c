/*
Write a program that takes up to 10 integers as command line parameters. These parameters are converted to integer types into an array of int named array. 
Then, the program sorts the array by increasing value and prints the resulat as follows:

./array 5 4 6 2 1 3 
1 2 3 4 5 6

./array 5 5 120
5 5 120
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare two elements for qsort
int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main(int argc, char *argv[]) {
    if (argc > 11) {
        printf("Error: Too many input parameters. Maximum is 10 integers.\n");
        return 1;
    }

    int array[10];
    int array_size = argc - 1; // Subtracting 1 to exclude the program name from the arguments.

    // Convert command line arguments to integers and populate the array.
    for (int i = 0; i < array_size; i++) {
        array[i] = atoi(argv[i + 1]);
    }

    // Sort the array in ascending order.
    qsort(array, array_size, sizeof(int), compare);

    // Print the sorted array.
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
