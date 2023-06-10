/*
Download Lab_3a_Task2.c from Blackboard and complete the instructions given in the comments. 
Try to predict the results before compiling and running the program.
*/
#include <stdio.h>

int main(void) {

    /* Step a):
       Declare and assign two variables i=7 and j=8 and
       try to predict the result of: i *= j + 1;
       Test your prediction with a suitable printf statement. */
    int i = 7, j = 8;
    printf("Start with: i=%d, j=%d\n", i, j);
    printf("i *= j + 1 = %d\n", i *= j + 1);
    /* a *= b + c is equivalent to
           a = a * (b + c)
           and not
           a = a * b + c
    */

    /* Step b):
       Declare a third int variable k; assign 1 to i, j and k.
       try to predict the result of: i += j += k;
       Test your prediction with a suitable printf statement. */
    int k;
    i = 1, j = 1, k = 1;
    printf("\nStart with: i=%d, j=%d, k=%d\n", i, j, k);
    i += j += k;
    printf("i += j += k results in: i=%d j=%d k=%d\n", i, j, k);

    /* Step c):
       Next assign i=1, j=2 and k=3.
       Try to predict the result of: i -= j -= k;
       Test your prediction with a suitable printf statement. */
    i = 1, j = 2, k = 3;
    printf("\nStart with: i=%d, j=%d, k=%d\n", i, j, k);
    i -= j -= k;
    printf("i -= j -= k results in: i=%d j=%d k=%d\n", i, j, k);

    /* Step d):
       Next assign i=2 and j=1 and k=0.
       Try to predict the result of: i *= j *= k;
       Test your prediction with a suitable printf statement. */
    i = 2, j = 1, k = 0;
    printf("\nStart with: i=%d, j=%d, k=%d\n", i, j, k);
    i *= j *= k;
    printf("i *= j *= k results in: i=%d j=%d k=%d\n", i, j, k);

    /* Step e):
       Next assign i=6 and try to predict the result of:
       j = i += i;
       Test your prediction with a suitable printf statement. */
    i = 6;
    printf("\nStart with: i=%d, j=%d\n", i, j);
    j = i += i;
    printf("j = i += i results in: i=%d j=%d\n", i, j);

    /* Step f):
       Next assign i=5 and try to predict the result of:
       j = (i -= 2) + 1;
       Test your prediction with a suitable printf statement. */
    i = 5;
    printf("\nStart with: i=%d, j=%d\n", i, j);
    j = (i -= 2) + 1;
    printf("j = (i -= 2) + 1 results in: i=%d j=%d\n", i, j);

    /* Step g):
       Next assign i=7 and try to predict the result of:
       j = 6 + (i = 2.5);
       Test your prediction with a suitable printf statement. */
    printf("\nStart with: i=%d, j=%d\n", i, j);
    j = 6 + (i = 2.5);
    printf("j = 6 + (i = 2.5) results in: i=%d j=%d\n", i, j);

    /* Step h):
       Finally assign i=2 and j=8, and try to predict the result of:
       j = (i = 6) + (j = 3);
       Test your prediction with a suitable printf statement. */
    printf("\nStart with: i=%d, j=%d\n", i, j);
    j = (i = 6) + (j = 3);
    printf("j = (i = 6) + (j = 3) results in: i=%d j=%d\n", i, j);


    return 0;
}
