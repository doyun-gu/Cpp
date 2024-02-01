class CountDown {
private:
    int cdmin, cdsec, cdtotal, initialTotal;
    bool cdisRunning, cdfinished;
    const float cd_pleft, cd_pright;

public:
    Ticker LEDticker;
    Ticker Speakerticker;
    Ticker Countticker;
    enum CountDownState { SETTING, RUNNING, FINISHED } countdownState;
    //CountDown() : cdmin(0), cdsec(0), cdtotal(0), cdisRunning(false), cdfinished(false), initialTotal(0), cd_pleft(24.0), cd_pright(60.0){}
    //CountDown() : cdmin(0), cdsec(0), cdisRunning(false), cdfinished(false), cdtotal(0), initialTotal(0), cd_pleft(24.0), cd_pright(60.0) {}
    CountDown() : cdmin(0), cdsec(0), cdtotal(0), initialTotal(0), cdisRunning(false), cdfinished(false), cd_pleft(24.0), cd_pright(60.0) {}
    void setClock(Potentiometer &leftHand, Potentiometer &rightHand) {
        cdmin = static_cast<int>(cd_pleft * leftHand.amplitudeNorm());
        cdsec = static_cast<int>(cd_pright * rightHand.amplitudeNorm());
        cdtotal = cdmin * 60 + cdsec;
        initialTotal = cdtotal;
    }

    int getcdmin(){
        return cdmin;
    }

    int getcdsec(){
        return cdsec;
    }

    int getcdtotal(){
        return cdtotal;
    }

    int getinitialTotal() {
        return initialTotal;
    }

    void timeoutISR() {
        if (cdisRunning) {
            cdtotal--;
            if (cdtotal <= 0) {
                finishCountDown();
            }
        }
    }

    void start() {
        if (countdownState == SETTING && cdtotal > 0) {
            countdownState = RUNNING;
            cdisRunning = true;
            Countticker.attach(callback(this, &CountDown::timeoutISR), 1.0);
            LEDticker.attach(callback(&greenLED, &LED::toggle), 1.0);
        }
    }

    void stop() {
        if (countdownState == RUNNING) {
            countdownState = SETTING;
            cdisRunning = false;
            Countticker.detach();
            LEDticker.detach();
            greenLED.off();
            mySpeaker.off();
        }
    }

    void finishCountDown() {
        lcd.cls();
        countdownState = FINISHED;
        cdisRunning = false;
        Countticker.detach();
        LEDticker.detach();
        greenLED.on();
        float frequency = 1000.0;
        float toggletime = 0.5*1.0/frequency;
        Speakerticker.attach(callback(&mySpeaker, &Speaker::toggle), toggletime);
    }

    void reset() {
        lcd.cls();
        countdownState = SETTING;
        cdisRunning = false;
        cdtotal = initialTotal;
        greenLED.off();
        LEDticker.detach();
        Speakerticker.detach();
    }

    CountDownState getState() const {
        return countdownState;
    }

    bool isCountDownRunning() const {
        return cdisRunning;
    }
};
