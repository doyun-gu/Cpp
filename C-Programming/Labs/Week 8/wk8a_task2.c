/* 
Suppose that p has been declared as follows:

char *p = "abc";

Which of the following calls would you predict to be legal? Write a simple program to test your prediction for each one. 
*/

/* Lab 8a Task2 Solution */

/* Given that p has been declared as follows:
         char *p = "abc";
   this program tests each of the following to verify 
   if they are legal calls, or not.
   (a)	putchar(p);
   (b)	putchar(*p);
   (c)	puts(p);
   (d)	puts(*p);
*/

#include <stdio.h>

int main(void)  {

    char *p = "abc";
    
    // putchar(p);  -illegal since p is not a character.
    // putchar(*p); -legal: output is a.
    // puts(p);     -legal: output is abc.
    // puts(*p);    -illegal; *p is not a pointer.

    return 0;
}
