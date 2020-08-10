#if !MBED_TEST_MODE

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
    uint32_t nextWake = 0;
    
    while(true){
        nextWake = get_ms_count()+1000;
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
        ThisThread::sleep_for(1000);
    }
}


#endif
