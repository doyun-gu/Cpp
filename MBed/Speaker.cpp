#include "mbed.h"

// Speaker Class
class Speaker{
    private:
        // Data Members (Variables)
        DigitalOut OutputSignal;
        char state;  // Can be set to either 1 or 0 to record output value

    public:
        // Constructor: Initialise the Speaker
        Speaker(PinName pin):OutputSignal(pin){
            off();
        }

        // Member Function begins

        void on (void){
            OutputSignal = 1;
            state = 1;
        }

        void off (void){
            OutputSignal = 0;
            state = 0;
        }

        void toggle (void) {
            if (state) {
                off();
            }

            else {
                on();
            }
        }
};
