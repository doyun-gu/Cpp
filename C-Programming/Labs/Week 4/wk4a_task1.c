/*
Task 1
Write a program that uses a while loop to find the largest in a series of numbers
entered by the user. The program prompts the user to enter numbers one by one,
until 0 or a negative value is entered; it then prints out the largest number entered.

Example output:
Enter a number: 50
Enter a number: 27.4
Enter a number: 98.42
Enter a number: 98.41
Enter a number: 0
The largest number entered was 98.42
*/

#include <stdio.h>
int main(void)
{
 double x, max = 0.0f;
 while (1) {
     printf("Enter a number: ");
     scanf("%lf", &x);

     if (x <= 0.0)
        break;

     if (x > max)
        max = x;
     }
 printf("\n"); /* blank line */
 printf("The largest number entered was %g\n", max);

 return 0;
}
