/* 
The following program is supposed to print a line on the standard output but compilation fails due to several errors:

#include <tdio.h>

void man() {
    printf("This should work!\n");
    retur 0;
}

Correct the program to have it display the following output:
This should work!

*/

# include <stdio.h> /* tdio.h -> stdio.h */

void main () {

    printf("This should work!\n");

    /* Void does not have return value */

}
