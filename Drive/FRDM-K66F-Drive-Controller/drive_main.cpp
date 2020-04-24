#if !MBED_TEST_MODE

#include "mbed.h"
#define LOG_LEVEL_DEBUG
#include "logger.h"
#include "CommunicationInterface.h"

Thread pwmThread(osPriorityNormal,OS_STACK_SIZE,nullptr,"pwm");
Thread statusThread(osPriorityNormal,OS_STACK_SIZE,nullptr,"status");

PwmOut motor(D6);
DigitalOut ledStatus(LED1);

void pwmSig(PwmOut *output){
    
    output->period_ms(20);
    output->pulsewidth_ms(10);
    uint16_t pulsewidth = 10;
    uint32_t nextWake = 0;

    while(true){
        nextWake = get_ms_count()+100;
        if(pulsewidth == 10 ){
            pulsewidth += 10;
        }
        else {
            pulsewidth -= 10;
        }
        output->period_ms(pulsewidth);
        ThisThread::sleep_until(nextWake);
    }
}

void blink(DigitalOut *led){
    uint32_t nextWake = 0;
    
    while(true){
        nextWake = get_ms_count()+1000;
        *led = !*led;
        INFO("Switch!");
        ThisThread::sleep_until(nextWake);    
    }
}


int main()
{
    pwmThread.start(callback(pwmSig, &motor));
    statusThread.start(callback(blink, &ledStatus));
    while (true) {
        ThisThread::sleep_for(1000);
    }
}


#endif
