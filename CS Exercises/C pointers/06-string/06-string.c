/*
Write a C program reading two strings from the standard input using fgets, and indicating if the strings are similar or not. Output examples:

./string
input string1:
test
input string2:
test
strings are similar

./string
input string1:
hello world!
input string2:
goodbye
strings are different
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main (void) {

    char *input1, *input2;

    input1 = malloc(MAX);

    if (input1 == NULL) {
        printf("Error!\n");
        return -1;
    }

    printf("input string1: ");
    fgets(input1, MAX, stdin);

    input2 = malloc(MAX);

    if (input2 == NULL) {
        printf("Error!\n");
        return -1;
    }

    printf("input string2: ");
    fgets(input2, MAX, stdin);

    // strcmp gives 0 when two strings are same.
    if (strcmp(input1, input2)==0) {
        printf("strings are similar!\n");
    }

    else {
        printf("strings are different!\n");
    }

    free(input1);
    free(input2);

    return 0;

}
