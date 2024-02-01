/*
EEEN20011 - Lecture 18 Example Program - Transmit Nucleo

This program uses the Nucleo-64 board and the Application Shield.
The program is used in conjunction with the corresponding 'receive' program, and
requires a wired serial connection to a second Nucleo board.

The C12832 library is required - please see the instructions provided
for advice on how to include this in your project

The program uses the RawSerial API to transmit characters (single byte integers).
The program also uses a Ticker API to generate interrupts every 1 second.

When the Ticker's ISR executes, a single byte is transmitted on the RawSerial interface,
and this value is incremented so that the next value is transmitted at the next interrupt.

A receive data interrupt is attached to the RawSerial object, which triggers when data is
received. This data is checked to see if the received byte is equal to '1'. If this is the
case then it is assumed that this is a confirmation byte from the second Nucleo. When this
confirmation is received, a counter is incremented, which keeps track of the number of
transmitted bytes which have been acknowledged.

Both the last transmitted character and the number of received data confirmations are shown
on the LCD screen.

*/

#include "mbed.h"
#include "C12832.h"                         //Includes the library for the LCD screen

RawSerial myRawSerial(PA_11,PA_12);         //Creates RawSerial object using USART6
C12832 lcd(D11, D13, D12, D7, D10);         //Creates an LCD Object from the LCD library
Ticker txTimer;                             //Creates a Ticker object

volatile int bytes_confirmed;               //Volatile variable to store received serial data
volatile int tx_counter = 0;                //Volatile variable to recall transmit data

void dataReceivedISR()                      //ISR To execute when serial data is received
{
    int latest_byte = myRawSerial.getc();   //Copy received data to latest_byte

    if (latest_byte == '1') {               //Check if received data is the char '1'
        bytes_confirmed++;                  //If so, this means data was received OK...
    }                                       //..increment bytes_confirmed as a result
}

void txNewByte()                            //ISR to execute upon Ticker interrupt
{
    myRawSerial.putc(tx_counter);           //Transmit the current value of tx_counter
    tx_counter++;                           //Increment value so we transmit a new value next time
}

int main()
{

    myRawSerial.attach(&dataReceivedISR,Serial::RxIrq); // Attaches the dataReceivedISR upon receive data
    txTimer.attach(&txNewByte,1.0);                     // Attaches the txNewByte ISR to send data every 1 s

    while(1) {

        lcd.locate(0,0);                                        //Repeatedly print the latest values that have...
        lcd.printf("#Bytes sent:      %u\n",tx_counter);        //...been sent to the other device, and how many...
        lcd.printf("#Bytes confirmed: %u\n",bytes_confirmed);   //...have been successfully received
        wait(0.1);
    }
}
