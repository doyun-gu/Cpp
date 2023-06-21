/*
Write a simple program printing the size of 
1. int variables, 
2. followed on the next line by the size of double variables, 
3. followed on a third line by the size of unsigned long long int variables. 
4. On a last line, print the value of the multiplication of these 3 sizes. 

The expected output (on a modern 64 bits machine) is:
4
8
8
256
*/

# include <stdio.h>
int main (void) {
    int a = 5;
    double b = 5;
    unsigned long long int c = 5;

    printf("%d\n", sizeof a);
    printf("%d\n", sizeof b);
    printf("%d\n", sizeof c);
    printf("%d\n", sizeof a * sizeof b * sizeof c);

    return 0;
}
