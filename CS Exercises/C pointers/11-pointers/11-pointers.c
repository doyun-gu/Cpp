/*
Consider the following program printing a string to the standard output character by character:

#include <stdio.h>

int main(int argc, char **argv) {
    char *string = "hello, world!\n";

    int i = 0;
    while(string[i] != '\0')
        printf("%c", string[i++]);

    return 0;
}

Alter the loop so as to use a char * pointer as the iterator and as the way to access characters within the string for printing. 
The source code should contain no square bracket. 
The expected output is:

./pointer4
hello, world!
*/

#include <stdio.h>

int main(int argc, char **argv) {
    char *string = "hello, world!\n";

    for(char *p = string; *p != '\0'; p++) {
        printf("%c", *p);
    }

    return 0;
}
