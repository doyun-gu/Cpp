/*
Write a C program reading a double with scanf and asking the user if he wants this number to be floored or ceiled. 
Next, the program performs the requested operation and displays the result. 

Output examples:

./math
Input a number:
12.4
Input 0 for ceil, 1 for floor
0
13.000000

./math
Input a number:
45.87
Input 0 for ceil, 1 for floor
1
45.000000
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    double input, result;
    int command;

    printf("Input a number: \n");
    if(scanf("%lf", &input) != 1) {
        printf("Invalid input");
        return -1;
    }

    printf("Input 0 for ceil, 1 for floor\n");
    if(scanf("%d", &command) != 1) {
        printf("Invalid command");
        return -1;
    }

    if (command == 1) {
        result = floor(input);
    }
    else if (command == 0) {
        result = ceil(input);
    }
    else {
        printf("Invalid command");
        return -1;
    }

    printf("%lf\n", result);

    return 0;
}
