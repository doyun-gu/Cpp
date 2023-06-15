/* Lab 8a Task3 Solution */

/* Given the following statements:

    char date[] = {'J','u','l','y','\x20','1','4','\x20','i','s','\x20','a',
                   '\x20','f','a','m','o','u','s','\x20','d','a','y','!','\0'};
    char *p = date;
    int i;
    
    ..where '\x20' is the hex representation of the space character

   (a) Write a for loop to print out each character of the array
       using only'date' (i.e. not p).
       
   (b) Write a for loop to do the same using only p (i.e. not 'date').
   
   (c) write both (a) and (b) using while loops.

*/

#include <stdio.h>

int main(void)  {

    /* write the code in the space below and test */
    char date[] = {'J','u','l','y','\x20','1','4','\x20','i','s','\x20','a',
                   '\x20','f','a','m','o','u','s','\x20','d','a','y','!','\0'};
    char *p = date;
    int i;

    /* (a) for loop with 'date' only: */
    for (i=0; date[i]!='\0'; i++) {
      printf("%c", date[i]);
    }

    printf("\n"); /* blank line */

    /* (b) for loop with p only: */
    for (i=0; *p!='\0';) {
      printf("%c", *p++);
    }

    printf("\n"); /* blank line */

    /* (c) writing both (a) and (b) as while loops: */
    p = date;   /* re-initialise p */
    while (*p)
      printf("%c", *p++);

    printf("\n"); /* blank line */

    i = 0;  /* re-initialise i */
    while (date[i])
      printf("%c", date[i++]);

    return 0;
}
