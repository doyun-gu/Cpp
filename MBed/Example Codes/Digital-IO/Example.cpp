/*
EEEN20011 - Lecture 3 Example Program

This program uses the Nucleo-64 board only. The Application Shield should not be plugged in.
The program turns the on-board led (LD2) on whenever the button B1 is pressed.

*/

#include "mbed.h"       // Imports mbed libraries - allows us to use DigitalOut and DigitalIn


DigitalIn PB(PC_13);    // Sets up a digital input attached to the blue 'user' push button
DigitalOut led(PA_5);   // Sets up a digital output connected to on-board LD2

int main()
{
    led = 0;            // Turn led off when program starts
    while(1) {          // Loops infinitely - IMPORTANT
        while (!PB) {   // Checks if the button has been pressed
            led = 1;    // If the button is pressed, the LED is turned on
        }
        led = 0;        // Otherwise the LED is turned off
    }
}
