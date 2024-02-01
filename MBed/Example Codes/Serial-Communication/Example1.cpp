/*
MCE - Lecture 18 Example Program 1

This program uses the Nucleo-64 board and the Application Shield.
The program uses the virtual serial port that the Nucleo creates when connected to a PC

An interrupt is attached to the centre pin of the joystick. When the button is pressed the ISR triggers.
The ISR sets the variable trigger_flag to be true. In the main() while loop, this variable is repeatedly
checked, if it is found to be true then a counter value is sent to the PC over the serial link.
The value is incremented each time a new value is sent.

trigger_flag is reset to false to prevent the program being stuck in a loop constantly sending data to the PC

In the example video puTTY is used to view the transmitted data. However any terminal software may be used.

*/



#include "mbed.h"

Serial pc(USBTX, NC);                   // Creates an instance of a Serial Connection with default parameters
                                        // NC is used as this example uses simplex link where the PC only receives data
InterruptIn button(D4);                 // Create an InterruptIn associated with the centre pin of the joystick

volatile bool trigger_flag = false;     // A volatile boolean flag to indicate when our ISR has triggered.

void buttonISR()                        // The ISR for the InterruptIn. This function has minimal code for efficiency
{
    trigger_flag=true;                  // A single flag is set to indicate that the button has been pressed.
}


int main()
{
    int counter = 0;                                    // We create a counter to see how many times our button is pressed
    button.rise(&buttonISR);                            // The ISR is attached to the rising edge of the centre pin
    pc.printf("Microcontroller program running...\r\n");// This statement prints a text message to the serial link

    while(1) {
        if (trigger_flag) {                             // Checks for if the trigger flag is set (i.e. has the ISR run?)
            counter++;                                  // If so, the counter is incremented
            pc.printf("Button pressed %u times\r\n", counter); //And a message is displayed to the PC via the serial link
            trigger_flag = false;                       // IMPORTANT! - The flag is reset to prevent the loop executing infinitely
        }
    }
}
