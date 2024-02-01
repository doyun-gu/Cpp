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


int main() {
    // Speaker Object: my_Speaker
    Speaker my_Speaker (D6);

    // Set Frequency
    float freq = 1100.0;

    // Find Time
    // Divided by 2 to get the half period
    float time = 0.5*1.0/freq;

    while (1) {
        // Toggle the speaker state
        my_Speaker.toggle();

        
        wait(time);
    };
}
