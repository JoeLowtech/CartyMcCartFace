#ifndef TASK_H
#define TASK_H

#include "mbed.h"
#include "CommunicationInterface.h"
#include "DataDistributor.h"

namespace tasks{

//will probably not used
struct ARGS{
    CommunicationInterface* server;
    DataDistributor* dataQueues;
};

void tcpRead(ARGS* taskArgs);
void drive(ARGS*taskArgs);
}
#endif