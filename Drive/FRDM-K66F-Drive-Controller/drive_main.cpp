#if !MBED_TEST_MODE
// Activate HS-Mode in mbed_overrides.c to get 180 MHz SystemCoreClock speed

#include "mbed.h"
#include "logger.h"
#include "CommunicationInterface.h"
#include "tasks.h"
#include "DataDistributor.h"

Thread tcpThread(osPriorityHigh,OS_STACK_SIZE,nullptr,"TCP");
Thread driveThread(osPriorityNormal,OS_STACK_SIZE,nullptr, "DRIVE");
Thread statusThread(osPriorityBelowNormal,OS_STACK_SIZE,nullptr,"STATUS");

DigitalOut ledStatus(LED1);
DataDistributor dataQueues;

void blink(DigitalOut *led){
    
    while(true){
        Kernel::Clock::time_point nextWake = Kernel::Clock::now()+1s;
        *led = !*led;
        ThisThread::sleep_until(nextWake);    
    }
}


int main()
{
    statusThread.start(callback(blink, &ledStatus));
    driveThread.start(callback(tasks::drive,&dataQueues));
    tcpThread.start(callback(tasks::tcpRead,&dataQueues));

    while (true) {
        ThisThread::sleep_for(1s);
    }
}


#endif
