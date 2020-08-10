#ifndef TASK_H
#define TASK_H

#include "mbed.h"
#include "CommunicationInterface.h"
#include "DataDistributor.h"

namespace tasks{

void tcpRead(DataDistributor* dataQueues);
void drive(DataDistributor* dataQueues);
}
#endif