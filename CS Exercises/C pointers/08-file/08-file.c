/*
Write a C program taking as command line parameter A) a file name f and B) a word w. 
The program then creates the file f-processed which is a copy of f where all occurences of the word w have been deleted. 

Here is an example of execution:

cat sample-file-1
hello world
this is a test file containing the word hello several times
some lines do not contain that word
while others do: hello

./file sample-file-1 hello

cat sample-file-1-processed
 world
this is a test file containing the word  several times
some lines do not contain that word
while others do: 
*/

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <strsafe.h>

#define BUFFER_SIZE 2048

// Remove all instances of 'word' from 'str'
void removeWord(char* str, const char* word) {
    char* found;
    int len = strlen(word);
    while ((found = strstr(str, word)) != NULL) {
        memmove(found, found + len, 1 + strlen(found + len));
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    char newfilename[MAX_PATH];
    DWORD bytesRead, bytesWritten;

    // Copy filename
    if (FAILED(StringCbCopy(newfilename, sizeof(newfilename), argv[1]))) {
        printf("Error copying filename\n");
        return -1;
    }

    // Append "-processed" to the filename
    if (FAILED(StringCbCat(newfilename, sizeof(newfilename), "-processed"))) {
        printf("Error concatenating strings\n");
        return -1;
    }

    // Open the original file for reading
    HANDLE hOldFile = CreateFile(argv[1], GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hOldFile == INVALID_HANDLE_VALUE) {
        printf("Unable to open file %s for reading\n", argv[1]);
        return -1;
    }

    // Create the new file for writing
    HANDLE hNewFile = CreateFile(newfilename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hNewFile == INVALID_HANDLE_VALUE) {
        printf("Unable to open file %s for writing\n", newfilename);
        CloseHandle(hOldFile);
        return -1;
    }

    // Read from the old file, remove the word, and write to the new file
    while (ReadFile(hOldFile, buffer, BUFFER_SIZE - 1, &bytesRead, NULL) && bytesRead > 0) {
        buffer[bytesRead] = '\0';  // Null-terminate the string
        removeWord(buffer, argv[2]);
        if (!WriteFile(hNewFile, buffer, bytesRead, &bytesWritten, NULL)) {
            printf("Error writing to file\n");
            break;
        }
    }

    CloseHandle(hOldFile);
    CloseHandle(hNewFile);
    return 0;
}
