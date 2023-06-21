/*
The program below prints the dimensions of a rectangle passed from the command line arguments:

#include <stdio.h>
#include <stdlib.h>

struct s_rectangle {
    unsigned long long int width;
    unsigned long long int length;
};

void print_rectangle(struct s_rectangle r) {
    printf("Rectangle is %llu x %llu\n", r.width, r.length);
}

int main(int argc, char **argv) {
    struct s_rectangle r;
    unsigned long long int width;
    unsigned long long int length;

    if(argc == 3) {
        width = atoll(argv[1]);
        length = atoll(argv[2]);

        r.width = width;
        r.length = length;

        print_rectangle(r);
    }

    return 0;
}

Modify this program to use typedef to alias:

    struct s_rectangle into rectangle
    unsigned long long int into ull

*/

#include <stdio.h>
#include <stdlib.h>

/* unsigned long long int into ull */
typedef unsigned long long int ull;

struct s_rectangle {
    ull width;
    ull length;
};

/* s_rectangle into rectangle */
typedef struct s_rectangle rectangle;

void print_rectangle(rectangle r) {
    printf("Rectangle is %llu x %llu\n", r.width, r.length);
}

int main(int argc, char **argv) {
    rectangle r;
    ull width;
    ull length;

    if(argc == 3) {
        width = atoll(argv[1]);
        length = atoll(argv[2]);

        r.width = width;
        r.length = length;

        print_rectangle(r);
    }

    return 0;
}
