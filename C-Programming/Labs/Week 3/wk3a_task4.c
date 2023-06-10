/*
Download the file Lab_3a_Task4 from Blackboard and complete the instructions given in the comments. 
Try to predict the results before compiling and running the program. 
Remember that in C true and false are represented by integers: 'true' is 1, and 'false' is 0.
*/
#include <stdio.h>

int main(void) {

    /* Step a):
       Declare and assign variables i=2, j=3 and k (unassigned)
       try to predict the result of the expression:
       k = i * j == 6
       Test your prediction with a suitable printf statement. */
    int i = 2, j = 3, k;
    printf("k = %d * %d == 6 evaluates to %d\n", i, j, k = i * j == 6);

    /* Step b):
       Next assign i=5, j=10 and k=1.
       Try to predict the result of the expression:
       k > i < j
       Test your prediction with a suitable printf statement. */
    i = 5, j = 10, k = 1;
    printf("%d > %d < %d evaluates to %d\n", k, i, j, k > i < j);

    /* Step c):
       Next assign i=3, j=2 and keep k=1.
       Try to predict the result of the expression:
       (i < j) == (j < k)
       Test your prediction with a suitable printf statement. */
    i = 3, j = 2;
    printf("(%d < %d) == (%d < %d) evaluates to %d\n", i, j, j, k, (i < j) == (j < k));

    /* Step d):
       Next keep i=3 and assign j=4 and k=5.
       Try to predict the result of the expression:
       i % j + i < k
       Test your prediction with a suitable printf statement. */
    j = 4, k = 5;
    printf("%d \%% %d + %d < %d evaluates to %d\n", i, j, i, k, i % j + i < k);

    return 0;
}
