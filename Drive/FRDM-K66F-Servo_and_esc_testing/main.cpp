#include "mbed.h"

PwmOut motor(D6);
Serial pc(USBTX,USBRX,115200);

void servo(){
    // max 1700
    // center 1500
    // min 1200
    int pulsewidth = 0;
    pc.printf("pulsewidth:\n");
    pc.scanf("%d",&pulsewidth);
    
    pc.printf("%d\n",pulsewidth);
    motor.pulsewidth_us(pulsewidth);
}

void esc(){
    // max 0.9
    // center 0.4 
    // min 0.3
    float dutycycle = 0.0;
    pc.printf("dutycycle:\n");
    pc.scanf("%f",&dutycycle);
    
    pc.printf("%f\n",dutycycle);
    motor.write(dutycycle);
}

int main()
{
    int frequency;
    
    pc.printf("Frequenz:\n");
    pc.scanf("%d",&frequency);
    motor.period_ms(1000/frequency);
    while (true) {

        esc();
        //servo();
        ThisThread::sleep_for(1000);
    }
}
