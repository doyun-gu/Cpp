/*
EEEN20011 - Example Program â€“ Function Overloading

This program uses the Nucleo-64 board and the Application Shield.
The program demonstrates function overloading with the use of two functions named â€˜sumâ€™, each of which takes a different number of parameters.

The C12832 library is required - please see the instructions provided for advice on how to include this in your project.

The program then loops infinitely to keep the program running; without this infinite loop, our program will stop executing.

*/

#include "mbed.h"                                   //Includes Mbed library
#include "C12832.h"                                 //Includes the library for the LCD screen

C12832 lcd(D11, D13, D12, D7, D10);                 //Creates an LCD Object from the LCD library

int sum(int a, int b)                               //First version of â€˜sumâ€™ function
{
    return a + b;
}

int sum(int a, int b, int c)                        //Overloaded version of â€˜sumâ€™ function
{
    return a + b + c;
}


int main()
{

    lcd.cls();                                      //Clear the screen
    lcd.locate(0,0);                                //Locate at (20,0)

    lcd.printf(" 1 + 2  = %u \n",sum(1,2));         //Uses first version of the â€˜sumâ€™ function
    lcd.printf(" 1 + 2 + 3  = %u \n",sum(1,2,3));   //Uses second version of the â€˜sumâ€™ function

    while(1) {
    }
}
