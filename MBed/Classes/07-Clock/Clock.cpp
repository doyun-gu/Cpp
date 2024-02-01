class Clock {
    private:
        int time_hour, time_min, time_secs;
        const float clock_pleft, clock_pright, worldclock_pleft;

        struct CountryInfo {
            const char* name;
            int hourDiff;
            int minDiff;
        };
        CountryInfo countries[20];
        int lastCountryIndex;
        int currentCountryIndex;
        bool setting;

    public:
        Clock(): time_hour(0), time_min(0), time_secs(0), clock_pleft(24.0), clock_pright(60.0), setting(false) {

        // FireButton Interruption
        // void reset(){};
        void tick() {
                time_secs = time_secs + 1;

                // Seconds
                if (time_secs >= 60) {
                    time_min = time_min + 1;
                    time_secs = 0;

                    // Minutes
                    if (time_min >= 60) {
                        time_hour = time_hour + 1;
                        time_min = 0;

                        // Hours
                        if (time_hour >= 24) {
                            time_hour = 0;
                        }
                    }

                }
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
          
        return false;
    }
};
