/*
Write a C program taking an integer as parameter and printing a right-angled triangle on the command line which legs size is defined by the integer parameter. Here are some examples of execution:

./triangle 2
*
**

./triangle 5
*
**
***
****
*****

./triangle 15
*
**
***
****
*****
******
*******
********
*********
**********
***********
************
*************
**************
***************
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    if (argc == 1) {
        printf("Please put any Parameter!");

        return -1;
    }

    int n = atoi(argv[1]);

    for (int i=1; i<=n; i++) {

        for (int j=1; j<=i; j++) {
            printf("*");
        }

        printf("\n");
    }
    
    return 0;
}
