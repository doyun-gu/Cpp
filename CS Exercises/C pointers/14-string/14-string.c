/*
Write a C program reading a string from the standard input and capitalize the first letter of each word.

./string2
input a string:
we swears, to serve the master of the precious
We Swears, To Serve The Master Of The Precious

./string2
input a string:
and following our will and wind we may just go where no one's been
And Following Our Will And Wind We May Just Go Where No One's Been
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[256];
    char* words;
    const char s[2] = " ";


    printf("input a string: ");
    fgets(input, sizeof(input), stdin);

    // strtok function to split the string into words
    words = strtok(input, s);

    while(words != NULL) {
        // Capitalize the first letter of each word
        words[0] = toupper(words[0]);

        // Print the word and add a space at the end
        printf("%s ", words);

        // Continue to the next word
        words = strtok(NULL, s);
    }

    printf("\n"); // Print a newline after the output
    return 0;
}
