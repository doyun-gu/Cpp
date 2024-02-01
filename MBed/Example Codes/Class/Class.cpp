/*
EEEN20011 - Example Program â€“ LED Wrapper Class

This program uses the Nucleo-64 board and the Application Shield.
The program demonstrates the construction of a wrapper class to create the functionality of an LED from the DigitalOut API provided with Mbed.

The DigitalOut library allows us to set a GPIO pin either high or low. The effect that this has depends on the connection of external circuitry. The LED class allows us to define meanings of 'on' or 'off' which relate to the LED itself. The notion of toggling the output is also now included. 


*/

#include "mbed.h"                                   //Include the Mbed libraries

class LED                                           //Begin LED class definition
{

protected:                                          //Protected (Private) data member declaration
    DigitalOut outputSignal;                        //Declaration of DigitalOut object
    bool status;                                    //Variable to recall the state of the LED

public:                                             //Public declarations
    LED(PinName pin) : outputSignal(pin){off();}    //Constructor - user provided pin name is assigned to the DigitalOut

    void on(void)                                   //Public member function for turning the LED on
    {
        outputSignal = 0;                           //Set output to 0 (LED is active low)
        status = true;                              //Set the status variable to show the LED is on
    }

    void off(void)                                  //Public member function for turning the LED off
    {
        outputSignal = 1;                           //Set output to 1 (LED is active low)
        status = false;                             //Set the status variable to show the LED is off
    }

    void toggle(void)                               //Public member function for toggling the LED
    {
        if (status)                                 //Check if the LED is currently on
            off();                                  //Turn off if so
        else                                        //Otherwise...
            on();                                   //Turn the LED on
    }

    bool getStatus(void)                            //Public member function for returning the status of the LED
    {
        return status;                              //Returns whether the LED is currently on or off
    }
};



int main()                                          //Begin main function
{

    LED redLED(D5);                                 //Create an object from the LED class. Associated with pin D5

    while(1) {                                      //Begin infinite loop - IMPORTANT

        redLED.toggle();                            //Toggle the LED
        wait(0.5);                                  //Wait for 0.5 seconds

    }                                               //Loop infinitely
}
