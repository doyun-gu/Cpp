/*
This code takes 3 arguments (first: Weight on the start day, second: Weight the day before, third: Today's Weight)
Then calculates Total weight lost in kg and % and weight difference between a day before and today. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {
    if (argc != 4) {
        printf("Please put 3 arguments!");

        return -1;
    }

    double sweight = atof(argv[1]);
    double bweight = atof(argv[2]);
    double tweight = atof(argv[3]);

    double total_dweight = sweight - tweight;
    double dweight = bweight - tweight;

    double total_rate = total_dweight * 100 / sweight;

    printf("Total Lost: %.2lf kg and this is %.2lf %%\n", total_dweight, total_rate);
    printf("Day Lost: %.2lf kg\n", dweight);

    return 0;
}
