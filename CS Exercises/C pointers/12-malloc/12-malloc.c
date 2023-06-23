/*
Write a C program using malloc to allocate an array able to contain 10 int, fill this array with the 10 first natural number (starting with 0). 

Expected output:

./malloc4
0
1
2
3
4
5
6
7
8
9
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int *array = malloc (10*sizeof(int));

    if (array == NULL) {
        printf("Error!");
        return -1;
    }

    for (int i=0; i<10; i++){
        array[i] = i;
    }

    for (int i=0; i<10; i++) {
        printf("%d\n", array[i]);
    }

    free (array);

    return 0;
}
