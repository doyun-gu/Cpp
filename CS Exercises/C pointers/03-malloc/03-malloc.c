/*
Write a program taking a list of integers as command line parameters, storing them in an array allocated with malloc, and sorting that array in increasing order.

Output examples:

./malloc 5 4 3 2 1
1 2 3 4 5 

./malloc 546 874 18 13 87 54 4651 54 877 8 46351 87 654 657 654
8 13 18 54 54 87 87 546 654 654 657 874 877 4651 46351
*/

# include <stdio.h>
# include <stdlib.h>

int compare (const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main (int argc, char **argv) {
    
    int size = argc - 1;

    /* Allocate the spaces to store the integers (inputs) */
    int *array = malloc (size * sizeof(int));

    if (array == NULL) {

        return 1;

    }

    for (int i=0; i < size; i++) {

        array [i] = atoi(argv[i+1]);

    }
    
    qsort (array, size, sizeof(int), compare);

    for (int i=0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    /* Since we used 'malloc' */
    free (array);

    return 0;
}
