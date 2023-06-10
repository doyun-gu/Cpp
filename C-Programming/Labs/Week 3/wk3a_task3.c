/*
Download Lab_3a_ Task3.c from Blackboard and complete the instructions given in the comments. 
Try to predict the results before compiling and running the program.
*/

#include <stdio.h>

int main(void) {

    /* Step a):
       Declare two int variables i and j, and assign 1 to i.
       Try to predict the result of:
       j = i++ - 1;
       Test your prediction with a suitable printf statement. */
    int i = 1, j;
    printf("Start with: i=%d\n", i);
    j = i++ - 1;
    printf("j = i++ - 1 results in i=%d j=%d\n", i, j);

    /* Step b):
       Declare a third int variable k.
       Assign i=10 and j=5, and try to predict the result of:
       j = i++ - ++j;
       Test your prediction with a suitable printf statement. */
    int k;
    i = 10, j = 5;
    printf("\nStart with: i=%d, j=%d\n", i, j);
    k = i++ - ++j;
    printf("k = i++ - ++j results in i=%d j=%d k=%d\n", i, j, k);

    /* Step c):
       Next assign i=7 and j=8, and try to predict the result of:
       k = i++ - --j;
       Test your prediction with a suitable printf statement. */
    i = 7, j = 8;
    printf("\nStart with: i=%d, j=%d\n", i, j);
    k = i++ - --j;
    printf("i++ - --j results in i=%d j=%d k=%d\n", i, j, k);


    /* Step d):
       Declare a fourth int variable p, and assign i=2 and j=1 and k=5.
       Try to predict the result of:
       p = i++ - j++ + --k;
       Test your prediction with a suitable printf statement. */
    int p;
    i = 2, j = 1, k = 5;
    printf("\nStart with: i=%d, j=%d, k=%d\n", i, j, k);
    p = i++ - j++ + --k;
    printf("p = i++ - j++ + --k results in i=%d j=%d k=%d p=%d\n", i, j, k, p);


    /* Step e):
       Next assign i=5 and try to predict the result of:
       j = ++i * 3 - 2;
       Test your prediction with a suitable printf statement. */
    i = 5;
    printf("\nStart with: i=%d\n", i);
    j = ++i * 3 - 2;
    printf("j = ++i * 3 - 2 results in i=%d j=%d\n", i, j);

    /* Step f):
       Next assign i=5 and try to predict the result of:
       j = 3 - 2 * i++;
       Test your prediction with a suitable printf statement. */
    i = 5;
    printf("\nStart with: i=%d\n", i);
    j = 3 - 2 * i++;
    printf("j = 3 - 2 * i++ results in i=%d j=%d\n", i, j);


    /* Step g):
       Next assign i=7 and try to predict the result of:
       j = 3 * i-- + 2;
       Test your prediction with a suitable printf statement. */
    i = 7;
    printf("\nStart with: i=%d\n", i);
    j = 3 * i-- + 2;
    printf("j = 3 * i-- + 2 results in i=%d j=%d\n", i, j);

    /* Step h):
       Finally assign i=7 and try to predict the result of:
       j = 3 + --i * 2;
       Test your prediction with a suitable printf statement. */
    i = 7;
    printf("\nStart with: i=%d\n", i);
    j = 3 + --i * 2;
    printf("j = 3 + --i * 2 results in i=%d j=%d\n", i, j);


    return 0;
}
