/*
Write a program that uses the following function:

void get_extension (const char * file_name, char * extension)

where ‘file_name’ points to a string containing a file name. 

The function should store the extension on the file name in the string pointed to by ‘extension’. 
For example, if the file name is “note.txt”, the function will store “txt” in the string pointed to by ‘extension’. 
If the file name doesn’t have an extension, the function should store an empty string (a single null character) in the string pointed to by ‘extension’. 

Example output:
Enter a file name with an extension: note.txt
The extension is: txt
*/

/* Lab 8b Task 2 Solution */

/* A program that uses the following function:
        void get_extension (const char * file_name, char * extension)
   where 'file_name' points to a string containing a file name. 
   The function should store the extension on the file name in the string 
   pointed to by 'extension'. For example, if the file name is "note.txt", 
   the function will store "txt" in the string pointed to by 'extension'. 
   If the file name doesn't have an extension, the function should store
   an empty string (a single null character) in the string pointed to by 'extension'.

*/

#include <stdio.h>
#include <string.h>  /* needed for strcpy */
#define N 100

/* function 'get_extension' prototype: */
void get_extension(const char *file_name, char *extension);

int main(void)  {

    /* write the code below and test */
    char file_name [N], extension[N];
    char ch;
    int i=0;
    printf("\n\n Enter a file name with an extension: "); /* blank line */
    while ((ch = getchar()) != '\n')	{
        file_name[i++] = ch;
    }
    file_name[i] = '\0';

    /* call get_extension: */
    get_extension(file_name, extension);

    /* while loop to check that get_extension worked
       by printing it out character by character:
    */
    printf(" The extension is: ");
    char *p = extension;
    while (*p) {
        printf("%c", *p++);
    }
        printf("\n\n");
    return 0;
}

void get_extension(const char *file_name, char *extension) {
  /* can you see how this works? */
  char const *p = file_name + strlen(file_name);
  /* Why const? Because all the compiler is saying is:
    "Hey, you said to the caller 'I won't change anything',
    but you're opening up opportunities for that."
  */
  while (p-- > file_name) {
      if (*p == '.') {
          strcpy(extension, p + 1);
          return;
      }
  }
      *extension = '\0';
}
