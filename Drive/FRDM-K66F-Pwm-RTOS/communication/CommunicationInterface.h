/*
    Class for Communication between the MCU and another device
 */
#ifndef COMMUNICATION_INTERFACE_H
#define COMMUNICATION_INTERFACE_H

#include "mbed.h"
#include "logger.h"

 class CommunicationInterface{
    private:
        NetworkInterface *net;
        nsapi_size_or_error_t status;
        SocketAddress local, remote;
        TCPSocket socket;

    public:
        CommunicationInterface(const char* remoteAddress,
                               const uint16_t remotePort);
        
        void send();
        void recv();
 };
 #endif