// Class Potentiometer
class Potentiometer {
private:
    AnalogIn inputSignal;
    float VDD;

public:
    Potentiometer(PinName pin, float v) : inputSignal(pin), VDD(v) {}

    float amplitudeVolts(void) {
        return (inputSignal.read() * VDD);
    }
    
    float amplitudeNorm(void) {
        return inputSignal.read();
    }
};

class SamplingPotentiometer: public Potentiometer {
    private:
        float samplingFrequency, samplingPeriod;
        Ticker sampler;

    public:
        SamplingPotentiometer(PinName p, float v, float fs);
};
