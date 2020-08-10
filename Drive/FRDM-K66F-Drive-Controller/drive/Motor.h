#ifndef MOTOR_H
#define MOTOR_H

#include "mbed.h"

class Motor{
    static constexpr uint32_t MOTOR_SIGNAL_FREQUENCY = 500;
    static constexpr float MOTOR_MIN_RANGE = 0.3;
    static constexpr float MOTOR_MAX_RANGE = 0.9;

    private:
        PwmOut pwm;
    public:
        Motor(PinName pin): pwm(pin){
            pwm.period_ms(1000/MOTOR_SIGNAL_FREQUENCY);
        }
        void set(float dutycylce){
            pwm.write(min(max(dutycylce,MOTOR_MIN_RANGE),MOTOR_MAX_RANGE));
        }
};

#endif