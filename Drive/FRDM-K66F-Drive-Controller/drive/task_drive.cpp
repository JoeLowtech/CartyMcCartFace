#include "tasks.h"
#include "logger.h"
#include "Motor.h"
#include "Servo.h"

void tasks::drive(DataDistributor *dataQueues){
    driveMessage* driveCommands;
    Motor motor(D6);
    Servo servo(D5);

    while(true){
        
        if (dataQueues->driveQueue.try_get_for(Kernel::wait_for_u32_forever,&driveCommands)){
            DEBUG("Steering: %d",driveCommands->steering);
            servo.set(driveCommands->steering);
            DEBUG("Power:%f",driveCommands->power);
            motor.set(driveCommands->steering);
        }
        else{
            DEBUG("No drive data aquired.")
        }
    }
}