#if !MBED_TEST_MODE

#include "mbed.h"
#include "logger.h"
#include "CommunicationInterface.h"

Thread tcpThread(osPriorityHigh,OS_STACK_SIZE,nullptr,"TCP");
Thread statusThread(osPriorityNormal,OS_STACK_SIZE,nullptr,"status");

DigitalOut ledStatus(LED1);
CommunicationInterface server;

void tcpRead(CommunicationInterface* server){
    driveMessage* receivedMessage;
    nsapi_size_or_error_t serverStatus;
    do{
        serverStatus = server->start();
    }
    while(serverStatus != NSAPI_ERROR_OK);

    while(serverStatus == NSAPI_ERROR_OK){
        nsapi_size_or_error_t receiveStatus;
        
        if((receiveStatus = server->recv())){
            receivedMessage = server->decode();
            INFO("Steering: %d",receivedMessage->steering);
            INFO("Power:%f",receivedMessage->power);
        }else{
            ERROR("Something is wrong:%d",receiveStatus);
            if(receiveStatus == 0){
                serverStatus = NSAPI_ERROR_CONNECTION_LOST;
            }
        } 
    }
}

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
    tcpThread.start(callback(tcpRead, &server));
    statusThread.start(callback(blink, &ledStatus));
    while (true) {
        ThisThread::sleep_for(1000);
    }
}


#endif
