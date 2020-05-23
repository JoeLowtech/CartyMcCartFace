#include "tasks.h"
#include "logger.h"

void tasks::tcpRead(ARGS* taskArgs){
    driveMessage* receivedMessage;
    nsapi_size_or_error_t serverStatus;
    do{
        serverStatus = taskArgs->server->start();
    }
    while(serverStatus != NSAPI_ERROR_OK);

    while(serverStatus == NSAPI_ERROR_OK){
        nsapi_size_or_error_t receiveStatus;
        
        if((receiveStatus = taskArgs->server->recv())){
            receivedMessage = taskArgs->server->decode();
            taskArgs->dataQueues->driveQueue.put(receivedMessage);
        }else{
            ERROR("Something is wrong:%d",receiveStatus);
            if(receiveStatus == 0){
                serverStatus = NSAPI_ERROR_CONNECTION_LOST;
            }
        } 
    }
}