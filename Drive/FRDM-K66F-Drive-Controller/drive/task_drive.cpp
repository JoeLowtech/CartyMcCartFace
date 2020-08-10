#include "tasks.h"
#include "logger.h"
#include "Motor.h"
#include "Servo.h"

void tasks::drive(DataDistributor *dataQueues){
    driveMessage* driveCommands;
    osEvent receiveMessage;
    Motor motor(D6);
    Servo servo(D7);

    while(true){
        receiveMessage = dataQueues->driveQueue.get();
        if (receiveMessage.status == osEventMessage){
            driveCommands = (driveMessage*)receiveMessage.value.p;
        DEBUG("Steering: %d",driveCommands->steering);
        servo.set(driveCommands->steering);
        DEBUG("Power:%f",driveCommands->power);
        motor.set(driveCommands->power);
        }
    }
}