/*
MCE - Lecture 9 Example Program

This program uses the Nucleo-64 board and the Application Shield.
The program repeatedly measures the voltage on pin A0 and displays it on the LCD screen

The C12832 library is required - please see the instructions provided
for advice on how to include this in your project

*/

#include "mbed.h"                               //Imports mbed libraries
#include "C12832.h"                             //Imports the library for the LCD screen

C12832 lcd(D11, D13, D12, D7, D10);             //Creates an LCD object from the LCD library 
AnalogIn analog_source(A0);                     //Creates an AnalogIn object attached to pin A0

int main()
{
    float adc_in;                               //Declares a variable to store the raw ADC result
    float adc_voltage;                          //Declares a variable to store the ADC voltage calculation
    
    while(1) {

        adc_in = analog_source.read();          // Read the analog input value 
                                                // Value is from 0.0 to 1.0 for full ADC dynamic range)
        adc_voltage = adc_in * 3300;            // Converts value in the 0V - 3300 mV range
        
                                                // Print values to LCD screen
        lcd.locate(0,0);
        lcd.printf("ADC    = %f \nVoltage = %.0f mV   ", adc_in, adc_voltage);

        wait(0.1);                              // Wait for 0.1 seconds, smooths LCD update
    }
}
