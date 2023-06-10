/*
Write a program that stores the following data in a 2-dimensional array:

8, 16, 9, 52
3, 15, 27, 6
14, 25, 2, 10

The program should sum the elements and print out the total. Hint: use nested forloops.

*/

#include <stdio.h>

int main(void) {

    int multi[3][4] = { {8, 16, 9, 52},
                        {3, 15, 27, 6},
                        {14, 25, 2, 10}
    };

    int row, column, sum = 0;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 4; column++) {
            sum += multi[row][column];
        } /* end inner for loop */
    } /* end outer for loop */

    printf("sum = %d\n", sum);

    return 0;
}
