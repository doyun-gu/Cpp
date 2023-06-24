/*
The program strtol.c converts a string entered by the user into an integer and prints it on the standard output. 
The conversion is realised with atoi, and as such it is not robust in case of malformed strings as well as under/overflows.

Modify the implementation of the function convert_and_print in this program to use strtol for the conversion rather than atoi, and make the program more robust against improper inputs. Output examples:

$ ./strtol
please enter an integer number (base 10): 1234
you have entered: 1234

$ ./strtol
please enter an integer number (base 10): foo
invalid string

$ ./strtol
please enter an integer number (base 10): 100000000000000000000
under/overflow

$ ./strtol 
please enter an integer number (base 10): -100000000000000000000
under/overflow
*/

#include <stdio.h>
#include <stdlib.h>
// for size of data type
#include <limits.h>
// to check range error
#include <errno.h>

void convert_and_print(const char* input_string) {
    char *end;
    errno = 0; /* To distinguish success/failure after call */
    long val = strtol(input_string, &end, 10);

    /* Check for various possible errors */
    if (/*checks overflow*/(errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || /*checks conversion error*/(errno != 0 && val == 0)) {
        printf("under/overflow\n");
        return;
    }

    if (end == input_string) {
        printf("invalid string\n");
        return;
    }

    /* If we got here, strtol() successfully parsed a number */
    printf("you have entered: %ld\n", val);
}


int main() {
    char buf[256];
    printf("please enter an integer number (base 10): ");
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printf("Error or end of input -- exiting\n");
        return 0;
    }
    convert_and_print(buf);
    return 0;
}
