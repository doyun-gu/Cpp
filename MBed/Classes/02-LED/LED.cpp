class LED {
private:
    DigitalOut OutputSignal;
    bool status;

public:
    LED(PinName pin) : OutputSignal(pin) {
        off();
    }

    void on() {
        OutputSignal = 0;
        status = true;
    }

    void off() {
        OutputSignal = 1;
        status = false;
    }
};
