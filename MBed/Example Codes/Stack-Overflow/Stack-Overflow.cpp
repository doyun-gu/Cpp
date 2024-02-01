/*
EEEN20011 - Lecture 20 Example Program

This program uses the Nucleo-64 board and the Application Shield.
The program is used to illustrate the difficulty in observing when a stack overflow 
occurs in embedded programming

The C12832 library is required - please see the instructions provided
for advice on how to include this in your project

The program generates two arrays, and performs modular division and random number generation
to generate a random number and print it on the LCD screen.
In its current format, the code will generate a runtime error when compiled and uploaded to
the Nucleo board. This is because second_array contains too many elements to accommodate on the
stack. If the values of 65536 are all significantly reduced (e.g. to 65) the program will execute

*/

#include "mbed.h"                       //Includes Mbed library
#include "C12832.h"                     //Includes the library for the LCD screen

C12832 lcd(D11, D13, D12, D7, D10);     //Creates an LCD Object from the LCD library

int main()
{
    char initial_array[32768];             //Create an array
    for (int ix = 0; ix < 32768; ix++) initial_array[ix] = ix; // Populate this array with values

    while (1) {
        wait(1.0);
        lcd.cls();                                                  //Clear the LCD screen
        lcd.locate(0,0);
        char second_array[65536];                                   // Create a second array
        for (int ix = 0; ix < 65536; ix++) second_array[ix] = ix;   // Populate this array with values

            // Perform random operations on the arrays to prevent them from being optimized away
        second_array[rand() % 65536] = initial_array[rand() % 32768];
        lcd.printf("Random Number: %d\n", second_array[rand() % 65536]);
    }
}
