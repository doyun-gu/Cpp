/*
Download Lab_3a_Task1.c from Blackboard and complete the instructions given in the comments. 
Try to predict the results before compiling and running the program.
*/

#include <stdio.h>

int main(void) {

    /* Step a):
       Declare and assign two variables i=5 and j=3 and try to predict the result of: i/j and i%j.
       Test your prediction with suitable printf statements. */
    int i = 5, j = 3;
    printf("i/j=%d i\%%j=%d\n", i / j, i % j);

    /* Step b):
       Next assign i=2 and j=3 and
       try to predict the result of: (i+10)%j.
       Test your prediction with a suitable printf statement. */
    i = 2, j = 3;
    printf("(2+10)\%%3=%d\n", (i + 10) % j);

    /* Step c):
       Next assign i=7 and j=8 and a third int variable k=9.
       Try to predict the result of: (i+10)%k/j.
       Test your prediction with a suitable printf statement. */
    i = 2, j = 3; int k = 9;
    printf("(2+10)\%%9/3=%d\n", (i + 10) % k / j);

    /* Step d):
       Next assign i=1 and j=2 and k=3.
       Try to predict the result of: (i+5)%(j+2)/k.
       Test your prediction with a suitable printf statement. */
    i = 1, j = 2, k = 3;
    printf("(i+5)\%%(j+2)/k=%d\n", (i + 5) % (j + 2) / k);

    return 0;
}
