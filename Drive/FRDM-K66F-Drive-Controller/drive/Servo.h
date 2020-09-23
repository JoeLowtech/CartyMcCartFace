#ifndef SERVO_H
#define SERVO_H

#include "mbed.h"
#include "arm_math.h"

class Servo{
    static constexpr uint32_t SERVO_SIGNAL_FREQUENCY = 50;
    static constexpr uint32_t SERVO_MIN_RANGE = 1200;
    static constexpr uint32_t SERVO_MAX_RANGE = 1700;
    static constexpr uint32_t SERVO_CENTER = 1450;

    private:
        PwmOut pwm;

    public:
        Servo(PinName pin):pwm(pin){
            pwm.period_ms(1000/SERVO_SIGNAL_FREQUENCY);
            pwm.pulsewidth_us(SERVO_CENTER);
        }

        void set(uint32_t pulsewidth){
            pwm.pulsewidth_us(min(max(pulsewidth,SERVO_MIN_RANGE),SERVO_MAX_RANGE));
        }

};

#endif