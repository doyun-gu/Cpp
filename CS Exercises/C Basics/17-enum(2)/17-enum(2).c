/*
Enumerations can be used in C in combination with bitwise operations to define flags, 
i.e. set of properties attached to objects, each object being able to have 0 or several properties enabled.

Consider the following program:

#include <stdio.h>

typedef enum {
    // define FLAG1, FLAG2, FLAG3, FLAG4
} flags;

void print_flags(flags f) {

    if(f & FLAG1)
        printf("FLAG1 enabled\n");
    if(f & FLAG2)
        printf("FLAG2 enabled\n");
    if(f & FLAG3)
        printf("FLAG3 enabled\n");
    if(f & FLAG4)
        printf("FLAG4 enabled\n");
}

int main(int argc, char **argv) {
    flags f1 = FLAG1 | FLAG2;
    flags f2 = FLAG1 | FLAG2 | FLAG3;

    printf("f1:\n");
    print_flags(f1);

    printf("f2:\n");
    print_flags(f2);

    return 0;
}

The goal of the exercise is to write the definition of flags so that the program behaves correctly, 

i.e. it should produce the following output:

./enum2
f1:
FLAG1 enabled
FLAG2 enabled
f2:
FLAG1 enabled
FLAG2 enabled
FLAG3 enabled
*/

#include <stdio.h>

typedef enum {
    FLAG1 = 1, // Binary: 0001
    FLAG2 = 2, // Binary: 0010
    FLAG3 = 4, // Binary: 0100
    FLAG4 = 8  // Binary: 1000
} flags;

void print_flags(flags f) {
    if(f & FLAG1)
        printf("FLAG1 enabled\n");
    if(f & FLAG2)
        printf("FLAG2 enabled\n");
    if(f & FLAG3)
        printf("FLAG3 enabled\n");
    if(f & FLAG4)
        printf("FLAG4 enabled\n");
}

int main(int argc, char **argv) {
    flags f1 = FLAG1 | FLAG2;
    flags f2 = FLAG1 | FLAG2 | FLAG3;

    printf("f1:\n");
    print_flags(f1);

    printf("f2:\n");
    print_flags(f2);

    return 0;
}
