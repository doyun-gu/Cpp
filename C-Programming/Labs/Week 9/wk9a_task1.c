/*
Write a simple program that declares a structure s with one char variable and one
int variable, both un-initialized. What do you think is the size occupied by this
structure? Test your prediction using the following statement:
printf("sizeof structure s = %ld\n", (unsigned long) sizeof(s));
Does the result meet your expectation? If there is a difference, can you think of an
explanation?
*/

/* Lab 9a Task1 Solution */

/* Write a simple program that declares a structure s with one char variable and one int variable, 
   both un-initialized. What do you think is the size occupied by this structure? Test your prediction 
   using the following statement:
		printf("sizeof structure s = %ld\n", (unsigned long) sizeof(s));
   Does the result meet your expectation? If there is a difference, can you think of an explanation?
   
   A. The result is likely to be eight bytes.
      A char occupies one byte and an int occupies four bytes, making a total of five bytes.
      However many compilers will align data items along multiples of bytes, leaving 'holes'
      if necessary in between. As a result sizeof(s) will be 8.

*/

#include <stdio.h>

int main(void)  {
   struct {
      char a;
      int i;
   } s;

   printf("sizeof structure s = %ld\n", (unsigned long) sizeof(s));

   return 0;
}
