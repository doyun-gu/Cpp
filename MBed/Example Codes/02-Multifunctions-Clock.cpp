#include "mbed.h"
#include "C12832.h"                             //Imports the library for the LCD screen

class LED                                           //Begin LED class definition
{

protected:                                          //Protected (Private) data member declaration
    DigitalOut outputSignal;                        //Declaration of DigitalOut object
    bool status;                                    //Variable to recall the state of the LED

public:                                             //Public declarations
    LED(PinName pin) : outputSignal(pin)
    {
        off();   //Constructor - user provided pin name is assigned to the DigitalOut
    }

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



class Potentiometer                                                     //Begin updated potentiometer class definition
{

private:                                                                //Private data member declaration
    AnalogIn inputSignal;                                               //Declaration of AnalogIn object
    float VDD, currentSampleNorm, currentSampleVolts;                   //Float variable to speficy the value of VDD (3.3 V for the Nucleo-64)

public:                                                                 // Public declarations
    Potentiometer(PinName pin, float v) : inputSignal(pin), VDD(v) {}   //Constructor - user provided pin name assigned to AnalogIn...
                                                                        //VDD is also provided to determine maximum measurable voltage
    float amplitudeVolts(void)                                          //Public member function to measure the amplitude in volts
    {
        return (inputSignal.read()*VDD);                                //Scales the 0.0-1.0 value by VDD to read the input in volts
    }

    float amplitudeNorm(void)                                           //Public member function to measure the normalised amplitude
    {
        return inputSignal.read();                                      //Returns the ADC value normalised to range 0.0 - 1.0
    }

    void sample(void)                                                   //Public member function to read a sample and store the value as data members
    {
        currentSampleNorm = inputSignal.read();                         //Read a sample from the ADC and store normalised representation [0..1]
        currentSampleVolts = currentSampleNorm*VDD;                     //Convert this to a voltage and store that as a data member too.
    }

    const float getCurrentSampleNorm(void)                              //Public member function to return the most recent normalised sample [0..1]
    {
        return currentSampleNorm;                                       //Return the most recent normalised sample
    }

    const float getCurrentSampleVolts(void)                             //Public member function to return the most recent sampled voltage [0.. 3.3 V]
    {
        return currentSampleVolts;                                      //Return the most recent sampled voltage
    }

};



class SamplingPotentiometer : public Potentiometer                      //Class for Sampling potentiometer, inherits from Potentiomteter (Required for task)
{

private:                                                                //Private data members
    float samplingFrequency, samplingPeriod;                            //Data members for the frequency and period of the sampling
    Ticker sampler;                                                     //Ticker object used to sample the potentiometer

public:                                                                 //Public declarations
    SamplingPotentiometer(PinName p, float v, float fs) : Potentiometer(p,v) //Constructor. Accepts pin of potentiometer, and VDD, as needed by the Potentiometer class. The sampling frequency is also accepted
    {
        samplingFrequency = fs;                                         //Upon object creation, store sample frequency
        samplingPeriod = 1.0f/samplingFrequency;                        //Convert to a period
        sampler.attach(callback(this, &SamplingPotentiometer::sample),samplingPeriod);  //Attach the interrupt for regular sampling of the potentiometer at the specified frequency
    }

};



class Buzzer                                        //Begin class definition
{

protected:                                          //Protected (Private) data member declaration
    DigitalOut outputSignal;                        //Declaration of DigitalOut object
    bool status;                                    //Optional: Variable to recall the state of the output

public:                                             //Public declarations
    Buzzer(PinName pin) : outputSignal(pin)
    {
        off();   //Constructor - user provided pin name is assigned to the DigitalOut
    }

    void on(void)                                   //Public member function for turning the Buzzer on
    {
        outputSignal = 1;                           //Set output to 1
        status = true;                              //Optional: Set the status variable to show the output is high
    }

    void off(void)                                  //Public member function for turning the output off
    {
        outputSignal = 0;                           //Set output to 0
        status = false;                             //Optional: Set the status variable to show the output is low
    }

    void toggle(void)                               //Public member function for toggling the Buzzer
    {
        if (status)                                 //Check if the output is currently on
            off();                                  //Turn off if so
        else                                        //Otherwise...
            on();                                   //Turn the output on
    }

    bool getStatus(void)                            //Optional: Public member function for returning the status of the output
    {
        return status;                              //Optional: Returns whether the output is currently high or low
    }
};



class Clock
{
    private:

        int time_hour, time_min, time_secs, base_t;
        int world_hour, world_min;

    public:
        Clock(){
            base_t = 0;
            time_hour = 0;
            time_min = 0;
            time_secs = 0;
        }

        void reset(){
            base_t = 0;
        }

        void tick(){
            base_t = base_t+1;

            calculateTime();
        }

        void calculateTime(){
            time_hour = base_t/3600;
            if (time_hour>23){
                time_hour = 0;
                base_t=0;
            }
            time_min = base_t/60;
            if (time_min>59){
                time_min = time_min-(time_hour*60);
            }
            time_secs = base_t%60;
        }

        void setClock(int new_time){
                base_t = new_time;
                calculateTime();
        }


        void updateTimeZone(float offset){
            time_hour = base_t/3600;
                if (time_hour>23){
                    time_hour = 0;
                    base_t=0;
                }
                time_min = base_t/60;
                if (time_min>59){
                    time_min = time_min-(time_hour*60);
                }
                
                world_hour = static_cast<int>(time_hour+offset);
                world_min = static_cast<int>(((offset-world_hour+time_hour)*60)+time_min);

                if (world_min >59){
                    world_min = world_min-60;
                    world_hour = world_hour+1;
                }

                world_hour = (world_hour+24)%24;
        }

        int getHours(){
            return time_hour;
        }

        int getMins(){
            return time_min;
        }

        int getSecs(){
            return time_secs;
        }

        int getWorldHours(){
            return world_hour;
        }

        int getWorldMins(){
            return world_min;
        }

};



//Global Variables - These should be minimal - and all should be justified by the students. E.g. *needs* to be accessible in an ISR
//This is the minimum number of global variables needed to solve this task. Having only the state machine as global will provide full marks in this area.

typedef enum {initialisation, enterSetTime, setTime, enterCurrentTime, currentTime, changeCurrentTime, enterChangeCurrentTime, updateCurrentTime, enterWorldTime, worldTime, enterStopwatch, stopwatch, updateStopwatch, enterCountdownTimer, setCountdownPeriod, startTimer, countdownTimer, timerEnd1, timerEnd2, stopTimer, idle} ProgramState;    //Definition of the enum that refers to the states of the program
ProgramState state;                             //Initialisation of the state machine, which is stored as an enum

//ISRs - These should all be programmatically as efficient as possible. No loops, delays, LCD functions, or other unnecessary code.
//For full marks only the state should be modified in each ISR. 

void centrePressed(){


 switch (state) {                            

        case(setTime):
            state = enterChangeCurrentTime;
            break;

        case(changeCurrentTime):
            state=updateCurrentTime;
            break;

        case (stopwatch):
            state = updateStopwatch;
            break;

        case (setCountdownPeriod):
            state = startTimer;
            break;

        case (timerEnd2):
            state = enterCountdownTimer;
            break;

        case (countdownTimer):
            state = stopTimer;
            break;

        default:
            state = state;
        //    No action needed
 }

}


void downPressed(){

 switch (state) {                            

        case (setTime) :
            state = enterCurrentTime;
            break;

        case (currentTime) :
            state = enterWorldTime;
            break;

        case (worldTime) :
            state = enterStopwatch;
            break;

        case (stopwatch) :
            state = enterCountdownTimer;
            break;

        case (countdownTimer):
            state = enterSetTime;
            break;

        default:
            state = initialisation;
 }

}


void upPressed() {
    switch (state) {  

        case (setTime) :
            state = enterCountdownTimer;
            break;

        case (currentTime) :
            state = enterSetTime;
            break;

        case (worldTime) :
            state = enterCurrentTime;
            break;

        case (stopwatch) :
            state = enterWorldTime;
            break;

        case (setCountdownPeriod):
            state = enterStopwatch;
            break;

        default:
            state = initialisation; 
    }

}


void countdownISR(){

    state = timerEnd1;

}



int main(){
    //Peripherals
    C12832 lcd(D11, D13, D12, D7, D10);             //Creates an LCD object from the LCD library
    InterruptIn centre(D4);                         //Declare interruptIn object for centre pin
    InterruptIn down(A3);                           //Declare interruptIn object for down pin
    InterruptIn up(A2);                             //Declare interruptIn object for up pin
    SamplingPotentiometer left(A0, 3.3, 50);      //Create SamplingPotentiometer object for input of minutes (3.3V 50Hz sampling)
    SamplingPotentiometer right(A1, 3.3, 50);      //Create SamplingPotentiometer object for input of seconds (3.3V 50Hz sampling)
    LED blueLED(D8);
    LED greenLED(D9);
    Buzzer speaker(D6);

    //Time state
    Clock clk;
    int set_hours = 0;
    int set_mins = 0;
    Ticker metronome;

    //World time
    float offset = 0;

    //Stopwatch variables
    Timer stopwatchTimer;
    bool stopwatch_running = false;
    float stopwatch_value = 0;
    
    //Countdown timer variables
    Timer countdown_time_counter;
    Ticker active_speaker;
    Timeout countdown_timer;
    Ticker led_flash;
    bool countdown_timer_running = false;
    float countdown_mins = 0;
    float countdown_secs = 0;
    int current_countdown_value = 0;


    state = initialisation;                         //Set initial state of state machine: initialisiation

    metronome.attach(callback(&clk, &Clock::tick), 1.0);


    while(1) {                                      //Main while() loop

        switch (state) {                            //Main switch statement for state machine

            case (initialisation) :                 //Initialisation state
               
                centre.rise(&centrePressed);
                up.rise(&upPressed);
                down.rise(&downPressed);
                greenLED.off();
                lcd.cls();

                state = enterSetTime;
                break;                              //Exit switch statement

            case (enterSetTime) :

                lcd.cls();
                lcd.locate(0,0);
                lcd.printf("Press Fire to set time:");

                state = setTime;
                break;
           

            case(setTime):

                lcd.locate(0,10);
                lcd.printf("%02d:%02d:%02d   ", clk.getHours(), clk.getMins(), clk.getSecs());
                wait(0.1);

                break;

            case(enterChangeCurrentTime):
                
                lcd.cls();
                lcd.locate(0,0);
                lcd.printf("Set new time (HH:MM)");
                
                state=changeCurrentTime;
                break;

            case(changeCurrentTime):
                
                lcd.locate(0,10);
                set_hours = static_cast<int>((left.getCurrentSampleNorm()*23)+0.5);
                set_mins = static_cast<int>((right.getCurrentSampleNorm()*59)+0.5);
                lcd.printf("%02d:%02d   ", set_hours, set_mins);
                wait(0.1);
                
                break;

            case(updateCurrentTime):

                clk.setClock((set_hours*3600)+(set_mins*60));
                
                state=enterSetTime;
                break;

            case(enterCurrentTime):

                lcd.cls();
                lcd.locate(0,0);
                lcd.printf("Current Time:");
                
                state = currentTime;
                break;

            case(currentTime):

                lcd.locate(0,10);
                lcd.printf("%02d:%02d:%02d   ", clk.getHours(), clk.getMins(), clk.getSecs());
                wait(0.1);
                
                break;

            case(enterWorldTime):

                lcd.cls();
                lcd.locate(0,0);
                lcd.printf("World Time State");
                
                state = worldTime;
                break;

            case(worldTime):
                int timezone = static_cast<int>(left.getCurrentSampleNorm()*22);
                
                switch (timezone) {

                    case (0):
                        lcd.locate(0,0);
                        lcd.printf("Honolulu (GMT-11)    ");
                        offset = -11;
                        break;
                    case (1):
                        lcd.locate(0,0);
                        lcd.printf("Juneau (GMT-9)       ");
                        offset = -9;
                        break;
                    case (2):
                        lcd.locate(0,0);
                        lcd.printf("Vancouver (GMT-8)     ");
                        offset = -8;
                        break;
                    case (3):
                        lcd.locate(0,0);
                        lcd.printf("Denver (GMT-7)        ");
                        offset = -7;
                        break;
                    case (4):
                        lcd.locate(0,0);
                        lcd.printf("Mexico City (GMT-6)   ");
                        offset = -6;
                        break;
                    case (5):
                        lcd.locate(0,0);
                        lcd.printf("Toronto (GMT-5)       ");
                        offset = -5;
                        break;
                    case (6):
                        lcd.locate(0,0);
                        lcd.printf("Santiago (GMT-4)      ");
                        offset = -4;
                        break;
                    case (7):
                        lcd.locate(0,0);
                        lcd.printf("Rio de Janeiro (GMT-3) ");
                        offset = -3;
                        break;
                    case (8):
                        lcd.locate(0,0);
                        lcd.printf("Ponta Delgada (GMT-1)  ");
                        offset = -1;
                        break;
                    case (9):
                        lcd.locate(0,0);
                        lcd.printf("Manchester (GMT)       ");
                        offset = 0;
                        break;
                    case (10):
                        lcd.locate(0,0);
                        lcd.printf("Lagos (GMT+1)          ");
                        offset = 1;
                        break;
                    case (11):
                        lcd.locate(0,0);
                        lcd.printf("Kyiv (GMT+2)            ");
                        offset = 2;
                        break;
                    case (12):
                        lcd.locate(0,0);
                        lcd.printf("Riyadh (GMT+3)          ");
                        offset = 3;
                        break;
                    case (13):
                        lcd.locate(0,0);
                        lcd.printf("Tehran (GMT+3.5)        ");
                        offset = 3.5;
                        break;
                    case (14):
                        lcd.locate(0,0);
                        lcd.printf("Yerevan (GMT+4)          ");
                        offset = 4;
                        break;
                    case (15):
                        lcd.locate(0,0);
                        lcd.printf("Islamabad (GMT+5)        ");
                        offset = 5;
                        break;
                    case (16):
                        lcd.locate(0,0);
                        lcd.printf("New Delhi (GMT+5.5)      ");
                        offset = 5.5;
                        break;
                    case (17):
                        lcd.locate(0,0);
                        lcd.printf("Beijing (GMT+8)          ");
                        offset = 8;
                        break;
                    case (18):
                        lcd.locate(0,0);
                        lcd.printf("Tokyo (GMT+9)             ");
                        offset = 9;
                        break;
                    case (19):
                        lcd.locate(0,0);
                        lcd.printf("Darwin (GMT+9.5)          ");
                        offset = 9.5;
                        break;
                    case (20):
                        lcd.locate(0,0);
                        lcd.printf("Sydney (GMT+10)            ");
                        offset = 10;
                        break;
                    case (21):
                        lcd.locate(0,0);
                        lcd.printf("Auckland (GMT+12)          ");
                        offset = 12;
                        break;
                }

                lcd.locate(0,10);
                clk.updateTimeZone(offset);
                lcd.printf("%02d:%02d:%02d   ", clk.getWorldHours(), clk.getWorldMins(), clk.getSecs());
                lcd.locate(0,20);
                lcd.printf("%02d:%02d:%02d  (Manchester)   ", clk.getHours(), clk.getMins(), clk.getSecs());
                wait (0.1);

                break;

            case(enterStopwatch):

                lcd.cls();
                lcd.locate(0,0);
                if (stopwatch_running){
                    lcd.printf("Stopwatch: Running");
                }
                else {
                    lcd.printf("Stopwatch: Inactive");
                    lcd.locate(0,10);
                    lcd.printf("Last Time: %.2f s", stopwatch_value);
                }
                
                state = stopwatch;
                break;

            case(updateStopwatch):

                if(stopwatch_running){
                    stopwatch_value = stopwatchTimer.read();
                    stopwatchTimer.stop();
                    blueLED.off();
                    stopwatch_running = false;
                }
                else {
                    stopwatchTimer.reset();
                    stopwatchTimer.start();
                    blueLED.on();
                    stopwatch_running = true;
                }

                state = enterStopwatch;
                break;

            case(stopwatch):

                if (stopwatch_running){
                    lcd.locate(0,10);
                    lcd.printf("Time: %.2f s   ", stopwatchTimer.read());
                    wait(0.1);
                }

                break;

            case(enterCountdownTimer):

                lcd.cls();
                lcd.locate(0,0);
                if (countdown_timer_running){
                    lcd.printf("Countdown Timer: Running");
                    state = countdownTimer;
                }
                else {
                    lcd.printf("Set Countdown Period:");
                    greenLED.off();
                    active_speaker.detach();
                    countdown_time_counter.reset();
                    state = setCountdownPeriod;
                }
                
                break;

            case(setCountdownPeriod):

                lcd.locate(0,10);
                countdown_mins = static_cast<int>(left.getCurrentSampleNorm()*9);
                countdown_secs = static_cast<int>(right.getCurrentSampleNorm()*59);
                lcd.printf("%02.0f:%02.0f   ", countdown_mins, countdown_secs);

            break;

            case(startTimer):

                countdown_secs = countdown_secs + 60*countdown_mins;
                countdown_timer_running = true;
                countdown_timer.attach(&countdownISR,countdown_secs);
                led_flash.attach(callback(&greenLED, &LED::toggle), 1.0);
                countdown_time_counter.start();
                state = enterCountdownTimer;
            break;

            case(countdownTimer):
                lcd.locate(0,10);
                current_countdown_value = static_cast<int>(countdown_secs - countdown_time_counter.read())+1;
                lcd.printf("%02u  /  %02.0f s    ",current_countdown_value, countdown_secs);
                wait(0.1);
                
                break;

            case(timerEnd1):

                lcd.cls();
                lcd.locate(0,0);
                lcd.printf("Time Period Elapsed");
                countdown_timer_running = false;
                state=timerEnd2;
                led_flash.detach();
                greenLED.on();
                active_speaker.attach(callback(&speaker, &Buzzer::toggle), 1.0/(2000));
                
                break;

            case(timerEnd2):
                //Do nothing - wait for user input.
                break;

            case(stopTimer):

                countdown_timer.detach();
                countdown_time_counter.stop();
                countdown_time_counter.reset();
                led_flash.detach();
                greenLED.off();
                countdown_timer_running = false;
                
                state = enterCountdownTimer;
                break;

            default:
                state = initialisation;
        }


    }
}
