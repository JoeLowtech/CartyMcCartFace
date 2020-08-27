#include "tasks.h"
#include "logger.h"

void tasks::tcpRead(DataDistributor* dataQueues){
    driveMessage* receivedMessage;
    nsapi_size_or_error_t serverStatus;
    CommunicationInterface server;

    do{
        serverStatus = server.start();
    }
    while(serverStatus != NSAPI_ERROR_OK);

    while(serverStatus == NSAPI_ERROR_OK){
        nsapi_size_or_error_t receiveStatus;
        
        if((receiveStatus = server.recv())){
            receivedMessage = server.decode();
            dataQueues->driveQueue.try_put(receivedMessage);
        }else{
            ERROR("Something is wrong:%d",receiveStatus);
            if(receiveStatus == 0){
                serverStatus = NSAPI_ERROR_CONNECTION_LOST;
                //STOP THE CAR
                driveMessage stopMessage;
                stopMessage.steering = 1500;
                stopMessage.power = 0.4;
                dataQueues->driveQueue.try_put(&stopMessage);
            }
        } 
    }
}