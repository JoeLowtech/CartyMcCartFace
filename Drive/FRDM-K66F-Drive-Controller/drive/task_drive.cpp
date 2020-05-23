#include "tasks.h"
#include "logger.h"

void tasks::drive(ARGS *taskArgs){
    driveMessage* driveCommands;
    osEvent receiveMessage;

    while(true){
        receiveMessage = taskArgs->dataQueues->driveQueue.get();
        if (receiveMessage.status == osEventMessage){
            driveCommands = (driveMessage*)receiveMessage.value.p;
        INFO("Steering: %d",driveCommands->steering);
        INFO("Power:%f",driveCommands->power);
        }
    }
}