/*
Fix the memory leak contained in the following program:

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int *a = malloc(10 * sizeof(int));
    if(!a) return -1;

    for(int i=0; i<10; i++)
        a[i] = i*2;

    int *b = a;

    for(int i=0; i<10; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

The expected output is:

./malloc3
0 2 4 6 8 10 12 14 16 18
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int *a = malloc(10 * sizeof(int));
    if(!a) return -1;

    for(int i=0; i<10; i++)
        a[i] = i*2;

    int *b = a;

    for(int i=0; i<10; i++)
        printf("%d ", b[i]);
    printf("\n");

    free (a);

    return 0;
}
