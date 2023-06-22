/*
Write a C program that takes two integer as command line parameter, x and y, 
and prints on the standard output y lines of x integers corresponding to the first (x * y) natural integers. 
The numbers should be stored in a 2-dimensional array allocated with malloc before being printed.

# 3 rows, 4 columns
./malloc2 3 4
0 1 2 3
4 5 6 7
8 9 10 11

./malloc2 2 5
0 1 2 3 4
5 6 7 8 9

./malloc2 10 11
0 1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20 21
22 23 24 25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40 41 42 43
44 45 46 47 48 49 50 51 52 53 54
55 56 57 58 59 60 61 62 63 64 65
66 67 68 69 70 71 72 73 74 75 76
77 78 79 80 81 82 83 84 85 86 87
88 89 90 91 92 93 94 95 96 97 98
99 100 101 102 103 104 105 106 107 108 109
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

    if (argc != 3) {
        printf("Error! Please enter exactly two command line arguments.\n");
        return -1;
    }

    int row_size = atoi(argv[1]);
    int column_size = atoi(argv[2]);

    int **array = malloc(row_size * sizeof(int *));
    
    for(int i = 0; i < row_size; i++)
        array[i] = malloc(column_size * sizeof(int));

    // Fill the array with the first (x * y) natural integers.
    int count = 0;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < column_size; j++) {
            array[i][j] = count++;
        }
    }

    // Print the array.
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < column_size; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the memory.
    for(int i = 0; i < row_size; i++)
        free(array[i]);
    free(array);

    return 0;
}
