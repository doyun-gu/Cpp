/*
MCE - Example Program“ Dimming an LED with a potentiometer

This program uses the Nucleo-64 board and the Application Shield.
The program uses the previously introduced LED class. It adds an implementation of a wrapper class to determine the functionality of a potentiometer, based on the AnalogIn API provided through Mbed.

The potentiometer is regularly sampled in the main function, with the value being used as part of a function to determine the total 'on-time' for the LED. The LED is turned off for a fixed period of time. Consequently, the program allows for a varying of the duty cycle of a periodic digital signal. The ratio of the 'on-time' to the 'off-time' consequently determines the brightness of the LED.

*/

#include "mbed.h"

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


class Potentiometer                                 //Begin potentiometer class definition
{

private:                                            //Private data member declaration
    AnalogIn inputSignal;                           //Declaration of AnalogIn object
    float VDD;                                      //Float variable to speficy the value of VDD (3.3 V for the Nucleo-64)

public:                                             // Public declarations
    Potentiometer(PinName pin, float v) : inputSignal(pin), VDD(v) {}   //Constructor - user provided pin name assigned to AnalogIn...
                                                                        //VDD is also provided to determine maximum measurable voltage
    float amplitudeVolts(void)                      //Public member function to measure the amplitude in volts
    {
        return (inputSignal.read()*VDD);            //Scales the 0.0-1.0 value by VDD to read the input in volts
    }
    
    float amplitudeNorm(void)                       //Public member function to measure the normalised amplitude
    {
        return inputSignal.read();                  //Returns the ADC value normalised to range 0.0 - 1.0
    }
};



int main(int)                                       //Begin main function
{
    const float DC_period = 10.0;                   //Float variable to hold the scalar coefficient for the LED on-time


    float on_time = 0;                              //Initialisation of variable to determine to total LED on-time
    Potentiometer leftHand(A0, 3.3);                //Create an object from the potentiometer class. Uses left potentiometer and 3.3V
    LED redLED(D5);                                 //Create an object from the LED class. Associated with pin D5

    while(1) {                                      //Begin infinite loop - IMPORTANT

        on_time = DC_period*leftHand.amplitudeNorm();   //Calculate LED on-time by multiplying the DC_period by the Normalised ADC amplitude
        redLED.on();                                //Turn the LED on
        wait_ms(on_time);                           //Wait for a variable time period, based on the variable on_time
        redLED.off();                               //Turn the LED off
        wait_ms(10);                                //Wait for a fixed periof of 10 ms

    }                                               //Loop infinitely
}
