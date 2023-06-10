/*
Download the file Lab_3b _Task1 from Blackboard and complete the instructions given in the comments.
*/

#include <stdio.h>
int main(void) {

    //use the following variables as directed in each of the steps below:
    int a = 2, b = 3, c = 0, d = 9, p = 3, m = 7, r;


    /* Step a):
       Replace the following nested if statement with a single
       equivalent expression using the conditional operator:
       if (a > b)
          r = p;
       else
          r = m;
       printf("r = %d\n", r);   */
       //<write the code here, and test it with different values of a>
    r = a > b ? p : m;
    printf("r = %d\n", r);

    /* Step b):
       Replace the following nested if statement with a single
       equivalent expression using the conditional operator:
       if (a < d)
          r = b;
       else if (b < c)
          r = p;
       else
          r = m;
       printf("m = " %d\n", m);   */
       //<write the code here, and test it with different values of a>
    r = a < d ? b : (b < c ? p : m);
    printf("r = %d\n", r);

    /* Step c):
       Replace the following expressions with equivalent if else statements:
       r = a > b ? 1 : 0;
       printf("r = %d\n", r);        */
       //<write the code here, and test it with different values of a>
    if (a > b)
        r = 1;
    else
        r = 0;
    printf("r = %d\n", r);

    /* Step d):
       Replace the following expressions with equivalent if else statements:
       r = a > b ? (b < c ? a : b) : d;
       printf("r = %d\n", r);   */
       //<write the code here, and test it with different values of a>
    if (a > b)
        if (b < c)
            r = a;
        else
            r = b;
    else
        r = d;
    printf("r = %d\n", r);

    return 0;
}
