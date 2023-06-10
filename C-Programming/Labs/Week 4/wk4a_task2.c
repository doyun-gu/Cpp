/*
Task 2 If working together, compare your individual solutions when you finish the task.

Using
a) a while loop
b) a do loop
c) a for loop

write a program that prints out the first twelve powers of two.
Example output:

2^0=1
2^1=2
2^3=8
2^4=16
2^5=32
2^6=64
2^7=128
2^8=256
2^9=512
2^10=1024
2^11=2048
*/

#include <stdio.h>

int main(void) {

    /* a) Using a while loop: */
    int i = 0, result = 1;
    while (i < 12) {
        //printf("2^%d =\t%d\n", i, i*=2);
        printf("2^%d =\t%d\n", i, result);
        result = result * 2;
        i++;
    }


    /* b) Using a do loop: */
    /* reset the values of i and 'result': */
    i = 0;
    result = 1;
    printf("\nUsing a do loop:\n");
    do {
        printf("2^%d =\t%d\n", i, result);
        result = result * 2;
        i++;
    } while (i < 12);


    /* c) Using a for loop: */
    /* reset the value of 'result': */
    result = 1;
    printf("\nUsing a for loop:\n");
    for (i = 0; i < 12; i++) {
        printf("2^%d =\t%d\n", i, result);
        result = result * 2;
    }



    return 0;
}
