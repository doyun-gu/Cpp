/* Lab 8b Task 1 Solution */

/* The following program supposedly creates an identical copy of a string
   entered by the user. It relies on a function called 'duplicate' which is incomplete.
   The program is also incomplete in a number of other ways.
   Fix it so that it works!

*/

#include <stdio.h>
#include <string.h>  /* needed for strcpy */
#define N 100

/* function 'duplicate' prototype: */
char * duplicate (const char *p, char *q);

int main(void)  {

    /* write the code below and test */
    char str1 [N], str2[N];
    char ch;
    int i=0;
    printf("\n\n Enter some text: "); /* blank line */
    while ((ch = getchar()) != '\n')	{
        str1[i++] = ch;
    }
    str1[i] = '\0';
    
    /* declare char pointer p and initialise it to
       the value returned by a call to duplicate that 
       copies str1 to str2:
    */
    char *p = duplicate(str1, str2);

    /* while loop that uses p to check that duplicate worked
       and str2 contains a copy by printing it out character by character:
    */
    while (*p)
        printf("%c", *p++);

    return 0;
}

char * duplicate (const char *p, char *q)     {
  strcpy(q,p);
  return q;
}
