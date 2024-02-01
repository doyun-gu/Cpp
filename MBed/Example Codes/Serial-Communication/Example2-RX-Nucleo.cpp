/*
EEEN20011 - Lecture 18 Example Program 2 - Receiving Nucleo

This program uses the Nucleo-64 board and the Application Shield.
The program is used in conjunction with the corresponding 'transmit' program, and
requires a wired serial connection to a second Nucleo board.

The C12832 library is required - please see the instructions provided
for advice on how to include this in your project

The program uses the RawSerial API to receive characters (single byte integers).
A receive interrupt is attached to an ISR; this ISR executes automatically when data is received.
The ISR also transmits a confirmatory '1' to the transmitting Nucleo, so that it knows the data
has been received. Finally, the received character is printed on the LCD screen.

*/

#include "mbed.h"
#include "C12832.h"                                     //Includes the library for the LCD screen

RawSerial myRawSerial(PA_11,PA_12);                     //Creates RawSerial object using USART6
C12832 lcd(D11, D13, D12, D7, D10);                     //Creates an LCD Object from the LCD library
volatile int latest_byte;                               //Volatile variable to store the received data

void dataReceivedISR()                                  //ISR to run when data is received
{
    latest_byte = myRawSerial.getc();                   //Copy received byte to latest_byte
    myRawSerial.putc('1');                              //Transmit a confirmatory '1' to the Tx Nucleo
}

int main()
{

    myRawSerial.attach(&dataReceivedISR,Serial::RxIrq); // Attaches the dataReceivedISR upon receive data
    latest_byte = 0;                                    // Initialise latest_byte to 0

    while(1) {
        lcd.locate(0,0);                                // Continuously print the most recent value of..
        lcd.printf("Most recent data: %u",latest_byte); // ... latest_value to the LCD screen
        wait(0.1);                                      // Wait period to prevent flickering on the screen
    }
}
