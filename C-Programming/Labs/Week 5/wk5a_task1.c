/*
Task 1
Download and complete Lab_5a_Task1.c from Blackboard and complete 
	– if working together, compare your individual solutions when you finish the task.
*/

#include <stdio.h>

int main(void) {


    /* Step a):
       What is printed out by the following statements?
            double pi = 22/7;
            printf("pi = %lf\n", pi);

       Test your prediction by compiling and running the program.
       Suppose that i and j are variables of type int.

       Using a type cast, modify the first statements so that "pi"
       includes a fractional part. */
       /*
       double pi = (double)22/7;
       printf("pi = %lf\n", pi);
       */


       /* Step b)
          Suppose now that i is of type int, j is of type long, and
          k is a variable of type unsigned int. What is the resulting type
          of the expression:   i + (int) j * k   ?
          Choosing simple values for i, j and k, test you prediction by
          writing some appropriate statements.
          Write your code below, and test the program.  */
          /*
          int i = 3;
          long j = 4;
          unsigned k = 5;
          printf("i + (int)j*k = %u\n", i + (int) j * k);
          // The resulting type is unsigned int.
          */




          /* Step c):
             Suppose next that f is a variable of type float, d is a variable
             of type double, and i is of type int as before. Explain what conversions
             take place during the execution of the following statement?
                               d = i + f;
             Choosing simple values for i and f, test you prediction by
             writing some appropriate statements.
             Write your code below, and test the program.  */
             /*
             float f = 3.2;
             int i = 3;
             double d = i + f;
             printf("d = %lf\n", d);
             // i is promoted to float, and the result is promoted to double
             // prior to the assignment
             */




             /* Step d)
                Suppose that the variables d and d_frac_part are both of type double,
                where d_frac_part contains the fractional part of d. Thus, for example
                d is 7.853 and d_frac_part is 0.853. Construct a statement that correctly
                assigns the fractional part of d to d_frac_part.
                Write your code below, and test the program>  */
                /*
                double d_frac_part, d = 7.853;
                d_frac_part = d - (int) d;
                printf("d_frac_part = %lf\n", d_frac_part);
                */




    return 0;
}
