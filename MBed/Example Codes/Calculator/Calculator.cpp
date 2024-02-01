#include "mbed.h"
#include "C12832.h"                             //Imports the library for the LCD screen

C12832 lcd(D11, D13, D12, D7, D10);             //Creates an LCD object from the LCD library

class RGBLED                                           //Begin RGBLED class definition
{

protected:                                          //Protected (Private) data member declaration
    DigitalOut redSignal;                           //Declaration of DigitalOut object
    DigitalOut greenSignal;                           //Declaration of DigitalOut object
    DigitalOut blueSignal;  

public:                                             //Public declarations
    RGBLED(PinName redPin, PinName greenPin, PinName bluePin) : redSignal(redPin), greenSignal(greenPin), blueSignal(bluePin){off();}    //Constructor - user provided pin name is assigned to the DigitalOut

    void red(void)                                   //Public member function for turning the LED on
    {
        redSignal = 0;
        greenSignal = 1;
        blueSignal = 1;                             //Set output to 0 (LED is active low)
        
    }
    
    
    void green(void)                                   //Public member function for turning the LED on
    {
        redSignal = 1;
        greenSignal = 0;
        blueSignal = 1;                             //Set output to 0 (LED is active low)
        
    }
    
    
    void blue(void)                                   //Public member function for turning the LED on
    {
        redSignal = 1;
        greenSignal = 1;
        blueSignal = 0;                             //Set output to 0 (LED is active low)
        
    }
    
    void amber(void)
    {
        redSignal = 0;
        greenSignal = 0;
        blueSignal = 1;
    }
        

    void off(void)                                  //Public member function for turning the LED off
    {
        redSignal = 1;
        greenSignal = 1;
        blueSignal = 1;                           
        
    }


};


RGBLED ledout(D5, D9, D8);                  //Declare LED objects for each of the R, G, B LEDs
InterruptIn up(A2);                         //Create interruptIn object for up button
InterruptIn down(A3);                       //Create interruptIn object for down button
InterruptIn centre(D4);                     //Create interruptIn object for centre button
Ticker cursorflash;
int cursorstate = 0;

float numeric1 = 1;
float numeric2 = 1;
int activenumber = 1;

int oper = 0;

float calculation()
{

    float result;

    if (oper==0){result = numeric1+numeric2;}
    else if (oper==1){result = numeric1-numeric2;}
    else if (oper==2){result = numeric1*numeric2;}
    else if (oper==3){result = numeric1/numeric2;}
    else if (oper==4){result = pow(numeric1,numeric2);}
    
    return result;

}

char getOp()
{

    char op = ' ';

    if (oper==0){op = '+';}
    else if(oper==1){op = '-';}
    else if(oper==2){op = 'x';}
    else if(oper==3){op = '/';}
    else if(oper==4){op = '^';}

    return op;

}


void updateScreen()                         //Function to update LCD screen data
{

    float result = calculation();
    char op = getOp();

    lcd.locate(0,0);                        //Locate to (0,0)
    lcd.printf("\n  %.0f   %c   %.0f = %.2f         ",numeric1,op,numeric2,result);


}

void upISR()
{
    if (activenumber == 1){
    
        if (numeric1<9){numeric1 = numeric1 + 1;}}

    else if (activenumber==2) {

        if (numeric2<9){numeric2 = numeric2 + 1;}}

    else if (activenumber==3) {

        if (oper==4) {oper = 0;}
        else {oper = oper+1;}

    }
    updateScreen();
    
}


void downISR()
{
    if (activenumber == 1){
    
        if (numeric1>0){numeric1 = numeric1 - 1;}}

    else if (activenumber ==2) {

        if (numeric2>0){numeric2 = numeric2 - 1;}}

    else if (activenumber==3) {

        if (oper==0) {oper = 4;}
        else {oper = oper-1;}
    }

    updateScreen();
    
}


void swapISR()
{
    
    if (activenumber == 3) {activenumber = 1;}
    else {activenumber = activenumber +1;}
    
    if(activenumber==1){
        ledout.red();
        lcd.fillrect(0,0,127,31,0);
        updateScreen();
        lcd.line(7,20,18,20,1);}
    else if(activenumber==2) {
        lcd.fillrect(0,0,127,31,0);
        updateScreen();
        lcd.line(47,20,59,20,1);
        ledout.amber();}
    else if(activenumber==3) {
        ledout.blue();
        lcd.fillrect(0,0,127,31,0);
        updateScreen();
        lcd.line(28,20,37,20,1);}
     
}


void flashingCursorISR()
{
    if(cursorstate==0){
        if(activenumber==1){
            lcd.line(7,20,18,20,1);}
        else if(activenumber==2) {
            lcd.line(47,20,59,20,1);}
        else if(activenumber==3) {
            lcd.line(28,20,37,20,1);}
        cursorstate=1;
    }

    else

    {
        if(activenumber==1){
            lcd.line(7,20,18,20,0);}
        else if(activenumber==2) {
            lcd.line(47,20,59,20,0);}
        else if(activenumber==3) {
            lcd.line(28,20,37,20,0);}
        cursorstate=0;
    }

}


int main()
{

    updateScreen();                     // Display this on the LCD screen
    cursorflash.attach(&flashingCursorISR,1.0);

    up.rise(&upISR);             // Attach ISR for 'up' button - should increase the frequency
    down.rise(&downISR);           // Attach ISR for 'up' button - should decrease the frequency
    centre.rise(&swapISR);         // Attach the ISR for the 'centre button - should toggle the output tone on/off

    ledout.red();
    
    while(1) {                          // Inifnite while loop - needed to keep the program running
                                        // Should be empty - part of the task requirement - as program should be entirely interrupt-driven
    }
}
