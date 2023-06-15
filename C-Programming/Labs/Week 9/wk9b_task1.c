/*
Write a program that declares a union called ‘info’ to store the following, uninitialized, data:
char c
int integer
unsigned int u_integer
long long_int
unsigned long u_long_int
float f
double d
long double l_d

Add a statement that prints out the size of the union, and make sure you can explain your result.
*/

/* Lab 9b Task1 Solution */

#include <stdio.h>

int main(void)
{
  union {
    char ch;
    int integer;
    unsigned int u_integer;
    long long_int;
    unsigned long u_long_int;
    float f;
    double d;
    //long double l_d;
  } info;
  
  printf ("The sizeof the union = %ld\n", (unsigned long) sizeof (info));
  /* result is 16 bytes (128 bits) -the size of long double on a typical machine */


  return 0;
}
