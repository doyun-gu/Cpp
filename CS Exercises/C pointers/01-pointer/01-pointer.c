/*
Consider the following program:

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    return a + b;
}

int main(int argc, char **argv) {
    if(argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        printf("%d + %d = %d\n", a, b, add(a, b));
    }
    return 0;
}

Modify the function add and its invocation so that it takes two int pointer parameters. Examples of output:

./pointer 10 20
10 + 20 = 30

./pointer 154 -12
154 + -12 = 142
*/

#include <stdio.h>
#include <stdlib.h>

int add(int *a, int *b) {
    return *a + *b;
}

int main(int argc, char **argv) {
    if(argc == 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        printf("%d + %d = %d\n", a, b, add(&a, &b));
    }
    
    return 0;
}
