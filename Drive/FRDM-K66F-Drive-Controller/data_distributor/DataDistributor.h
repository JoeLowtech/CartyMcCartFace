#ifndef DATA_DISTRIBUTOR_H
#define DATA_DISTRIBUTOR_H
#include "mbed.h"
#include "CommunicationInterface.h"

struct DataDistributor{
    Queue<driveMessage, 1> driveQueue;
};

#endif