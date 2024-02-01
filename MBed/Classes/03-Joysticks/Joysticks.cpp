class Joystick {
    private:
        // Data Members (Variables)
        DigitalIn up, down, left, right, fire;

    public:
        // Constructor: Initialise the JoySticks
        Joystick(PinName u, PinName d, PinName l, PinName r, PinName f):up(u), down(d), left(l), right(r), fire(f){}

        // Member Functions begin
        bool upPressed (void){
            return up;
        }
        bool downPressed (void){
            return down;
        }
        bool leftPressed(void){
            return left;
        }
        bool rightPressed(void){
            return right;
        }
        bool firePressed(void){
            return fire;
        }
};
