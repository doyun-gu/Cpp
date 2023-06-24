/*
This is a variation of a previous exercise targetting file I/O. 
The goal is similar: write a C program taking as command line parameter A) a file name f and B) a word w. 
The program then creates the file f-processed which is a copy of f where all occurences of the word w have been deleted. 
This time, you should use the stream-based file I/O functions (fopen, fread, and fwrite) to write the program.

Here is an example of execution:

cat sample-file-1
hello world
this is a test file containing the word hello several times
some lines do not contain that word
while others do: hello

./stream sample-file-1 hello

cat sample-file-1-processed
 world
this is a test file containing the word  several times
some lines do not contain that word
while others do: 

You download sample-file-1 here.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

void remove_word_from_line(char* line, const char* word) {
    char* occurrence;
    while ((occurrence = strstr(line, word)) != NULL) {
        // remove effectively the word by shifting using 'memmove' function
        memmove(occurrence, occurrence + strlen(word), 1 + strlen(occurrence + strlen(word))); //strlen returns length of the word
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    char* word = argv[2];

    char processed_filename[MAX_LINE_LEN];
    // set output file name
    snprintf(processed_filename, MAX_LINE_LEN, "%s-processed", filename);

    FILE* source_file = fopen(filename, "r");
    if (source_file == NULL) {
        printf("Cannot open source file %s\n", filename);
        return 1;
    }

    FILE* dest_file = fopen(processed_filename, "w");
    
    if (dest_file == NULL) {
        printf("Cannot open destination file %s\n", processed_filename);
        return 1;
    }

    // read the file line by line and write the removed line to the processed file
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, source_file)) {
        remove_word_from_line(line, word);
        fputs(line, dest_file);
    }

    // close the file
    fclose(source_file);
    fclose(dest_file);

    return 0;
}
