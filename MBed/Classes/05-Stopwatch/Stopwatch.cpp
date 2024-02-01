class StopWatch {
private:
    int swsecond, swfrsecond;
    bool swisRunning;
    int displayUpdateCounter;

    void timeoutISR() {
        if (swisRunning) {
            swfrsecond++;
            if (swfrsecond >= 100) {
                swsecond++;
                swfrsecond = 0;
            }
        }
    }

public:
    Ticker SWticker;
    StopWatch() : swsecond(0), swfrsecond(0), swisRunning(false), displayUpdateCounter(0) {}

    void start() {
        if (!swisRunning) {
            swisRunning = true;
            swsecond = 0;
            swfrsecond = 0;
            //displayUpdateCounter = 0;
            SWticker.attach(callback(this, &StopWatch::timeoutISR), 0.01);
            blueLED.on();
        }
    }

    void stop() {
        if (swisRunning) {
            swisRunning = false;
            SWticker.detach();
            blueLED.off();
        }
    }

    bool isStopWatchRunning() const {
        return swisRunning;
    }

    int getswseconds(){
        return swsecond;
    }

    int getswfrseconds(){
        return swfrsecond;
    }
};
