/*
Download the file Lab_6a_Task4 from Blackboard and complete the instructions given in the comments
*/

/* Lab 6a Task 4 Solution */

/*  A program that uses a function to return the number of
    positive integers greater than 50.

    The main function populates an array with ten random numbers
    between 1 and 100. It then calls a function to add up the number
    of elements in the array whose value is greater than 50.
    The program prints out the number returned by the function.

    Your task is to write the function, whose prototype is:
              int num_pos(int a[],int n);
*/

#include <stdio.h>
#include <stdlib.h>   /* needed for rand(0 and srand() functions */
#include <time.h>  /* needed for time() function */

int num_pos(int a[], int n);

int main(void) {
    int a[10];   /* declare a ten-element array */
    int n = 10;  /* number of elements in a */
    srand((unsigned)time(NULL));    /* "seed" the pseudo-random number generator */
    printf("\n Pseudo-random numbers:\n");
    /* populate a with 10 pseudo-random numbers: */
    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;
        printf(" %d, ", num);
        a[i] = num;
    }

    printf("\n\n The number of elements greater than 50 is %d\n",
        num_pos(a, n));

    return 0;
} /* end main */

int num_pos(int a[], int n) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] > 50) {
            total++;
        }
    }
    return total;
} /* end num_pos */
