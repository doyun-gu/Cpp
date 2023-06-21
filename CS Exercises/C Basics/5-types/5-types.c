/* 
The following code fails to compile due to a missing variable declaration:

#include <stdio.h>

int main() {

    variable = 10;

    printf("variable is %u\n", variable);

    return 0;
}

Edit the code to have it compile and run successfully. The expected output is:

variable is 10
*/

# include <stdio.h>

int main () {
    int variable = 10;

    printf("variable is %u\n", variable);    /* %u: unsigned int */

    return 0;
}
